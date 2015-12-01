#ifndef ERROR_CHECK_H
    #define ERROR_CHECK_H
        unsigned int braf_valOverflowCheck(const char *dataPtr, const int col, const int rw);
        unsigned int braf_valUnderflowCheck(const char *dataPtr, const int col, const int rw);
        unsigned int braf_tapeAccessCheck(const int currIndex, const int col, const int rw);
#endif
