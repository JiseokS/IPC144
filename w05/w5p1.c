/*
* Name: Jiseok Shim
* Student Number: 122758170
* Seneca Email Address: jshim13@myseneca.ca
* Section Information Code: IPC144 NCC
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_LIVES 10
#define MIN_LIVES 1
#define MAX_LENGTH 70
#define MIN_LENGTH 10

struct PlayerInfo {
	int lives;
	char charsymbol;
	int treasure;
	int history_positions[MAX_LENGTH];
};

struct GameInfo {
	int moves;
	int length;
	int bombs[MAX_LENGTH / 5];
	int treasure[MAX_LENGTH / 5];

};

int main(void)
{
	int valid = 0;
	int lives, length, moves;
	char charsymbol;
	printf("================================\n");
	printf("         Treasure Hunt!         \n");
	printf("================================\n\n");

	printf("PLAYER Configuration\n");
	printf("--------------------\n");
	printf("Enter a single character to represent the player: ");
	scanf(" %c", &charsymbol);
	do {
		valid = 1;
		printf("Set the number of lives: ");
		scanf("%d", &lives);
		if (lives < MIN_LIVES || lives > MAX_LIVES) {
			valid = 0;
			printf("     Must be between 1 and 10!\n");
		}
		else
			break;
	} while (!valid);

	printf("Player configuration set-up is complete\n\n");

	printf("GAME Configuration\n");
	printf("------------------\n");
	
	do {
		valid = 1;
		printf("Set the path length (a multiple of 5 between 10-70): ");
		scanf("%d", &length);

		if ((length >= MIN_LENGTH || length <= MAX_LENGTH) && length % 5 == 0) {
			break;
		}
		else
			valid = 0;
		printf("     Must be a multiple of 5 and between 10-70!!!\n");
	} while (!valid);

	int Max_moves = (int)(3 * length / 4);
	
	do {
		printf("Set the limit for number of moves allowed: ");
		scanf("%d", &moves);
		if (moves < lives || moves > Max_moves) {
			valid = 0;
			printf("    Value must be between %d and %d\n",lives, Max_moves);
		}
		else
			break;
	} while (!valid);
	printf("\n");

	printf("BOMB Placement\n");
	printf("--------------\n");

	printf("Enter the bomb positions in sets of 5 where a value\n");
	printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
	printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n",length);
	int i;
	int bomb1[MAX_LENGTH / 5], bomb2[MAX_LENGTH / 5], bomb3[MAX_LENGTH / 5], bomb4[MAX_LENGTH / 5], bomb5[MAX_LENGTH / 5];
	for (i = 0; i < (length / 5); i++) {
		printf("   Positions [%2d-%2d]: ",i*5+1,i*5+5);
		scanf("%d %d %d %d %d", &bomb1[i], &bomb2[i], &bomb3[i], &bomb4[i], &bomb5[i]);
	}
	printf("BOMB placement set\n\n");

	printf("TREASURE Placement\n");
	printf("------------------\n");
	printf("Enter the treasure placements in sets of 5 where a value\n");
	printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
	printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n",length);
	int treasure1[MAX_LENGTH / 5], treasure2[MAX_LENGTH / 5], treasure3[MAX_LENGTH / 5], treasure4[MAX_LENGTH / 5], treasure5[MAX_LENGTH / 5];
	for (i = 0; i < (length / 5); i++) {
		printf("   Positions [%2d-%2d]: ", i * 5 + 1, i * 5 + 5);
		scanf("%d %d %d %d %d", &treasure1[i], &treasure2[i], &treasure3[i], &treasure4[i], &treasure5[i]);
	}
	printf("TREASURE placement set\n\n");
	printf("GAME configuration set-up is complete...\n\n");

	printf("------------------------------------\n");
	printf("TREASURE HUNT Configuration Settings\n");
	printf("------------------------------------\n");
	printf("Player:\n");
	printf("   Symbol     : %c\n", charsymbol);
	printf("   Lives      : %d\n", lives);
	printf("   Treasure   : [ready for gameplay]\n");
	printf("   History    : [ready for gameplay]\n\n");

	printf("Game:\n");
	printf("   Path Length: %d\n", length);
	printf("   Bombs      : ");
	for (i = 0;i < (length / 5);i++) {
		printf("%d%d%d%d%d", bomb1[i], bomb2[i], bomb3[i], bomb4[i], bomb5[i]);
	}
	printf("\n");

	printf("   Treasure   : ");
	for (i = 0;i < (length / 5);i++) {
		printf("%d%d%d%d%d", treasure1[i], treasure2[i], treasure3[i], treasure4[i], treasure5[i]);
	}
	printf("\n\n");
	printf("====================================\n");
	printf("~ Get ready to play TREASURE HUNT! ~\n");
	printf("====================================\n");
	return 0;
}