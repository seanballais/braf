/*
 * braf - Brainfuck interpreter
 * Developed by:
 *     - Bea Santiago (<>)
 *     - Kenneth Cu (<>)
 *     - Sean Ballais (@seanballais <sfballais123@gmail.com>)
 *     - Ivan Puayap
 *
 * braf is licensed under the MIT License (MIT)
 * Copyright (c) 2015 Bea Santiago, Kenneth Cu, Ivan Puayap, and Sean Ballais
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#include "util.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define CAPACITY 128

void braf_displayError(const char *msg)
{
    printf("braf: error: %s\n", msg);
}

void braf_displayErrorInArguments(const char *msg, const char *arg)
{
    strcat(msg, "'");
    strcat(msg, arg);
    strcat(msg, "'");

    braf_displayError(msg);
}

void braf_displayErrorInInterpreter(const char *msg, const int col = 0, const int rw = 0)
{
    printf("braf: error at line %d, column %d: %s\n", rw, col, msg);
}

void braf_displayHelp(void)
{
    printf("braf - a Brainfuck interpreter\n");
    printf("Usage: braf [options] <input files>\n");
    printf("Options:\n");
    printf("\t-h --help\tDisplay this help text\n");
    printf("\t-v --version\tDisplay braf version and additional information.\n")
    printf("\t-i --interactive\tExplicitly enable interactive mode.\n");
    printf("\t\t\tInteractive mode can be initialized by not including any flags.\n");
    printf("\t-d --debug\tEnable debug mode. braf will display the values of the modified cells, and any performed operations.\n");
    printf("\t   --verbose\n");
    printf("NOTE: braf will accept any text file (.c, .txt, .ini) and will treat them as if they contain Brainfuck code, as long as the text file has a file extension.\n");
}

void braf_displayInfo(void)
{
    printf("braf - a Brainfuck interpreter\n");
    printf("Copyright (C) 2015 Kenneth Cu, Bea Santiago, Sean Ballais, Ivan Puayap\n");
    printf("Version 0.01a\n");
}

void braf_fileExists(const char *fileName)
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
        if (numChar + 1 > capacity) {
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
            char *tmp = realloc(buffer, capacity * sizeof(char));
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
    if (numChar == 0 && c == EOF) {
        return NULL;
    }

    // Minimize buffer
    char *minimal = malloc((n + 1) * sizeof(char));
    strncpy(minimal, buffer, n);
    free(buffer);

    // Terminate string
    minimal[n] = '\0';

    return minimal;
}
