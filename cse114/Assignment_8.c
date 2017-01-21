#include <stdio.h>

void fill(char* table, int i, int j, char c)
{
	if (i < 8 && j < 8 && i >= 0 && j >= 0) *(table + i * 8 + j) = c;
}

void check(char* table, int Qi, int Qj, int Ri, int Rj)
{
	int i;
	for (i = 0; i < 8; i++)
	{
		if (Qi - i >= 0 && Qj - i >= 0 || Qi + i < 8 && Qj + i < 8)
			if ((Qi - i == Ri && Qj + i == Rj) || (Qi + i == Ri && Qj - i == Rj) || (Qi - i == Ri && Qj - i == Rj) || (Qi + i == Ri && Qj + i == Rj) || (Qi == Ri) || (Qj == Rj))
			{
				printf("Queen Can Capture The Rook\n");
				return;
			}
	}

	fill(table, Qi, Rj, 'q');
	fill(table, Ri, Qj, 'q');

	for (i = 0; i < 8; i++)
	{
		if ((Ri - i >= 0 && Rj - i >= 0) || (Ri + i < 8 && Rj + i < 8))
		{
			if (Ri - i == Qi) fill(table, Qi, Rj - i, 'q');
			if (Ri + i == Qi) fill(table, Qi, Rj - i, 'q');
			if (Ri - i == Qi) fill(table, Qi, Rj + i, 'q');
			if (Ri + i == Qi) fill(table, Qi, Rj + i, 'q');
			if (Rj - i == Qj) fill(table, Ri - i, Qj, 'q');
			if (Rj + i == Qj) fill(table, Ri - i, Qj, 'q');
			if (Rj - i == Qj) fill(table, Ri + i, Qj, 'q');
			if (Rj + i == Qj) fill(table, Ri + i, Qj, 'q');
		}
		if ((Qi - i >= 0 && Qj - i >= 0) || (Qi + i < 8 && Qj + i < 8))
		{
			if (Qi - i == Ri) fill(table, Ri, Qj - i, 'q');
			if (Qi + i == Ri) fill(table, Ri, Qj - i, 'q');
			if (Qi - i == Ri) fill(table, Ri, Qj + i, 'q');
			if (Qi + i == Ri) fill(table, Ri, Qj + i, 'q');
			if (Qj - i == Rj) fill(table, Qi - i, Rj, 'q');
			if (Qj + i == Rj) fill(table, Qi - i, Rj, 'q');
			if (Qj - i == Rj) fill(table, Qi + i, Rj, 'q');
			if (Qj + i == Rj) fill(table, Qi + i, Rj, 'q');
		}
	}
}

void print(char* table)
{
	int i, j;
	printf("\t    0\t    1\t    2\t    3\t    4\t    5\t    6\t    7\n");
	for (i = 0; i < 8; i++)
	{
		printf("\t-----------------------------------------------------------------\n");
		printf("    %d\t", i);
		for (j = 0; j < 8; j++)
		{
			if (*(table + 8 * i + j) != '\0')printf("|%c(%d,%d)\t", *(table + 8 * i + j), i, j);
			else printf("|\t");
		}
		printf("|\n");
	}
	printf("\t-----------------------------------------------------------------\n");
}


int main(void)
{
	char table[8][8] = {""};
	int Qi = 1, Qj = 1, Ri = 4, Rj = 4;
	printf("Q(i,j) i: ");
	scanf("%d", &Qi);
	printf("Q(i,j) j: ");
	scanf("%d", &Qj);
	printf("R(i,j) i: ");
	scanf("%d", &Ri);
	printf("R(i,j) j: ");
	scanf("%d", &Rj);
	fill(table, Qi, Qj, 'Q');
	fill(table, Ri, Rj, 'R');
	check(table, Qi, Qj, Ri, Rj);
	print(table);

	return 0;
}
