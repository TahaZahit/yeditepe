#include <stdio.h>
#include <string.h>

struct time
{
	int d;
	int m;
	int y;
};

struct room
{
	int number;
	int type;
	int available[7];
	int price;
} r[20];

struct customer
{
	char name[30];
	struct time arrive;
	struct time departure;
	struct room room;
	int age;
	char other[5][30];
} c[20], nullc;

char s[10];
void create();
void settime();
void fee();
void load();
void save();
void rooms();
void printroom(struct room* room, int all);
void available();
void del();
void status();
void customers();


int main()
{
	int x;

	rooms();


	while (1)
	{
		printf("1. Create a new reservation\n2. Set departure time of a customer\n3. Display total fee for a customer\n4. Offer the available rooms.\n5. Delete reservation.\n6. Display the status of the rooms.\n7. Display the number of people staying at the hotel.\n0. Exit\n");
		scanf(" %d", &x);
		switch (x)
		{
		case 1:
			create();
			break;

		case 2:
			settime();
			break;

		case 3:
			fee();
			break;

		case 4:
			available();
			break;

		case 5:
			del();
			break;

		case 6:
			status();
			break;

		case 7:
			customers();
			break;

		case 0:
			save();
			return 0;
			break;
		default:
			printf("wrong selection\n");
			break;
		}
	}

	return 0;
}


void create()
{
	int x, days = 0, i;
	for (x = 0; x < 20; x++)
	{
		if (c[x].age == 0)
		{
			break;
		}
	}

	printf("name:");
	//gets();

	fgets(s, 10, stdin);
	fgets(c[x].name, 30, stdin);


	printf("age:");
	scanf(" %d", &c[x].age);

	printf("room type:");
	scanf(" %d", &c[x].room.type);
	fgets(s, 10, stdin);

	if (c[x].room.type != 1)
		for (i = 0; i < (c[x].room.type == 2 ? 1 : 4); i++)
		{
			printf("%d. other: ", i + 1);
			fgets(c[x].other[i], 30, stdin);
		}

	printf("arrive date(dd mm yyyy)");
	scanf(" %d %d %d", &c[x].arrive.d, &c[x].arrive.m, &c[x].arrive.y);

	printf("do you want to enter departure time?\n1.yes \n2.no\n");
	scanf(" %d", &i);
	if (i == 1)
		do
		{
			printf("departure time(dd mm yyyy)");
			scanf("%d %d %d", &c[x].departure.d, &c[x].departure.m, &c[x].departure.y);

			days = c[x].departure.d + 30 * c[x].departure.m + 365 * c[x].departure.y - c[x].arrive.d - 30 * c[x].arrive.m - 365 * c[x].arrive.y;

			if (days <= 0) printf("departure date cannot be early than arrive date");
			if (days > 7) printf("reservation cannot exceed 7 days");
		}
		while (i == 1 && (days <= 0 || days > 7));

	for (i = 0; i < days; i++)
	{
		c[x].room.available[i] = 0;
		r[x].available[i] = 0;
	}
}

void settime()
{
	char name[30];
	printf("\nenter name:");
	fgets(s, 10, stdin);
	fgets(name, 30, stdin);

	int x, days = 0, i;
	for (x = 0; x < 20; x++)
		if (!strcmp(name, c[x].name))break;


	do
	{
		printf("departure time(dd mm yyyy): ");
		scanf(" %d %d %d", &c[x].departure.d, &c[x].departure.m, &c[x].departure.y);

		days = c[x].departure.d + 30 * c[x].departure.m + 365 * c[x].departure.y - c[x].arrive.d - 30 * c[x].arrive.m - 365 * c[x].arrive.y;

		if (days <= 0) printf("departure date cannot be early than arrive date");
		if (days > 7) printf("reservation cannot exceed 7 days");
	}
	while (days <= 0 || days > 7);

	for (i = 0; i < days; i++)
	{
		c[x].room.available[i] = 0;
	}
}


