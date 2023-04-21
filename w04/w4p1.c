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
	int valid, list, i;
	int Priority[MAX_NUM] = { 0 };
	char Financed[MAX_NUM] = { 0 };
	double Cost[MAX_NUM] = { 0 };
	i = 0;


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
		printf("Item-%d Details:\n", i+1);

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

	printf("Best of luck in all your future endeavours!\n");
	return 0;
}
