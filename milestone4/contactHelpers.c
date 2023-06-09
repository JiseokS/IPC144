//==============================================
// Name:           Jiseok Shim
// Student Number: 122758170
// Email:          jshim13@myseneca.ca
// Section:        NCC
// Date:           2021.07.29
//==============================================
// Assignment:     2
// Milestone:      4
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        contents below...                        |
// +-------------------------------------------------+

#define MAXCONTACTS 5

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "contactHelpers.h"
#include "contacts.h"

// clearKeyboard:  Empty function definition
void clearKeyboard(void)
{
    {
        while (getchar() != '\n')
            ; 
    }
}

// pause: Empty function definition goes here:
void pause(void)
{
    puts("");
    printf("(Press Enter to Continue)");
    clearKeyboard();
}

// getInt: Empty function definition goes here:
int getInt(void)
{
    int validInt;
    char invalidChar = 'x'; 

    while (invalidChar != '\n')
    {
        scanf("%d%c", &validInt, &invalidChar); 
        if (invalidChar != '\n')                
        {
            clearKeyboard();
            printf("*** INVALID INTEGER *** <Please enter an integer>: ");
        }
    }
    return validInt;
}

// getIntInRange: Empty function definition goes here:
int getIntInRange(int min, int max)
{
    int validRange = getInt();

    while (validRange < min || validRange > max)
    {
        printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
        validRange = getInt();
    }
    return validRange;
}

// yes: Empty function definition goes here:
int yes(void)
{
    int validYes = 0; 
    char validChar, newlineChar;

    do
    {
        scanf("%c%c", &validChar, &newlineChar);
        if (newlineChar != '\n' || (validChar != 'Y' && validChar != 'y' && validChar != 'N' && validChar != 'n'))
        {
            if (newlineChar != '\n') 
            {
                clearKeyboard();
            }

            printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
        }
        else if (validChar == 'Y' || validChar == 'y')
        {
            validYes = 1; 
        }
    } while (newlineChar != '\n' || (validChar != 'Y' && validChar != 'y' && validChar != 'N' && validChar != 'n'));

    return validYes;
}

// menu: Empty function definition goes here:
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

// contactManagerSystem: Empty function definition goes here:
void contactManagerSystem(void)
{
    int valid = 0;

    struct Contact contacts[MAXCONTACTS] =
    {
        {{"Rick", {'\0'}, "Grimes"},
         {11, "Trailer Park", 0, "A7A 2J2", "King City"},
         {"4161112222", "4162223333", "4163334444"}},

        {{"Maggie", "R.", "Greene"},
        {55, "Hightop House", 0, "A9A 3K3", "Bolton"},
        {"9051112222", "9052223333", "9053334444"}},

        {{"Morgan", "A.", "Jones"},
        {77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough"},
        {"7051112222", "7052223333", "7053334444"}},

        {{"Sasha", {'\0'}, "Williams"},
        {55, "Hightop House", 0, "A9A 3K3", "Bolton"},
        {"9052223333", "9052223333", "9054445555"}},
    };

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
            displayContacts(contacts, MAXCONTACTS);
            pause();
            puts("");
            break;

        case 2:
            puts("");
            addContact(contacts, MAXCONTACTS);
            pause();
            puts("");
            break;

        case 3:
            puts("");
            updateContact(contacts, MAXCONTACTS);
            pause();
            puts("");
            break;

        case 4:
            puts("");
            deleteContact(contacts, MAXCONTACTS);
            pause();
            puts("");
            break;

        case 5:
            puts("");
            searchContacts(contacts, MAXCONTACTS);
            pause();
            puts("");
            break;

        case 6:
            puts("");
            sortContacts(contacts, MAXCONTACTS);
            pause();
            puts("");
            break;

        default:
            break;
        }
    } while (valid != 1);

    puts("Contact Management System: terminated");
}


int getPositiveInt(const char* errrMsg)
{
    int validInt = getInt();

    while (validInt < 0)
    {
        printf(errrMsg);
        validInt = getInt();
    }
    return validInt;
}

// +-------------------------------------------------+
// |                                                 |
// |                    N E W                        |
// |           S T U F F     G O E S                 |
// |                  B E L O W                      |
// |                                                 |
// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 3 =======       |
// +-------------------------------------------------+
// | Put empty function definitions below...         |
// +-------------------------------------------------+

// Generic function to get a ten-digit phone number (ensures 10-digit chars entered)
// ---------------------------------------------------------------------------------
// NOTE: Modify this function to validate only numeric character digits are entered
// ---------------------------------------------------------------------------------
void getTenDigitPhone(char phoneNum[])
{
    int i;
    int needInput = 1, valid = 0;

    while (needInput == 1)
    {

        scanf("%s", phoneNum);
        clearKeyboard();

       
        if (strlen(phoneNum) == 10)
        {
            
            for (i = 0; i < 10; i++)
            {
                if (!isdigit(phoneNum[i]))
                {
                    valid++;
                }
            }

            if (valid == 0)
            {
                needInput = 0;
            }
            else
            {
                printf("Enter a 10-digit phone number: ");
                valid = 0;
            }
        }
        else
        {
            printf("Enter a 10-digit phone number: ");
        }
    }
}

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
    int i, contactIndex = -1;

    
    for (i = 0; i < size; i++)
    {
        
        if (strcmp(contacts[i].numbers.cell, cellNum) == 0)
        {
            contactIndex = i;
        }
    }
    return contactIndex;
}


