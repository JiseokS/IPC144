///*
//	==================================================
//	Workshop #2 (Part-1):
//	==================================================
//	Name   : Jiseok Shim
//	ID     : 122758170
//	Email  : jshim13@myseneca.ca
//	Section: IPC144 NCC
//*/
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//int main(void)
//{
//	float amount, remain1, remain2, remain3;
//	int too, loo, qua;
//	float fee, balance;
//
//	printf("Change Maker Machine\n");
//	printf("====================\n");
//	printf("Enter dollars and cents amount to convert to coins: $");
//	scanf("%f", &amount);
//
//
//	fee = amount / 100 * 5;
//	balance = amount - fee;
//
//	printf("Service fee (5.0 percent): %.2f", fee);
//	printf("Balance to dispense: $%.2f", balance);
//
//	too = amount / 2.00;
//	remain1 = amount - too * 2;
//
//	printf("\n");
//	printf("$2.00 Toonies  X %d (remaining: $%.2f)\n", too, remain1);
//
//	loo = remain1 / 1.00;
//	remain2 = remain1 - loo * 1;
//
//	printf("$1.00 Loonies  X %d (remaining: $%.2f)\n", loo, remain2);
//
//	qua = remain2 / 0.25;
//	remain3 = remain2 - qua * 0.25;
//
//	printf("$0.25 Quarters X %d (remaining: $%.2f)\n\n", qua, remain3);
//	printf("Machine error! Thank you for letting me keep $%.2f!\n", remain3);
//
//	return 0;
//}