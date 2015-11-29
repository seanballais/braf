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
#include <stdio.h>
#include <unistd.h>

#include "braf.h"
#include "interactive_mode.h"
#include "util.h"

int main(int argc, char *argv[])
{
    char tape[30000] = {0};
    char *tapePtr = tape;
    char *code = NULL;

    // Check if there is an invalid argument
    bool verbose = false;
    if (argc > 1) {
        for (int argIndex = 1; argIndex < argc; argIndex++) {
            char *currArg = argv[argIndex];
            if (*currArg[0] == '-') { // Argument is a flag
                if (strcmp(currArg, "-h") != 0 || strcmp(currArg, "--help") != 0 ||
                    strcmp(currArg, "-v") != 0 || strcmp(currArg, "--version") != 0 ||
                    strcmp(currArg, "-i") != 0 || strcmp(currArg, "--interactive") != 0 ||
                    strcmp(currArg, "-d") != 0 || strcmp(currArg, "--debug") != 0 ||
                    strcmp(currArg, "--verbose") != 0)) {
                    braf_displayErrorInArguments("unknown arguments: ", currArg);

                    return 1;
                } else if (strcmp(currArg, "-d") == 0 || strcmp(currArg, "--debug") == 0 ||
                           strcmp(currArg, "--verbose") == 0)) {
                    verbose = true;
                }
            } else { // Argument is probably a file
                if (!braf_fileExists(currArg)) {
                    braf_displayErrorInArguments("file does not exist: ", currArg);

                    return 1;
                }
            }
        }
    }

    // Execute the flags
    if (argc > 1) {
        bool helpDisplayed = false;
        bool versionDisplayed = false;
        bool interactiveDone = false;
        for (int argIndex = 1; argIndex < argc; argIndex++) {
            char *currArg = argv[argIndex];
            if (strcmp(currArg, "-h") == 0 || strcmp(currArg, "--help") == 0) {
                if (!helpDisplayed) {
                    braf_displayHelp(void);
                    helpDisplayed = true;
                }
            } else if (strcmp(currArg, "-v") == 0 || strcmp(currArg, "--version") == 0) {
                if (!versionDisplayed) {
                    braf_displayInfo(void);
                    versionDisplayed = true;
                }
            } else if (strcmp(currArg, "-i") == 0 || strcmp(currArg, "--interactive") == 0) {
                if (!interactiveDone) {
                    braf_interactiveMode(dataPtr, verbose);
                    interactiveDone = true;
                }
            } else { // Handle the files
                char *code;
                int currChar = 0;
                FILE *file = fopen(currArg, "r");
                if (file) {
                    while ((currChar = getc(file)) != EOF) {
                        strcat(code, currChar);
                    }

                    fclose(file);
                }

                braf_interpretCode(code, tapePtr, verbose);
            }
        }
    }

    return 0;
}
