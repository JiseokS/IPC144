//==============================================
// Name:           Jiseok Shim
// Student Number: 122758170
// Email:          jshim13@myseneca.ca
// Section:        NCC
// Date:           2021.07.14
//==============================================
// Assignment:     2
// Milestone:      2
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the functions you prototyped
// in the contact helper header file.
// HINT: Put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
//       #include your contactHelpers header file on the next line:


//--------------------------------
// Function Definitions
//--------------------------------

// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 2 =======       |
// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        empty function definitions below and     |
// |        complete the definitions as per the      |
// |        Milestone-2 specifications               | 
// |                                                 |
// | - The clearKeyboard function is done for you    |
// +-------------------------------------------------+


// Clear the standard input buffer
void clearKeyboard(void)
{
    {
        while (getchar() != '\n'); // empty execution code block on purpose
    }
}

// pause function definition goes here:
void pause(void)
{
    printf("(Press Enter to Continue)");
    clearKeyboard();
}

// getInt function definition goes here:
int getInt(void)
{
    int num;
    char ch = 'x'; 

    while (ch != '\n')
    {
        scanf("%d%c", &num, &ch); 
        if (ch != '\n')               
        {
            clearKeyboard();
            printf("*** INVALID INTEGER *** <Please enter an integer>: ");
        }
    }
    return num;
}

// getIntInRange function definition goes here:
int getIntInRange(int min, int max)
{
    int validinteger = getInt();

    while (validinteger < min || validinteger > max) {
        printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ",min,max);
        validinteger = getInt();
    }
    
    return validinteger;
}

// yes function definition goes here:
int yes(void)
{
    int key = 0; 
    char char1, char2;

    do
    {
        scanf("%c%c", &char1, &char2);
        if (char2 != '\n' || (char1 != 'Y' && char1 != 'y' && char1 != 'N' && char1 != 'n'))
        {
            if (char2 != '\n') 
            {
                clearKeyboard();
            }

            printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
        }
        else if (char1 == 'Y' || char1 == 'y')
        {
            key = 1; 
        }
    } while (char2 != '\n' || (char1 != 'Y' && char1 != 'y' && char1 != 'N' && char1 != 'n'));

    return key;
}



// menu function definition goes here:
int menu(void)
{
    puts("Contact Management System");
    puts("-------------------------");
    puts("1. Display contacts");
    puts("2. Add a contact");
    puts("3. Update a contact");
    puts("4. Delete a contact");
    puts("5. Search contacts by cell phone number");
    puts("6. Sort contacts by cell phone number");
    puts("0. Exit");
    puts("");
    printf("Select an option:> ");
    return getIntInRange(0, 6);
}

// contactManagerSystem function definition goes here:
void contactManagerSystem(void)
{

    int valid = 0;

    do
    {

        switch (menu())
        {
        case 0:
            puts("");
            printf("Exit the program? (Y)es/(N)o: ");
            valid = yes();
            puts("");
            break;

        case 1:
            puts("");
            puts("<<< Feature 1 is unavailable >>>\n");
            pause();
            puts("");
            break;

        case 2:
            puts("");
            puts("<<< Feature 2 is unavailable >>>\n");
            pause();
            puts("");
            break;

        case 3:
            puts("");
            puts("<<< Feature 3 is unavailable >>>\n");
            pause();
            puts("");
            break;

        case 4:
            puts("");
            puts("<<< Feature 4 is unavailable >>>\n");
            pause();
            puts("");
            break;

        case 5:
            puts("");
            puts("<<< Feature 5 is unavailable >>>\n");
            pause();
            puts("");
            break;

        case 6:
            puts("");
            puts("<<< Feature 6 is unavailable >>>\n");
            pause();
            puts("");
            break;

        default:
            break;
        }
    } while (valid != 1);
    printf("Contact Management System: terminated\n");
}

int getintpositive(const char* error)
{
    int valid = getInt();

    while (valid < 0)
    {
        printf(error);
        valid = getInt();
    }

    return valid;
}