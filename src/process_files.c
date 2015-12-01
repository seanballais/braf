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
