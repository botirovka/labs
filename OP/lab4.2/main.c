#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int main() {
    char str[500];
    char *limits = " ,.-",*w;
        printf("Enter your sentence: \n");
    gets(str);
    if (str[strlen(str) - 1] == '.') {
        w = strtok(str, limits);
        while (w != NULL) {
            if (strlen(w) > 8) {
                printf("%s\n", w);
            }
            w = strtok(NULL, limits);
        }
    }
    else {
        printf("Error");
    }
        return 0;
    }
