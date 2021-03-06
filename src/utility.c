#include <stdlib.h>
#include <string.h>
#include <stdio.h>


void clean(char *str);

int safe_input(char *str, int length);

void purge();


void get_hour_minute_time(int t, char *output);

int get_minute_time(char *time);


void purge() {
    int c;

    while ((c = getchar()) != '\n' && c != EOF) {}
}

void clean(char *str) {
    char *p = strchr(str, '\n');

    if (p) {
        *p = 0;
    } else {
        purge();
    }
}

int safe_input(char *str, int length) {
    char *endPosition = NULL;

    if (fgets(str, length, stdin) != NULL) {
        endPosition = strchr(str, '\n');
        if (endPosition != NULL) {
            *endPosition = '\0';
        }
        clean(str);
        return 1;
    } else {
        return 0;
    }
}

void get_hour_minute_time(int t, char *output) {
    // Output a time in the HHMM format from t in minutes.

    int minutes = t % 60;
    int hours = t / 60;
    snprintf(output, sizeof(output), "%02d%02d", hours, minutes);
    output[4] = '\0';
}

int get_minute_time(char *time) {
    // Return a time in minutes, from HHMM

    return (time[3] - '0') + 10 * (time[2] - '0') + 60 * (time[1] - '0') + 600 * (time[0] - '0');
}



