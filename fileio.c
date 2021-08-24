#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "startScreen_main.h"
#include "fileio.h"

void outputTotal(char rule[]) {
	FILE* fp = fopen(rule, "r");
	char buffer[4000] = { 0, };

	fread(buffer, 1, 4000, fp);
	printf("%s", buffer);

	fclose(fp);
}

void outputLine(int x, int y, int x_plus, int y_plus, char text[]) {
	FILE* fp = fopen(text, "r");

	while (1) {
		char arr[1000];

		char* p = fgets(arr, 1000, fp);

		if (p == NULL) {
			break;
		}

		printfXY(x + x_plus, y + y_plus, arr);

		x += x_plus;
		y += y_plus;
	}

	fclose(fp);
}