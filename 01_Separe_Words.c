#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
	FILE *in_file;
	FILE *out_file;
	char string[100];

	in_file=fopen(argv[1], "r");
	out_file=fopen("output.txt", "w");
	while (fscanf(in_file, "%s", &string) == 1) {
		fprintf(out_file, string);
		fprintf(out_file, "\n");
	}
}
