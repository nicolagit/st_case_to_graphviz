#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
	FILE *in_file, *out_file;
	char string[100], last[2];
	int i;

	in_file=fopen(argv[1], "r");
	out_file=fopen("output.txt", "w");
	while (fscanf(in_file, "%s", &string) == 1) {
		for (i=0; i<2; i++) {
			last[i] = string[strlen(string) - (1-i)];
		}
		fprintf(out_file, last);
		fprintf(out_file, "\n");
	}
}
