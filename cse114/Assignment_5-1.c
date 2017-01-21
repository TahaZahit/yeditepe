#include <stdio.h>

#define SIZE sizeof(short int)*8 //SIZE = short int teki bit say�s�

void print_binary(short int value)
{
	short unsigned int mask = 1, space = 1;

	mask <<= SIZE - 1;
	while (mask > 0)
	{
		printf("%c", value & mask ? '1' : '0');//value&mask 0 dan b�y�k ise ekrana 1, 0 ise ekrana 0 basar
		if (space % 4 == 0) 
			printf(" ");//4 bitte 1 bo�luk girer
		mask >>= 1;
		space++;
	}
	printf("\n");
}

int main(void)
{
	short int number, mirror = 0, mask = 1;

	printf("Enter number : ");
	scanf("%hd", &number);

	printf("Number binary : ");
	print_binary(number);

	int i;
	for (i = 0; i < SIZE / 2; i++)
	{
		mirror <<= 1;
		mirror += number & mask ? 1 : 0;
		mask <<= 1;
	}

	mirror <<= SIZE / 2;
	mirror = number | mirror;

	printf("Mirrored binary: ");
	print_binary(mirror);
	printf("New number : %hd", mirror);
	//short int kullanmam�z gerekti�i i�in yeni say� negatif ��kabilir
	//short unsigned int kullan�rsak bu sorun d�zelecektir
	return 0;
}
