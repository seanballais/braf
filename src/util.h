#ifndef UTIL_H
    #define UTIL_H
        void braf_displayError(const char *msg);
        void braf_displayErrorInArguments(const char *msg, const char *arg);
        void braf_displayErrorInInterpreter(const char *msg, const int col, const int rw);
        void braf_displayHelp(void);
        void braf_displayInfo(void);
        unsigned int braf_fileExists(const char *fileName);
        char* braf_toString(int num);
        char* cs50_GetString(void);
#endif
