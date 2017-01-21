#include <stdio.h>

void print(char a[],int i,int j,int size)
{
	if (i < 0) return;
	char c = a[(i + j) % size];
	if (i!=size&&j==size-1&&c == ' ') return;
	if (j == 0) printf("Step %d: ", size-i);
	if(j<size)
	{
		printf("%c", c);
		print(a, i, ++j, size);
	}
	else
	{
		printf("\n");
		print(a, --i, 0, size);
	}
}


int main(void)
{
	char x[] = " Albert Einstein";
	int size;
	for (size = 0; x[size] != '\0'; size++);

	print(x,size,0,size);

	return 0;
}