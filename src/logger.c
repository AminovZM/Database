#include "logger.h"

#include <stdio.h>
#include <string.h>
#include <time.h>

/*
int main() {
    FILE *file = log_init("file.log");

    char message[100] = "99";
    logcat(file, message);
    log_close(file);

    return 0;
}
*/

FILE *log_init(char *filename) {
    FILE *f;
    f = fopen(filename, "a");

    return f;
}

int log_close(FILE *log_file) { return fclose(log_file); }

int logcat(FILE *log_file, char *message) {
    time_t currentTime = time(NULL);
    char timeString[9];  // "HH:MM:SS\0"
    strftime(timeString, sizeof(timeString), "%H:%M:%S", localtime(&currentTime));

    char result[100];
    strncpy(result, timeString, sizeof(result) - sizeof(timeString));
    strncat(result, " ", sizeof(result) - strlen(result) - 1);
    strncat(result, message, sizeof(result) - strlen(result) - 1);

    fprintf(log_file, "%c", '\n');
    fprintf(log_file, "%s", result);
    return 0;
}
