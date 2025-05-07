#ifndef UI_H
#define UI_H

int PrintMenuAndGetMenuInput(const char *menu[]);
int CountMenuItems(const char *menu[]);
void PrintInputRequestAndGetMenuInput(char *userInput, int numberOfCharacters);
void PrintMenu(int numberOfMenuItems, const char *menu[]);
void GetMenuInput(char *userInput, int numberOfCharacters);
void PrintInputRequest(void);
int ValidateInput(char *userInput, int numberOfMenuItems);
int ValidateIsInt(char *userInput);
int ValidateIsPositiveInt(int convertedInput);
int ValidateIsInMenu(int convertedInput, int numberOfMenuItems);
void ErrorNotInt(void);
void ErrorNotPositiveInt(void);
void ErrorNotInMenu();

#endif