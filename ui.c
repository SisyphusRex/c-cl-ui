#include <stdio.h>
#include <stdlib.h>
#include "ui.h"
#include "colors.h"

// This is the only function available outside of this file.  All other functions are helper functions.
int PrintMenuAndGetMenuInput(const char *menu[])
{
    int numberOfCharacters = 4; // here you will have to decide how many characters input will be, including NULL or /0
    int numberOfMenuItems = CountMenuItems(menu);
    char *userInput = NULL;
    userInput = (char *)malloc(numberOfCharacters * sizeof(char));
    int isValid = -1;
    int convertedInput;
    // printf("number of menu items: %d\n", numberOfMenuItems);

    while (isValid < 0)
    {
        PrintMenu(numberOfMenuItems, menu);
        PrintInputRequestAndGetMenuInput(userInput, numberOfCharacters);
        isValid = ValidateInput(userInput, numberOfMenuItems);
    }
    sscanf(userInput, "%d", &convertedInput);
    printf("user input: %d", convertedInput);
    free(userInput);
    return convertedInput;
}

void PrintInputRequestAndGetMenuInput(char *userInput, int numberOfCharacters)
{
    PrintInputRequest();
    GetMenuInput(userInput, numberOfCharacters);
    printf("\n");
}

int CountMenuItems(const char *menu[])
{
    int count = 0;
    while (menu[count] != NULL)
    {
        count++;
    }
    return count;
}

void PrintMenu(int numberOfMenuItems, const char *menu[])
{
    printf("MAIN MENU:\n");
    for (int i = 0; i < numberOfMenuItems; i++)
    {
        printf("%d. %s\n", i + 1, menu[i]);
    }
    printf("\n");
}

void PrintInputRequest(void)
{

    printf("Enter menu selection:\n");
    printf("> ");
}

void GetMenuInput(char *userInput, int numCharacters)
{
    // Here we use fgets() to prevent buffer overflow
    char buff[10];

    fgets(buff, numCharacters, stdin);
    sscanf(buff, "%s", userInput);
    // printf("%s", userInput);
}

int ValidateInput(char *userInput, int numberOfMenuItems)
{
    int convertedInput;
    if (ValidateIsInt(userInput) < 0)
    {
        return -1;
    }
    sscanf(userInput, "%d", &convertedInput);
    if (ValidateIsPositiveInt(convertedInput) < 0)
    {
        return -1;
    }
    if (ValidateIsInMenu(convertedInput, numberOfMenuItems) < 0)
    {
        return -1;
    }
    return 1;
}

int ValidateIsInt(char *userInput)
{

    int convertedToInt;
    if (sscanf(userInput, "%d", &convertedToInt) == 1)
    {
        return 1;
    }
    else
    {
        ErrorNotInt();
        return -1;
    }
}

int ValidateIsPositiveInt(int convertedInput)
{
    if (convertedInput > 0)
    {
        return 1;
    }
    else
    {
        ErrorNotPositiveInt();
        return -1;
    }
}

int ValidateIsInMenu(int convertedInput, int numberOfMenuItems)
{
    if (convertedInput <= numberOfMenuItems)
    {
        return 1;
    }
    else
    {
        ErrorNotInMenu();
        return -1;
    }
}

void ErrorNotInt(void)
{
    PrintRed("ERROR: Not an integer.\nYou must enter an integer.\n\n");
}

void ErrorNotPositiveInt(void)
{
    PrintRed("ERROR: Not a positive integer.\nYou must enter a positive integer.\n\n");
}

void ErrorNotInMenu()
{
    PrintRed("ERROR: Your selection is not in the menu.\n\n");
}