#ifndef LOGGER_H
#define LOGGER_H
#include <stdio.h>

FILE* log_init(char* filename);
int logcat(FILE* log_file, char* message);
int log_close(FILE* log_file);

#endif
