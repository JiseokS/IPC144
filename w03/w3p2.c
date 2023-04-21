/*
* Name: Jiseok Shim
* Student Number: 122758170
* Seneca Email Address: jshim13@myseneca.ca
* Section Information Code: IPC144 NCC
*/

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MIN_YEAR 2010
#define MAX_YEAR 2021
#define LOG_DAYS 3

int main(void)
{
	const int JAN = 1;
	const int DEC = 12;

	int year, month, valid, A, B;

	double Total_M, Total_E, Ove_total, ave_mor_rate, ave_eve_rate, ave_ove_rate;
	Total_M = 0;
	Total_E = 0;
	Ove_total = 0;
	ave_mor_rate = 0;
	ave_eve_rate = 0;
	ave_ove_rate = 0;
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
		}
		else if (B) {
			valid = 0;
			printf("   ERROR: Jan.(1) - Dec.(12)\n");
		}
		else {
			break;
		}
	} while (!valid);



	printf("\n*** Log date set! ***\n\n");

	int i;
	double M_Rate, E_Rate;

	for (i = 1;i <= LOG_DAYS;i++)
	{

		printf("%d-", year);


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

		printf("-%02d\n", i);
		
	
		do {

			printf("   Morning rating (0.0-5.0): ");
			scanf("%lf", &M_Rate);
			
			

			if (M_Rate <0.0 || M_Rate > 5.0) {
				valid = 0;
				printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
		
			}
			else {
				Total_M += M_Rate;
				break;
			}
		} while (!valid);

		do {

			printf("   Evening rating (0.0-5.0): ");
			scanf("%lf", &E_Rate);
			

			if (E_Rate < 0.0 || E_Rate > 5.0) {
				valid = 0;
				printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");

			}
			else {
				Total_E += E_Rate;
				break;
			}
		} while (!valid);
		printf("\n");

	}
	
	printf("Summary\n");
	printf("=======\n");
	printf("Morning total rating: %.3lf\n", Total_M);
	printf("Evening total rating: %.3lf\n", Total_E);
	printf("----------------------------\n");
	Ove_total = Total_M + Total_E;
	ave_mor_rate = Total_M / (double)LOG_DAYS;
	ave_eve_rate = Total_E / (double)LOG_DAYS;
	printf("Overall total rating: %.3lf\n\n", Ove_total);
	printf("Average morning rating:  %.1lf\n", ave_mor_rate);
	printf("Average evening rating:  %.1lf\n", ave_eve_rate);
	printf("----------------------------\n");
	ave_ove_rate = Ove_total / (double)(LOG_DAYS*2);
	printf("Average overall rating:  %.1lf\n", ave_ove_rate);
	


	return 0;
}

