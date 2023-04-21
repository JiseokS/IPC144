/*
* Name: Jiseok Shim
* Student Number: 122758170
* Seneca Email Address: jshim13@myseneca.ca
* Section Information Code: IPC144 NCC
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_NUM 10
int main(void)
{
	const double MIN_INCOME = 500.00;
	const double MAX_INCOME = 400000.00;
	const double MIN_COST = 100.00;
	double income;
	int valid = 0, list, i;
	int Priority[MAX_NUM] = { 0 };
	char Financed[MAX_NUM] = { 0 };
	double Cost[MAX_NUM] = { 0 };

	printf("+--------------------------+\n");
	printf("+   Wish List Forecaster   |\n");
	printf("+--------------------------+\n\n");

	do {
		printf("Enter your monthly NET income: $");
		scanf("%lf", &income);

		if (income < MIN_INCOME) {
			valid = 0;
			printf("ERROR: You must have a consistent monthly income of at least $500.00\n\n");
		}
		else if (income > MAX_INCOME) {
			valid = 0;
			printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n\n");
		}
		else
			break;
	} while (!valid);

	printf("\n");

	do {
		printf("How many wish list items do you want to forecast?: ");
		scanf("%d", &list);

		if (list < 1 || list > 10) {
			valid = 0;
			printf("ERROR: List is restricted to between 1 and 10 items.\n\n");
		}
		else
			break;
	} while (!valid);

	printf("\n");

	for (i = 0; i < list; i++)
	{
		printf("Item-%d Details:\n", i + 1);

		do {
			valid = 1;
			printf("   Item cost: $");
			scanf("%lf", &Cost[i]);

			if (Cost[i] < MIN_COST) {
				valid = 0;
				printf("      ERROR: Cost must be at least $100.00\n");
			}
			else
				break;

		} while (!valid);

		do {
			valid = 1;
			printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
			scanf("%d%*c", &Priority[i]);

			if (Priority[i] < 1 || Priority[i] > 3) {
				valid = 0;
				printf("      ERROR: Value must be between 1 and 3\n");
			}
			else
				break;

		} while (!valid);

		do {
			valid = 1;
			printf("   Does this item have financing options? [y/n]: ");
			scanf("%c%*c", &Financed[i]);

			if (Financed[i] == 'y' || Financed[i] == 'n') {
				break;
			}
			else {
				valid = 0;
				printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
			}
		} while (!valid);
		printf("\n");
	}
	printf("Item Priority Financed        Cost\n");
	printf("---- -------- -------- -----------\n");
	for (i = 0;i < list;i++) {
		printf("%3d  %5d    %5c    %11.2lf\n", i + 1, Priority[i], Financed[i], Cost[i]);
	}

	double sum = 0.0;

	for (i = 0; i < list; i++) {
		sum += Cost[i];
	}
	printf("---- -------- -------- -----------\n");
	printf("                      $%11.2lf\n\n", sum);

	int select, select1;
	select = 0, select1 = 0;
	do {
		printf("How do you want to forecast your wish list?\n");
		printf(" 1. All items (no filter)\n");
		printf(" 2. By priority\n");
		printf(" 0. Quit/Exit\n");
		printf("Selection: ");
		scanf("%d", &select);

		if(select>2 || select <0)
		{
			valid = 0;
			printf("\nERROR: Invalid menu selection.\n\n");
		}
		if(select == 1)
		{
			valid = 0;
			printf("\n====================================================\n");
			printf("Filter:   All items\n");
			printf("Amount:   $%1.2lf\n", sum);
			printf("Forecast: %d years, %d months\n", ((int)(sum * 100) / (int)(income * 100) / 12), ((int)(sum * 100) / (int)(income * 100) % 12)+1);
			printf("NOTE: Financing options are available on some items.\n");
			printf("      You can likely reduce the estimated months.\n");
			printf("====================================================\n\n");
		}
		if (select == 2)
		{
			valid = 0;
			printf("\nWhat priority do you want to filter by? [1-3]: ");
			scanf("%d", &select1);
			printf("\n====================================================\n");
			printf("Filter:   by priority (%d)\n", select1);
			i = 0;
			double Sum = 0.0;
			do {
				if (Priority[i] == select1)
				{
					Sum = Sum + Cost[i];
				}
				i++;
			} while (i < list);

	
			
			printf("Amount:   $%1.2lf\n", Sum);
			printf("Forecast: %d years, %d months\n", ((int)(Sum * 100) / (int)(income * 100) / 12), ((int)(Sum * 100) / (int)(income * 100) % 12) + 1);
			if (Financed[select1] == 'y')
			{
				printf("NOTE: Financing options are available on some items.\n");
				printf("      You can likely reduce the estimated months.\n");
				printf("====================================================\n\n");
			}
			if (Financed[select1] == 'n')
			{
				printf("====================================================\n\n");
			}
				
			
		}
		if (select == 0)
		{
			valid = !valid;
			printf("\n");

		}
	} while (!valid);

	printf("Best of luck in all your future endeavours!\n");




	return 0;
}