#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char numbers[10][6] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine",};

int main(const int argc, char** argv) {
    FILE* f = fopen(argv[argc - 1], "r");
    char c, str[10], str2[10], num[100];
    int i = 0, j = 0, k = 0, sum1 = 0, sum2 = 0;
    do {
        c = fgetc(f);
        if (c == '\n') {
            char n[3];
            n[0] = str[0];
            n[1] = str[i - 1];
            n[2] = '\0';
            sum1 += atoi(n);
            n[0] = str2[0];
            n[1] = str2[j - 1];
            sum2 += atoi(n);
            i = 0, j = 0, k = 0;
            continue;
        }
        if (!isdigit(c)) {
            num[k] = c;
            k++;
            for (int l = 0; l < sizeof(numbers) / sizeof(numbers[0]) - 1; l++) {
                if (strstr(num, numbers[l]) != NULL) {
                    str2[j] = l + 1 + '0';
                    j++;
                    k = 1;
                    memset(num, 0, strlen(num));
                    num[0] = c; // to avoid stuff like oneight not being recognized correctly.
                    break;
                };
            }
            continue;
        };
        str[i] = c;
        str2[j] = c;
        i++, j++;
    } while (c != EOF);
    printf("Part 1: %d\n", sum1);
    printf("Part 2: %d\n", sum2);
    return 0;
}
