#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define BUFSIZE 1000
#define STRSIZE 2

int main(void) {
	FILE* filep;

   	filep = fopen("input.txt", "r");

	char strings[1000][3];
	char c;
	for (int i = 0; i < 1000; i++) {
		int j = 0;
		char tempstr[10];
		do {
			c = fgetc(filep);
			if (isdigit(c)) {
				tempstr[j] = c;
				j++;
			}
		} while (c != '\n');
		tempstr[j] = '\0';
		
		strings[i][0] = tempstr[0];

		int length = strlen(tempstr) - 1;
		strings[i][1] = tempstr[length];
		strings[i][2] = '\0';
	}


	int sum = 0;
	for (int k = 0; k < 1000; k++) {
		sum += atoi(strings[k]);
	}

	printf("%d\n", sum);
	return 0;
}
