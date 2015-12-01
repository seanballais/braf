#include "braf.h"
#include "interactive_mode.h"
#include "util.h"

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// Inspired from the Python REPL
void braf_interactiveMode(char *dataPtr, const bool verbose)
{
    braf_displayInfo();
    printf("Type 'Exit' or press Ctrl+C to exit braf.\n");

    // Get the code
    char codeChar;
    char *code;
    while (true) {
        printf(">>> ");
        code = cs50_GetString();
        if (strcmp(code, "Exit") == 0 || strcmp(code, "EXIT") == 0 || strcmp(code, "exit") == 0) {
            break;
        }

        braf_interpretCode(code, dataPtr, verbose);
        printf("\n");

    }
}
