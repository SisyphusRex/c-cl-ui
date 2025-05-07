# c-cl-ui
This is a plug-n-play Command Line User Interface for programs written in C.

## How To
Copy the ui.c, and colors.c to your src folder.  Copy ui.h and colors.h to your incl folder.
Put:
```
#include "ui.h"
```
in the file where you want to use the UI.

The entry point function for the UI is PrintMenuAndGetMenuInput(const char *menu[]).
It takes in an array of strings where each string is a menu option and prints them out from 1 to last menu option.  The function reads the user's input for menu choice, validates the input, and then returns the corresponding int.  BEWARE, the number returned is one more than the corresponding menu options index in the menu array (if user selects option 1, index in the array is 0).

The menu array must be in the form:
```
const char *menu[] = {"option 1", "option 2", ..., "option n", NULL}
```
NULL is required to be at the end of the array.


```
const char *menu[] = {"Go Forward.", "Go Back.", NULL};  //NULL is required to read the end of the array

int userInput = PrintMenuAndGetMenuInput(menu);

if (userInput == 1) {
    char *choice = menu[0] //returned userInput is one more than corresponding index
}
```

