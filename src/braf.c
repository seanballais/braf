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
#include "braf.h"
#include "error_check.h"

#include <stdio.h>
#include <string.h>

unsigned int braf_interpretCode(char *code, char *dataPtr, bool verbose)
{
    int rw = 0
    int col = 0;
    int loop = 0;
    unsigned int chkResults = 0;
    char currChar = '\0';
    int tapeIndex = 1;
    for (int index = 0; code[index] != '\0'; index++) {
        currChar = code[index];
        if (currChar == '+') { // Increment the value in the pointer by 1
            if (verbose) {
                printf("Cell #%d value incremented. Original Value: %c\tNew value: %c\n", tapeIndex, *dataPtr, (*dataPtr)++)
            } else {
                (*dataPtr)++;
            }

            chkResults = braf_valOverflowCheck(*dataPtr, col, rw)
            if (chkResults) {
                return 1;
            }
        } else if (currChar == '-') { // Decrement the value in the pointer by 1
            if (verbose) {
                printf("Cell #%d value decremented. Original Value: %c\tNew value: %c\n", tapeIndex, *dataPtr, (*dataPtr)--)
            } else {
                (*dataPtr)--;
            }

            chkResults = braf_valUnderflowCheck(*dataPtr, col, rw)
            if (chkResults) {
                return 1;
            }
        } else if (currChar == '<') { // Move one step back in the tape
            if (verbose) {
                printf("Active cell changed shifted to the left. Previous active index: %d\t Current active index: %d\n", tapeIndex, tapeIndex--)
            } else {
                tapeIndex--;
            }
            dataPtr--;

            chkResults = braf_tapeAccessCheck(tapeIndex, col, rw);
            if (chkResults) {
                return 1;
            }
        } else if (currChar == '>') { // Move one step forward in the tape
            if (verbose) {
                printf("Active cell changed shifted to the right. Previous active index: %d\t Current active index: %d\n", tapeIndex, tapeIndex++)
            } else {
                tapeIndex++;
            }
            dataPtr++;

            chkResults = braf_tapeAccessCheck(tapeIndex, col, rw);
            if (chkResults) {
                return 1;
            }
        } else if (currChar == '.') { // Output the data
            putchar(*dataPtr);
        } else if (currChar == ',') { // Input data
            *dataPtr = getchar();
        } else if (currChar == '[') { // Start of a loop
            continue;
        } else if (currChar == ']' && *dataPtr) { // End of a loop
            loop = 1;
            while (loop > 0) {
                currChar = code[--index];
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
}
