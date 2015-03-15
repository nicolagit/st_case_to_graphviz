#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
	FILE *in_file, *out_file;
	char string[100];
	int posread=0, poswrite=0, length=10000;
	struct word {
		int pos;
		char word[100];
	};
	struct word words[length];
		
	in_file=fopen(argv[1], "r");
	out_file=fopen("output.txt", "w");
	while (fscanf(in_file, "%s", &string) == 1) {
		posread = posread + 1;
		words[posread].pos = posread;
		strcpy(words[posread].word, string);
	}
	for(poswrite=0; poswrite<posread; poswrite++) {
		fprintf(out_file, "%i, %s\n", words[poswrite+1].pos, words[poswrite+1].word);
	}
}