// displayContactHeader
// Put empty function definition below:
void displayContactHeader(void)
{
    puts("+-----------------------------------------------------------------------------+");
    puts("|                              Contacts Listing                               |");
    puts("+-----------------------------------------------------------------------------+");
}

// displayContactFooter
// Put empty function definition below:
void displayContactFooter(int count)
{
    puts("+-----------------------------------------------------------------------------+");
    printf("Total contacts: %d\n", count);

}

// displayContact:
// Put empty function definition below:
void displayContact(const struct Contact* contact)
{
    printf(" %s", contact->name.firstName);

    
    if (strlen(contact->name.middleInitial) > 0)
    {
        printf(" %s", contact->name.middleInitial);
    }
    printf(" %s\n", contact->name.lastName);

    printf("    C: %-10s   H: %-10s   B: %-10s\n", contact->numbers.cell, contact->numbers.home, contact->numbers.business);
    printf("       %d %s, ", contact->address.streetNumber, contact->address.street);

    
    if (contact->address.apartmentNumber > 0)
    {
        printf("Apt# %d, ", contact->address.apartmentNumber);
    }

    printf("%s, %s\n", contact->address.city, contact->address.postalCode);
}

// displayContacts:
// Put empty function definition below:
void displayContacts(const struct Contact contacts[], int size)
{
    int i, totalContacts = 0;

    displayContactHeader();

    
    for (i = 0; i < size; i++)
    {
        if (strlen(contacts[i].numbers.cell) > 0)
        {
            displayContact(&contacts[i]);
            totalContacts++;
        }
    }
    displayContactFooter(totalContacts);
}

// searchContacts:
// Put empty function definition below:
void searchContacts(const struct Contact contacts[], int size)
{
    int searchNum;
    char inputNum[11] = { '\0' };

    printf("Enter the cell number for the contact: ");
    getTenDigitPhone(inputNum);

  
    searchNum = findContactIndex(contacts, size, inputNum);
    if (searchNum != -1)
    {
        puts("");
        displayContact(&contacts[searchNum]);
    }
    else
    {
        puts("*** Contact NOT FOUND ***");
    }
}

// addContact:
// Put empty function definition below:
void addContact(struct Contact contacts[], int size)
{
    int addCont;
    char newContact[11] = { '\0' };

    
    addCont = findContactIndex(contacts, size, newContact);
    if (addCont != -1)
    {
        getContact(&contacts[addCont]);
        puts("--- New contact added! ---");
    }
    else
    {
        puts("*** ERROR: The contact list is full! ***");
    }
}

// updateContact:
// Put empty function definition below:
void updateContact(struct Contact contacts[], int size)
{
    int updateCont;
    char inputNum[11] = { '\0' };

    printf("Enter the cell number for the contact: ");
    getTenDigitPhone(inputNum);

    updateCont = findContactIndex(contacts, size, inputNum);
    if (updateCont != -1)
    {
        puts("");
        puts("Contact found:");

        displayContact(&contacts[updateCont]);
        puts("");

        printf("Do you want to update the name? (y or n): ");
        if (yes() == 1)
        {
            getName(&contacts[updateCont].name);
        }

        printf("Do you want to update the address? (y or n): ");
        if (yes() == 1)
        {
            getAddress(&contacts[updateCont].address);
        }

        printf("Do you want to update the numbers? (y or n): ");
        if (yes() == 1)
        {
            getNumbers(&contacts[updateCont].numbers);
        }
        puts("--- Contact Updated! ---");
    }
    else
    {
        puts("*** Contact NOT FOUND ***");
    }
}

// Put empty function definition below:
void deleteContact(struct Contact contacts[], int size)
{
    int deleNum;
    char inputNum[11] = { '\0' };

    printf("Enter the cell number for the contact: ");
    getTenDigitPhone(inputNum);

    
    deleNum = findContactIndex(contacts, size, inputNum);
    if (deleNum != -1)
    {
        puts("");
        puts("Contact found:");
        displayContact(&contacts[deleNum]);
        puts("");
        printf("CONFIRM: Delete this contact? (y or n): ");
        if (yes() == 1)
        {
            
            contacts[deleNum].numbers.cell[0] = '\0';
            puts("--- Contact deleted! ---");
        }
    }
}

// sortContacts:

void sortContacts(struct Contact contacts[], int size)
{
    int i, j;
    struct Contact sortCon;

    for (i = 0; i < size; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (strcmp(contacts[i].numbers.cell, contacts[j].numbers.cell) > 0)
            {
                sortCon = contacts[i];
                contacts[i] = contacts[j];
                contacts[j] = sortCon;
            }
        }
    }
    puts("--- Contacts sorted! ---");
}


// getContact:
void getContact(struct Contact* contact)
{
    getName(&contact->name);
    getAddress(&contact->address);
    getNumbers(&contact->numbers);
}