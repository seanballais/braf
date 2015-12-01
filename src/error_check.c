#include "error_check.h"
#include "util.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

unsigned int braf_valOverflowCheck(const char *dataPtr, const int col, const int rw)
{
    int dataVal = *dataPtr;
    if (dataVal > 255) {
        braf_displayErrorInInterpreter("Value overflow. Cell cannot handle ASCII values greater 255.", col, rw);
        return 1;
    }

    return 0;
}

unsigned int braf_valUnderflowCheck(const char *dataPtr, const int col, const int rw)
{
    int dataVal = *dataPtr;
    if (dataVal < 0) {
        braf_displayErrorInInterpreter("Value underflow. Cell cannot handle ASCII values less than 0.", col, rw);
        return 1;
    }

    return 0;
}

unsigned int braf_tapeAccessCheck(const int currIndex, const int col, const int rw)
{
    if (currIndex < 1 || currIndex > 30000) {
        char *msg = NULL;
        strcat(msg, "Attempting to access non-existent Cell #");
        strcat(msg, braf_toString(currIndex));
        strcat(msg, ". Accessible cells range from Cell #1 to Cell #30,000.");

        braf_displayErrorInInterpreter(msg, col, rw);
        return 1;
    }

    return 0;
}
