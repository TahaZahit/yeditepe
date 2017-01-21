#include <stdio.h>

#define SIZE sizeof(short int)*8 //SIZE = short int teki bit sayýsý

void print_binary(short int value)
{
	short unsigned int mask = 1, space = 1;

	mask <<= SIZE - 1;
	while (mask > 0)
	{
		printf("%c", value & mask ? '1' : '0');//value&mask 0 dan büyük ise ekrana 1, 0 ise ekrana 0 basar
		if (space % 4 == 0) printf(" ");//4 bitte 1 boþluk girer
		mask >>= 1;
		space++;
	}
	printf("\n");
}

int main(void)
{
	short int number, mask = 1, parity = 1, count = 0;

	printf("Enter number : ");
	scanf("%hd", &number);

	printf("Number binary :");
	print_binary(number);

	mask <<= SIZE / 2 - 1; //0000 0000 1000 0000
	parity <<= SIZE / 2; //0000 0001 0000 0000

	while (mask > 0)
	{
		if (mask & number != 0)
		{
			count++;
		}
		mask >>= 1;
	}
	if (count % 2 == 1)
	{
		number = number | parity;
	}

	printf("Parity :");
	print_binary(number);
	return 0;
}
