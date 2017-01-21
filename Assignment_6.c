#include <stdio.h>

char blocks[5][5][3];
char temprow[5];
int seatsblock[3] = { 25,25,25 };

int temp;

void print_block();
int isRowEmpty(int row, int block);
void getRow(int row, int block);
int isOk(int block, int ticket);
void fill(int block, int ticket);


int main(void)
{
	int i, j, k;
	for (i = 0; i < 5; i++)
		for (j = 0; j < 5; j++)
			for (k = 0; k < 3; k++)
				blocks[i][j][k] = 'B';
	printf("Welcome to the CineCSE : \n");
	printf("-------------------\n");
	do
	{
		int block = 0, ticket = 0;


		print_block();

		do
		{
			if (block > 3) printf("Enter 1,2 or 3!\n");
			printf("Choose Your Block(Enter - 1 for Exit) : ");
			scanf("%d", &block);
		} while (block > 3 || block == 0);

		if (block == -1)
		{
			
			printf("-------------------\n");
			printf("Thank you for preferring CineCSE.  ");
			printf("-------------------\n");
			return 0;
		}

		do
		{
			if (ticket > 5) printf("You can't enter greater than 5!\n");
			printf("How Many Tickets Do You Want: ");
			scanf("%d", &ticket);
		} while (ticket > 5);


		fill(block - 1, ticket);

		print_block();
	} while (1);

}


void print_block()
{
	int block, row, cloumn;
	printf("  1  \t  2  \t  3  \n");
	for (row = 0; row < 5; row++)
	{
		for (block = 0; block < 3; block++)
		{
			for (cloumn = 0; cloumn < 5; cloumn++)
			{
				printf("%c", blocks[row][cloumn][block]);
			}
			printf("\t");
		}
		printf("\n");
	}
	printf("       Screen\n");
	printf("-------------------\n");

}

int isRowEmpty(int row, int block)
{
	int i;
	for (i = 0; i < 5; i++)
	{
		if (blocks[row][i][block] == 'X') return 0;
	}
	return 1;
}


void getRow(int row, int block)
{
	int i;
	for (i = 0; i < 5; ++i)
	{
		temprow[i] = blocks[row][i][block];
	}
}


int isOk(int block, int ticket)
{
	int column, row, count = 0,i,j;
	for (row = 0; row < 5; row++)
	{
		getRow(row, block);
		if (block == 0)
		{
			count = 0;
			for (column = 4; column >= 0; column--)
			{
				if (temprow[column] == 'B')
				{
					count++;
					if (count == ticket)
					{
						temp = row;
						return column;
					}
				}
				else count = 0;
			}
		}

		else if (block == 1)
		{
			if (ticket==1)
			{
				column = 2;
				for(i=0;i<5;i++)
				{
					column = i % 2 ? column + i : column - i;
					if (temprow[column]=='B')
					{
						temp = row;
						return column;
					}
				}
			}
			else if (ticket==2 || ticket ==3)
			{
				for (i=1;i<4;i++)
				{
					if (temprow[i] == 'B' && ticket==3)
					{
						count++;
						if (count == ticket)
						{
							temp = row;
							return -2;
						}
					}
					else count = 0;
				}

				count = 0;
				for (i = 0; i<2; i++)
				{
					column = 2;
					for (j=0;j<3;j++)
					{
						

						if (temprow[column] == 'B')
						{
							count++;
							if (count == ticket)
							{
								temp = row;
								return column;
							}
						}
						else count = 0;
						i == 0 ? column++ : column--;
					}
					
				}
			}
			
			else
			{
				count = 0;
				for (column = 4; column >= 0; column--)
				{
					if (temprow[column] == 'B')
					{
						count++;
						if (count == ticket)
						{
							temp = row;
							return column;
						}
					}
					else count = 0;
				}
			}
		}

		else if (block == 2)
		{
			count = 0;
			for (column = 0; column < 5; column++)
			{
				if (temprow[column] == 'B')
				{
					count++;
					if (count == ticket)
					{
						temp = row;
						return column;
					}
				}
				else count = 0;
			}
		}
	}

	return -1;
}

void fill(int block, int ticket)
{
	int t = ticket,i,j,k;
	int column = isOk(block, ticket);
	if(seatsblock[block]<=0)
	{
		printf("!!NO SEAT!!\n");	
		return;
	}
	if (column == -1)
	{
			for(i=0;i<5&&ticket;i++)
			{
				for(j=0;j<5&&ticket;j++)
				{
					if (blocks[i][j][block] == 'B')
					{
						blocks[i][j][block] = 'X';
						ticket--;
						seatsblock[block]--;
					}
				}
			}
	}
	if (block == 0)
	{

		while (column < 5)
		{
			
			blocks[temp][column][block] = 'X';
			column++;
			seatsblock[block]--;
		}
	}
	else if (block == 1)
	{
		while (ticket>0)
		{
			if(t==4||t==5)
			{
				while (column < 5)
				{
					blocks[temp][column][block] = 'X';
					column++;
					seatsblock[block]--;
				}
				return;
			}
			if (column==-2)
			{
				blocks[temp][1][block] = 'X';
				blocks[temp][2][block] = 'X';
				blocks[temp][3][block] = 'X';
				seatsblock[block] -= 3;
				return;
			}
			blocks[temp][column][block] = 'X';
			ticket--;
			column>=2?column--:column++;
			seatsblock[block]--;
		}
	}
	else if (block == 2)
	{
		while (column >= 0)
		{
			blocks[temp][column][block] = 'X';
			column--;
			seatsblock[block]--;
		}
	}
}
