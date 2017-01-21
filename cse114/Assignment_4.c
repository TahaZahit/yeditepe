#include <stdio.h>
#include <stdlib.h>

int abs(int n)//absolute function
{
	return n < 0 ? -n : n;
}

int main()
{
	int i, n, dice, sum = 0, s = 50, status = 1;

	time_t t;
	srand((unsigned)time(&t));


	printf("Please enter a number in the interval [5,10], inclusive: ");
	scanf("%d", &n);

	if (n < 5 || n > 10)
	{
		printf("Your number should be in the interval[5, 10], inclusive.");
		return 0;
	}


	printf("Your beginning point: %d\n", s);
	while (s > 0 && status)
	{

		sum = 0;

		//first dice
		dice = rand() % 6 + 1;
		sum += dice;
		printf("Your frist dice:%d\n", dice);

		//second dice
		dice = rand() % 6 + 1;
		sum += dice;
		printf("Your second dice:%d\n", dice);

		//If the sum of the dice (sum) equals n, the computer will respond the user, displaying the message “You won.” 
		//and s will be increased by 10.
		if (sum == n)
		{
			printf("You Won!\n");
			s += 10;
		}

		//If sum is lower than 5 or greater than 10, 
		//it means that the user lost the current run. 
		else if (sum < 5 || sum > 10)
		{
			printf("You Lost!\n");
			s -= 10;
			
		}
		//Otherwise, 
		else
		{
			//Another test will be performed to see if |sum-n|=2. 
			if (abs(sum - n) == 2)
			{
				//If this condition is true, then the user will be allowed to throw the dice again.
				continue;
			}
			//Otherwise, if |sum-n|>2, 
			else if (abs(sum - n) > 2)
			{
				//the computer will ask the user to enter a new number n
				printf("Please enter a new number: ");
				scanf("%d", &n);

				// The above procedure will be repeated for n' too
				continue;
			}
		}

		printf("Your Score: %d\n", s);
		printf("Quit(0) or Go(1): ");
		scanf("%d", &status);
	}
	printf("Game Over");
	return (0);
}
