#include "braf.h"
#include "error_check.h"

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

unsigned int braf_interpretCode(const char *code, char *dataPtr, const bool verbose)
{
    int rw = 1;
    int col = 1;
    int loop = 0;
    unsigned int chkResults = 0;
    char currChar = '\0';
    int tapeIndex = 1;
    for (int index = 0; code[index] != '\0'; index++) {
        currChar = code[index];
        if (currChar == '+') { // Increment the value in the pointer by 1
            if (verbose) {
                printf("Cell #%d value incremented.\nOriginal Value: %d\t", tapeIndex, (int) *dataPtr);
                (*dataPtr)++;
                printf("New value: %d\n", (int) *dataPtr);
            } else {
                (*dataPtr)++;
            }

            chkResults = braf_valOverflowCheck(dataPtr, col, rw);
            if (chkResults) {
                return 1;
            }
        } else if (currChar == '-') { // Decrement the value in the pointer by 1
            if (verbose) {
                printf("Cell #%d value decremented.\nOriginal Value: %d\t", tapeIndex, (int) *dataPtr);
                (*dataPtr)--;
                printf("New value: %d\n", (int) *dataPtr);
            } else {
                (*dataPtr)--;
            }

            chkResults = braf_valUnderflowCheck(dataPtr, col, rw);
            if (chkResults) {
                return 1;
            }
        } else if (currChar == '<') { // Move one step back in the tape
            if (verbose) {
                printf("Active cell shifted to the left. \nPrevious active cell: %d\t", tapeIndex);
                tapeIndex--;
                printf("Current active cell: %d\n", tapeIndex);
            } else {
                tapeIndex--;
            }

            chkResults = braf_tapeAccessCheck(tapeIndex, col, rw);
            if (chkResults) {
                return 1;
            }

            dataPtr--;
        } else if (currChar == '>') { // Move one step forward in the tape
            if (verbose) {
                printf("Active cell shifted to the right. \nPrevious active cell: %d\t", tapeIndex);
                tapeIndex++;
                printf("Current active cell: %d\n", tapeIndex);
            } else {
                tapeIndex++;
            }

            chkResults = braf_tapeAccessCheck(tapeIndex, col, rw);
            if (chkResults) {
                return 1;
            }

            dataPtr++;
        } else if (currChar == '.') { // Output the data
            putchar(*dataPtr);
        } else if (currChar == ',') { // Input data
            *dataPtr = getchar();
        } else if (currChar == '[') { // Start of a loop
            col++;
            continue;
        } else if (currChar == ']' && *dataPtr) { // End of a loop
            loop = 1;
            while (loop > 0) {
                currChar = code[--index];
                col--;
                if (currChar == '[') {
                    loop--;
                } else if (currChar == ']') {
                    loop++;
                }
            }
        } else if (currChar == '\n') {
            col = 0;
            rw++;
        }

        col++;
    }

    return 0;
}
