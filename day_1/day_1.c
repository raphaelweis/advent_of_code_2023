#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char numbers[10][6] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine",};

int main(const int argc, char** argv) {
    FILE* f = fopen(argv[argc - 1], "r");
    char c, str[10], num[100];
    int i = 0, j = 0, sum = 0;
    do {
        c = fgetc(f);
        if (c == '\n') {
            char n[3];
            n[0] = str[0];
            n[1] = str[i - 1];
            n[2] = '\0';
            sum += atoi(n);
            i = 0, j = 0;
            continue;
        }
        if (!isdigit(c)) {
            num[j] = c;
            j++;
            for (int k = 0; k < sizeof(numbers) / sizeof(numbers[0]) - 1; k++) {
                if (strstr(num, numbers[k]) != NULL) {
                    str[i] = k + 1 + '0';
                    i++;
                    j = 1;
                    memset(num, 0, strlen(num));
                    num[0] = c; // to avoid stuff like oneight not being recognized correctly.
                    break;
                };
            }
            continue;
        };
        str[i] = c;
        i++;
    } while (c != EOF);
    printf("Sum: %d\n", sum);
    return 0;
}
