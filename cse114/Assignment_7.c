#include<stdio.h>

char text[400];
char* pT = text;

void fill(char line[])
{
	int i, j, end;
	for (end = 19; pT[end] != ' ' && pT[end] != '\0'; end--);
	if (pT[end] == '\0') for (end = 0; pT[end] != '\0'; end++);
	for (i = 0; i < 19 - end; i++) line[i] = ' ';
	for (j = 0; j < end; j++ , i++) line[i] = pT[j];
	line[i] = '\0';
	pT += end + 1;
}

void print(char lines[][20])
{
	int i;
	for (i = 0; i < 20; i++)
		if (lines[i][18] != ' ') 
			printf("%s\n", lines[i]);
}

int main(void)
{
	int i;
	char lines[20][20];
	printf("Enter text:");
	scanf("%[^\n]s", text);
	for (i = 0; i < 20; i++) fill(lines[i]);
	print(lines);
	return 0;
}