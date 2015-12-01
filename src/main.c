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
 * SOFTWARE.
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 */
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>

#include "braf.h"
#include "interactive_mode.h"
#include "util.h"
#include "process_files.h"

int main(int argc, char *argv[])
{
    char tape[30000] = {0};
    char *tapePtr = tape;
    char *code = NULL;

    // Handle the arguments
    bool verbose = false;
    for (int argIndex = 1; argIndex < argc; argIndex++) { // Apply any debug flags
        int argLen = strlen(argv[argIndex]);
        char currArg[argLen];
        strcpy(currArg, argv[argIndex]);

        if (strcmp(currArg, "-d") == 0 || strcmp(currArg, "--debug") == 0 ||
            strcmp(currArg, "--verbose") == 0) {
            if (verbose) {
                verbose = false;
            } else if (!verbose) {
               verbose = true;
            }
        }
    }

    if (argc == 1) { // No debugging enabled
        braf_interactiveMode(tapePtr, false);
    } else if (argc == 2 && (strcmp(argv[1], "-d") == 0 ||
               strcmp(argv[1], "--debug") == 0 || strcmp(argv[1], "--verbose") == 0)) {
        braf_interactiveMode(tapePtr, true);
    } else if (argc > 1) {
        bool helpDisplayed = false;
        bool versionDisplayed = false;
        bool enableInteractive = false;
        bool interactiveDone = false;
        for (int argIndex = 1; argIndex < argc; argIndex++) {
            int argLen = strlen(argv[argIndex]);
            char currArg[argLen];
            strcpy(currArg, argv[argIndex]);
            if (currArg[0] == '-') { // Handle the flags
                if (strcmp(currArg, "-h") == 0 || strcmp(currArg, "--help") == 0) {
                    if (!helpDisplayed) {
                        braf_displayHelp();
                        helpDisplayed = true;
                    }
                } else if (strcmp(currArg, "-v") == 0 || strcmp(currArg, "--version") == 0) {
                    if (!versionDisplayed) {
                        braf_displayInfo();
                        versionDisplayed = true;
                    }
                } else if (strcmp(currArg, "-i") == 0 || strcmp(currArg, "--interactive") == 0) {
                    if (!interactiveDone) {
                        braf_interactiveMode(tapePtr, verbose);
                        verbose = false;
                        interactiveDone = true;
                    }

                    return 0;
                } else if (strcmp(currArg, "-d") == 0 || strcmp(currArg, "--debug") == 0 ||
                           strcmp(currArg, "--verbose") == 0) {
                    continue; // Some ugly workaround
                } else {
                    braf_displayErrorInArguments("unknown arguments: ", currArg);

                    return 1;
                }
            } else { // Handle the files
                char *code = braf_extractCodeFromFile(currArg);
                if (code) {
                    braf_interpretCode(code, tapePtr, verbose);
                } else {
                    return 1;
                }
            }
        }
    }

    return 0;
}
