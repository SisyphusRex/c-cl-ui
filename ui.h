// Copyright 2025 Theodore Podewil
// GPL-3.0-or-later

/*
This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. 
*/

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
