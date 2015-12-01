#include "process_files.h"
#include "util.h"

#include <stdio.h>
#include <stdlib.h>

char* braf_extractCodeFromFile(const char *file)
{
    FILE *fileHandler = fopen(file, "r");
    if (fileHandler) {
        char *code = NULL;
        char currChar = 0;
        int charIndex = 0;
        while ((currChar = getc(fileHandler)) != EOF) {
            code = realloc(code, sizeof(char) * (charIndex + 1));
            if (!code) {
                free(code);
                code = NULL;

                braf_displayError("Code parsing error. Error while allocating memory for the code to be interpreted. Memory might not be enough.");
                return NULL;
            }

            code[charIndex++] = currChar;
        }

        fclose(fileHandler);

        return code;
    } else {
        braf_displayErrorInArguments("file does not exist: ", file);

        return NULL;
    }
}
