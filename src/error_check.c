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
#include "error_check.h"
#include "util.h"

#include <stdio.h>
#include <string.h>

unsigned int braf_OverflowCheck(char *dataPtr, int col, int rw)
{
    if (*dataPtr > 255) {
        braf_displayError("Value overflow. Cell cannot handle ASCII values greater 255.", col, row);
        return 1;
    }

    return 0;
}

unsigned int braf_valUnderflowCheck(char *dataPtr, int col, int rw)
{
    if (*dataPtr < 0) {
        braf_displayError("Value underflow. Cell cannot handle ASCII values less than 0.", col, row);
        return 1;
    }

    return 0;
}

unsigned int braf_tapeOverflowCheck(int currIndex, int col, int rw)
{
    if (currIndex < 1 || currIndex > 30000) {
        char *msg = "Attempting to access non-existent Cell #";
        strcat(msg, currIndex);
        strcat(msg, ". Accessible cells range from Cell #1 to Cell #30,000.")

        braf_displayError(msg, col, rw);
        return 1;
    }

    return 0;
}
