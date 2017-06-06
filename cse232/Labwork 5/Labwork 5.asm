	.org $100
	ldaa #5
	staa $20
	ldaa #3
	staa $21
	ldaa #8
	staa $22
	ldaa #18
	staa $23	
	ldaa #2
	staa $24
	ldx #$0
loop ldaa $20,x
	adda #1
	staa $30,x
	jsr DELAY
	inx
	cpx #5
	bne loop
	bra final

DELAY STX $40
	LDX #100
DEL2 DEX
	CPX #0
	BGT DEL2
	LDX $40
	RTS

final .end
