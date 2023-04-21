/*
* Name: Jiseok Shim
* Student Number: 122758170
* Seneca Email Address: jshim13@myseneca.ca
* Section Information Code: IPC144 NCC
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MIN_YEAR 2010
#define MAX_YEAR 2021

int main(void)
{
	const int JAN = 1;
	const int DEC = 12;

	int year, month, valid, A, B;

	printf("General Well-being Log\n");
	printf("======================\n");

	do {

		printf("Set the year and month for the well-being log (YYYY MM): ");
		scanf("%d %d", &year, &month);

		A = (year < MIN_YEAR || year > MAX_YEAR);
		B = (month < JAN || month > DEC);

		if (A && B) {
			valid = 0;
			printf("   ERROR: The year must be between 2010 and 2021 inclusive\n");
			printf("   ERROR: Jan.(1) - Dec.(12)\n");
		}
		else if (A) {
			valid = 0;
			printf("   ERROR: The year must be between 2010 and 2021 inclusive\n");
		}else if (B){
			valid = 0;
			printf("   ERROR: Jan.(1) - Dec.(12)\n");
		}
		else {
			break;
		}
	} while (!valid);

	
	
	printf("\n*** Log date set! ***\n\n");
	printf("Log starting date: %d-", year);


	switch (month) {
	case 1:
		printf("JAN");
		break;
	case 2:
		printf("FEB");
		break;
	case 3:
		printf("MAR");
		break;
	case 4:
		printf("APR");
		break;
	case 5:
		printf("MAY");
		break;
	case 6:
		printf("JUN");
		break;
	case 7:
		printf("JUL");
		break;
	case 8:
		printf("AUG");
		break;
	case 9:
		printf("SEP");
		break;
	case 10:
		printf("OCT");
		break;
	case 11:
		printf("NOV");
		break;
	case 12:
		printf("DEC");
		break;
	}

	printf("-01\n");

			
		
	return 0;
}






