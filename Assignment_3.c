#include <stdio.h>

int control(int table[][3])//kazananı kontrol eder
{
	//satırlar
	if (table[0][0] != 0 && table[0][0] == table[0][1] && table[0][1] == table[0][2]) return table[0][0];
	if (table[1][0] != 0 && table[1][0] == table[1][1] && table[1][1] == table[1][2]) return table[1][0];
	if (table[2][0] != 0 && table[2][0] == table[2][1] && table[2][1] == table[2][2]) return table[2][0];
	//sutunlar
	if (table[0][0] != 0 && table[0][0] == table[1][0] && table[1][0] == table[2][0]) return table[0][0];
	if (table[0][1] != 0 && table[0][1] == table[1][1] && table[1][1] == table[2][1]) return table[0][1];
	if (table[0][2] != 0 && table[0][2] == table[1][2] && table[1][2] == table[2][2]) return table[0][2];
	//diagoneller
	if (table[0][0] != 0 && table[0][0] == table[1][1] && table[1][1] == table[2][2]) return table[1][1];
	if (table[0][2] != 0 && table[0][2] == table[1][1] && table[1][1] == table[2][0]) return table[1][1];

	return 0;
}

void viewTable(int table[][3])//tabloyu çizer
{
	int i, j;
	printf("\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf(" %c |", table[i][j] == 1 ? 'X' : table[i][j] == 2 ? 'O' : ' '); //table daki değer 1 se X, 2 ise O yazar 0 ise boşluk bırakır
		}

		if (i < 2) printf("\b \n--- --- ---\n");
		else printf("\b \n\n");
	}
}


int main()
{
	int table[3][3] = {0};
	int x, y, player, winner, turn = 0;

	printf("Welcome to the  Taha Zahit's XOX Game: \n");

	for (turn = 0; turn < 9; turn++)
	{
		player = turn % 2;

		printf("Player %d(%c) Enter Coordinate:", player + 1, player ? 'O' : 'X');
		scanf(" %d %d", &x, &y);

		if (table[x - 1][y - 1] == 0 && x > 0 && x < 4 && y > 0 && y < 4)
		{
			table[x - 1][y - 1] = turn % 2 ? 2 : 1;
			viewTable(table);
		}

		else
		{
			printf("Incorrect move\n");
			turn--;
			continue;
		}

		winner = control(table);
		if (winner == 1)
		{
			printf("Player 1 Won!\n");
			return 0;
		}
		else if (winner == 2)
		{
			printf("Player 2 Won\n");
			return 0;
		}
	}
	printf("The game ended in a draw.");
}