void fee()
{
	char name[30];
	printf("\nenter name:");
	fgets(s, 10, stdin);
	fgets(name, 30, stdin);

	int x, days = 0, i;
	for (x = 0; x < 20; x++)
		if (!strcmp(name, c[x].name))break;
	if (x > 19)
	{
		printf("\ncustomer not found!\n");
		return;
	}
	days = c[x].departure.d + 30 * c[x].departure.m + 365 * c[x].departure.y - c[x].arrive.d - 30 * c[x].arrive.m - 365 * c[x].arrive.y;

	printf("\nfee: %d\n", r[x].price * days);
}


void load()
{
	FILE* f = fopen("data.txt", "r");
	int i, j;
	int temp;
	for (i = 0; i < 20; i++)
	{
		fscanf(f, "%d,%d,%d,%d", &r[i].number, &r[i].type, &temp, &r[i].price);//1,1,1111111,20(number,type,available,price)
		for (j = 0; j < 7; j++)
		{
			r[i].available[j] = temp % 10;
			temp /= 10;
		}
	}
}

void save()
{
	int i;
	FILE* f = fopen("data.txt", "w+");
	for (i = 0; i < 20; i++)
		fprintf(f, "%d,%d,%d%d%d%d%d%d%d,%d\n", r[i].number, r[i].type, r[i].available[0], r[i].available[1], r[i].available[2], r[i].available[3], r[i].available[4], r[i].available[5], r[i].available[6], r[i].price);
}

void rooms()
{
	int x, i;
	if (!fopen("data.txt", "r"))
	{
		for (x = 0; x < 20; x++)
		{
			r[x].number = x;

			if (x < 8)
			{
				r[x].type = 1;
				r[x].price = 20;
			}
			else if (x < 15)
			{
				r[x].type = 2;
				r[x].price = 50;
			}
			else if (x < 20)
			{
				r[x].type = 3;
				r[x].price = 100;
			}
			for (i = 0; i < 7; i++)
			{
				r[x].available[i] = 1;
			}
		}
	}
	else load();
}

void printroom(struct room* room, int all)
{
	int i;
	printf("number: %d\n", room->number);
	printf("type: %d\n", room->type);
	if (all == 1)
	{
		printf("available: ");
		for (i = 0; i < 7; i++) printf("%d", room->available[i]);
		printf("\n");
	}

	printf("price: %d\n", room->price);
	printf("\n");
}

void available()
{
	int i, j, flag;
	for (i = 0; i < 20; i++)
	{
		flag = 0;
		for (j = 0; j < 7 && !flag; j++)
		{
			if (r[i].available[j] == 0) flag = 1;
		}
		if (flag == 0) printroom(&r[i], 0);
	}
}

void del()
{
	char name[30];
	printf("\nenter name:");
	fgets(s, 10, stdin);
	fgets(name, 30, stdin);

	int x;
	for (x = 0; x < 20; x++)
		if (!strcmp(name, c[x].name))break;
	if (x < 20) c[x] = nullc;
}

void status()
{
	int c1 = 0, c2 = 0, cf = 0, i, t;
	for (i = 0; i < 20; i++)
	{
		for (t = 0; t < 7; t++)
		{
			if (r[i].available[t] == 0)
			{
				if (r[i].type == 1) c1++;
				else if (r[i].type == 2) c2++;
				else if (r[i].type == 3) cf++;
				else printf("status func worng");
				break;
			}
		}
	}
	printf("1 person room : %d / 8 are in use\n", c1);
	printf("2 person room : %d / 7 are in use\n", c2);
	printf("family room : %d / 5 are in use\n\n", cf);
}

void customers()
{
	int i, j, count = 0;
	for (i = 0; i < 20; i++)
	{
		if (c[i].age != 0)
		{
			count++;
			for (j = 0; j < 5; j++)
			{
				if (c[i].other[j][0] != '\0') count++;
			}
		}
	}
	printf("\nnumber of staying people: %d\n", count);
}
