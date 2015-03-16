#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


FILE *in_file;

typedef struct word {
	int pos;
	char *text;
	struct word *prev;
	struct word *next;
} word;

word* create(int pos, char *text, word *prev) {
	word *w = malloc(sizeof(word));
	w->pos = pos;
	w->text = strdup(text);
	w->prev = prev;
	return w;
}

void readfile(FILE *in_file){
	word *start = NULL;
	word *w = NULL;
	word *prev = NULL;
	word *next = NULL;
	char string[150];
	int posread=1;
	for (; fscanf(in_file, "%s", &string) == 1; w=next) {
		next = create(posread, string, w);
		posread = posread + 1;
		if (start == NULL)
			start = next;
		if (w != NULL)
			w->next = next;
	}
}

int main(int argc, char *argv[]) {

	// Open the input file (with sanity check)
	if (argc != 2) {
		fprintf(stderr, "Provide the name of the file to parse\n");
		return 1;
	}
	in_file = fopen(argv[1], "r");
	if (in_file == NULL) {
		fprintf(stderr, "Can't open the file");
		return 1;
	}

	// Create a linked list from the file contect
	readfile(in_file);	

	// Close files and free up memory
	fclose(in_file);
}
