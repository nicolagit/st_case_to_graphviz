#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * Structure of a word
 */
typedef struct word {
	int pos;
	char *text;
	struct word *prev, *next;
} word;

/**
 * Create a new word from the original "word" structure
 */
word* create(int pos, char *text, word *prev) {
	word *w = malloc(sizeof(word));
	w->pos = pos;
	w->text = strdup(text);
	w->prev = prev;
	return w;
}

/**
 * Create a linked list from the file content
 */
word* readfile(FILE *in_file){
	word *start=NULL, *w=NULL, *prev=NULL, *next=NULL;
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
	return start;
}

/**
 * M A I N
 */
int main(int argc, char *argv[]) {
	FILE *in_file;
	word *startword;
	// Open the input file (with a basic sanity check)
	if (argc != 2) {
		fprintf(stderr, "Provide the name of the file\n");
		return 1;
	}
	in_file = fopen(argv[1], "r");
	if (in_file == NULL) {
		fprintf(stderr, "Can't open the file\n");
		return 1;
	}

	// Create a linked list from the file content and close the file
	startword = readfile(in_file);	
	fclose(in_file);
}
