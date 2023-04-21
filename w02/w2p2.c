/*
	==================================================
	Workshop #2 (Part-1):
	==================================================
	Name   : Jiseok Shim
	ID     : 122758170
	Email  : jshim13@myseneca.ca
	Section: IPC144 NCC
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	double amount;
	int too, loo, qua, dim, nic, pen;

	printf("Change Maker Machine\n");
	printf("====================\n");
	printf("Enter dollars and cents amount to convert to coins: $");
	scanf("%lf", &amount);


	double fee = amount / 100 * 5;

	printf("Service fee (5.0 percent): %.2lf\n", fee);
	
	amount -= fee;
	
	printf("Balance to dispense: $%.2f\n", amount);

	int remain = (int)(amount * 100);
	too = remain / 200;
	remain %= 200;

	printf("\n");
	printf("$2.00 Toonies  X %d (remaining: $%1.2lf)\n", too, (double)remain / 100);

	loo = remain / 100;
	remain %= 100;

	printf("$1.00 Loonies  X %d (remaining: $%1.2lf)\n", loo, (double)remain / 100);

	qua = remain / 25;
	remain %= 25;

	printf("$0.25 Quarters X %d (remaining: $%1.2lf)\n", qua, (double)remain / 100);

	dim = remain / 10;
	remain %= 10;

	printf("$0.10 Dimes    X %d (remaining: $%1.2lf)\n", dim, (double)remain / 100);

	nic = remain / 5;
	remain %= 5;

	printf("$0.05 Nickels  X %d (remaining: $%1.2lf)\n", nic, (double)remain / 100);

	pen = remain / 1;
	remain %= 1;

	printf("$0.01 Pennies  X %d (remaining: $%1.2lf)\n\n", pen, (double)remain / 100);
	printf("All coins dispensed!\n");

	return 0;
}