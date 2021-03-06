#include "util.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <limits.h>

#define CAPACITY 128

void braf_displayError(const char *msg)
{
    printf("braf: error: %s\n", msg);
}

void braf_displayErrorInArguments(const char *msg, const char *arg)
{
    int msgLen = strlen(msg);
    char tmpMsg[msgLen + 1];
    strcpy(tmpMsg, msg);
    strcat(tmpMsg, arg);

    braf_displayError(tmpMsg);
    printf("Try 'braf --help' for more information.\n");
}

void braf_displayErrorInInterpreter(const char *msg, const int col, const int rw)
{
    printf("braf: error at line %d, column %d: %s\n", rw, col, msg);
}

void braf_displayHelp(void)
{
    printf("braf - a Brainfuck interpreter\n");
    printf("Usage: braf [options] <input files>\n");
    printf("Options:\n");
    printf("\t-h --help\t\tDisplay this help text\n");
    printf("\t-v --version\t\tDisplay braf version and additional information.\n");
    printf("\t-i --interactive\tExplicitly enable interactive mode.\n");
    printf("\t\t\t\tInteractive mode can be initialized by not including any flags.\n");
    printf("\t-d, --debug, --verbose  Enable debug mode. braf will display the values of the modified cells, and any performed operations.\n");
}

void braf_displayInfo(void)
{
    printf("braf - a Brainfuck interpreter\n");
    printf("Copyright (C) 2015 Kenneth Cu, Bea Santiago, Sean Ballais, Ivan Puayap\n");
    printf("Version 0.01a\n");
}

unsigned int braf_fileExists(const char *fileName)
{
    if (access(fileName, R_OK) != -1) { // File exists
        return 1;
    } else { // File doesn't exist
        return 0;
    }
}

// Code slightly modified from the CS50 library
char* cs50_GetString(void)
{
    char *buffer = NULL;
    unsigned int bufferCapacity = 0;
    unsigned int numChar = 0;
    int c;

    // Iteratively get chars from standard input
    while ((c = fgetc(stdin)) != '\n' && c != EOF) {
        // Grow buffer if necessary
        if (numChar + 1 > bufferCapacity) {
            // Determine new capacity: start at CAPACITY then double
            if (bufferCapacity == 0) {
                bufferCapacity = CAPACITY;
            } else if (bufferCapacity <= (UINT_MAX / 2)) {
                bufferCapacity *= 2;
            } else {
                free(buffer);

                return NULL;
            }

            // Extend buffer's capacity
            char *tmp = realloc(buffer, bufferCapacity * sizeof(char));
            if (tmp == NULL) {
                free(buffer);

                return NULL;
            }

            buffer = tmp;
        }

        // Append current character to buffer
        buffer[numChar++] = c;
    }

    // Return NULL if user provided no input
    if (numChar == 0 && numChar == EOF) {
        return NULL;
    }

    // Minimize buffer
    char *minimal = malloc((numChar + 1) * sizeof(char));
    strncpy(minimal, buffer, numChar);
    free(buffer);

    // Terminate string
    minimal[numChar] = '\0';

    return minimal;
}
