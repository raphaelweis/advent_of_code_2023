#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_SIZE 3
#define COLOR_SIZE 6

static const int totR = 12;
static const int totG = 13;
static const int totB = 14;

int main(const int argc, char** argv) {
    FILE* f = fopen(argv[argc - 1], "r");

    char c;
    int i = 0, j = 0, id = 1, sum1 = 0, maxR = 0, maxG = 0, maxB = 0;
    char num[NUM_SIZE];
    char token[COLOR_SIZE];
    do {
        c = fgetc(f);

        if (isdigit(c)) {
            num[i++] = c;
            continue;
        }
        if (c == ':') {
            id = atoi(num);
            i = 0, j = 0;
            memset(num, 0, NUM_SIZE * sizeof(char));
            memset(token, 0, COLOR_SIZE * sizeof(char));
            continue;
        }
        if (c == ' ') {
            j = 0;
            memset(token, 0, COLOR_SIZE * sizeof(char));
        }
        if (strstr(token, "red") != NULL) {
            int const current = atoi(num);
            maxR = current > maxR ? current : maxR;
            memset(num, 0, NUM_SIZE * sizeof(char));
            memset(token, 0, COLOR_SIZE * sizeof(char));
            i = 0, j = 0;
        }
        if (strstr(token, "green") != NULL) {
            int const current = atoi(num);
            maxG = current > maxG ? current : maxG;
            memset(num, 0, NUM_SIZE * sizeof(char));
            memset(token, 0, COLOR_SIZE * sizeof(char));
            i = 0, j = 0;
        }
        if (strstr(token, "blue") != NULL) {
            int const current = atoi(num);
            maxB = current > maxB ? current : maxB;
            memset(num, 0, NUM_SIZE * sizeof(char));
            memset(token, 0, COLOR_SIZE * sizeof(char));
            i = 0, j = 0;
        }
        if (c == '\n') {
            printf("Line %d, R = %d, G = %d, B = %d. ", id, maxR, maxG, maxB);
            if (!(maxR > totR || maxG > totG || maxB > totB)) {
                sum1 += id;
                printf(" POSSIBLE\n");
            } else {
                printf(" NOT POSSIBLE\n");
            }
            maxR = 0, maxG = 0, maxB = 0;
        }

        token[j++] = c;
    } while (c != EOF);

    printf("Part 1: %d\n", sum1);

    fclose(f);
    return 0;
}
