`timescale 1ns / 1ps

module SimpleCPU(clk, rst, data_fromRAM, wrEn, addr_toRAM, data_toRAM);

parameter SIZE = 10;

parameter ADD 	= 0;
parameter NAND	= 1;
parameter SRL 	= 2;
parameter LT 	= 3;
parameter CP 	= 4;
parameter CPI 	= 5;
parameter BZJ 	= 6;
parameter MUL 	= 7;

parameter FETCH			= 0; // Fetch Instruction
parameter DECODE 		= 1; // Decode Instruction
parameter GET_DATA_1 	= 2; // Data 1
parameter GET_DATA_2 	= 3; // Data 2
parameter EXECUTE 		= 4; // Execute
parameter WRITE 		= 5; // Write Back Update PC

input clk, rst;
input wire [31:0] data_fromRAM;
output reg wrEn;
output reg [SIZE-1:0] addr_toRAM;
output reg [31:0] data_toRAM;

//////////////////////////////////////

reg [2:0] state, stateNext;
reg [SIZE-1:0] PC, PCNext;

reg [31:0] R1, R1Next;
reg [31:0] R2, R2Next;
reg [31:0] IW, IWNext;

reg CPIdata, CPIdataNext;

wire [2:0] opcode;
wire immediate;
wire [SIZE-1:0] addrA;
wire [SIZE-1:0] addrB;

assign opcode 		= IW[31:29];
assign immediate 	= IW[28];
assign addrA 		= IW[27:14];
assign addrB 		= IW[13:0];

always@(posedge clk) begin
	state 	<= #1 stateNext;
	PC 		<= #1 PCNext;
	R1 		<= #1 R1Next;
	R2 		<= #1 R2Next;
	IW 		<= #1 IWNext;
	CPIdata <= #1 CPIdataNext;
end

always@(*) begin
	stateNext	= state;
	PCNext 		= PC;
	R1Next 		= R1;
	R2Next 		= R2;
	IWNext 		= IW;
	wrEn 		= 0;
	addr_toRAM 	= 0;
	data_toRAM 	= 0;
	CPIdataNext = CPIdata;

	if(rst) begin
		wrEn 		= 0;
		PCNext 		= 0;
		R1Next 		= 0;
		R2Next 		= 0;
		IWNext 		= 0;
		stateNext 	= 0;
		addr_toRAM 	= 0;
		data_toRAM 	= 0;
		CPIdataNext = 0;
	end
	
	else begin
		case(state)
		
			FETCH : begin
				wrEn 		= 0;
				addr_toRAM	= PC;
				stateNext 	= DECODE;
			end

			DECODE : begin
				IWNext		= data_fromRAM;
				addr_toRAM 	= data_fromRAM[27:14];
				 
				if(data_fromRAM[28]) R2Next = data_fromRAM[13:0];
				stateNext = GET_DATA_1;
				case(data_fromRAM[31:29])
					CP : begin
						if(data_fromRAM[28]) stateNext = EXECUTE;
						else begin
							addr_toRAM = data_fromRAM[13:0];
							stateNext 	= GET_DATA_2;
						end
					end
					CPI : begin
						if(!data_fromRAM[28]) begin
							addr_toRAM 	= data_fromRAM[13:0];
							stateNext 	= GET_DATA_2;
						end
					end
				endcase
			end

			GET_DATA_1 : begin
				R1Next = data_fromRAM;
				if(immediate && ~(opcode == CPI)) stateNext = EXECUTE;
				else begin
					addr_toRAM = addrB;
					stateNext  = GET_DATA_2;
				end
				case(opcode)
						CPI : IWNext = {IW[31:28], 4'b0000, data_fromRAM[SIZE-1:0], IW[13:0]};
						BZJ : if(data_fromRAM[28]) stateNext = EXECUTE;    
				endcase
			end

			GET_DATA_2 : begin
				R2Next 		= data_fromRAM;
				stateNext 	= EXECUTE;
				 
				case(opcode)
					CPI : begin
						if(~immediate && ~CPIdata) begin
							 IWNext 			= {IW[31:14], 4'b0000, data_fromRAM[SIZE-1:0]};
							 addr_toRAM 	= data_fromRAM[SIZE-1:0];
							 stateNext 		= GET_DATA_2;
							 CPIdataNext 	= 1;
						end
					end
				endcase
			end
			EXECUTE : begin
				stateNext = WRITE;
				case(opcode)
					ADD 	: 	R1Next = R1 + R2;
					NAND 	: 	R1Next = ~(R1 & R2);
					SRL 	: 	R1Next = (R2<32)?(R1 >> R2):(R1 << (R2 - 32));   
					LT 		: 	R1Next = (R1 < R2)?1:0;  
					CP 		: 	R1Next = R2;
					CPI 	: 	begin
									CPIdataNext = 0;
									R1Next = R2;
								end
					BZJ 	: 	begin 
									PCNext = (immediate) ? (R1 + addrB) : (R2==0) ? R1 : (PC + 1);	
									stateNext = FETCH;
								end
					MUL 	: R1Next = R1 * R2;                    
				endcase
			end

			WRITE : begin
				PCNext 		= PC + 1;
				wrEn 		= 1;
				data_toRAM	= R1;
				addr_toRAM	= addrA;
				stateNext 	= FETCH;
			end
		endcase
	end
end

endmodule

module blram(clk, rst, i_we, i_addr, i_ram_data_in, o_ram_data_out);

parameter SIZE = 10, DECODEPTH = 1024;

input clk;
input rst;
input i_we;
input [SIZE-1:0] i_addr;
input [31:0] i_ram_data_in;
output reg [31:0] o_ram_data_out;

reg [31:0] memory[0:DECODEPTH-1];

always @(posedge clk) begin
	o_ram_data_out <= #1 memory[i_addr[SIZE-1:0]];
	if (i_we) memory[i_addr[SIZE-1:0]] <= #1 i_ram_data_in;
end 

initial begin
//////////////////////////
// write BRAM content here
memory[0] = 32'h20114045;
memory[1] = 32'h10114001;
memory[2] = 32'hb0118064;
memory[3] = 32'h190045;
memory[4] = 32'h8011c064;
memory[5] = 32'h7011c001;
memory[6] = 32'h10118001;
memory[7] = 32'hc0120047;
memory[8] = 32'h118045;
memory[9] = 32'ha0128046;
memory[10] = 32'h8012c046;
memory[11] = 32'h12c045;
memory[12] = 32'ha013004b;
memory[13] = 32'he013004a;
memory[14] = 32'h8012804c;
memory[15] = 32'h8013404b;
memory[16] = 32'h701343e9;
memory[17] = 32'hc012404d;
memory[18] = 32'h8019404c;
memory[19] = 32'hd0050013;
memory[20] = 32'h0;
memory[69] = 32'h1;
memory[70] = 32'h3e8;
memory[72] = 32'h2;
memory[73] = 32'hb;
memory[100] = 32'h6;
memory[101] = 32'h0;
memory[999] = 32'h1;


//////////////////////////
end

endmodule
