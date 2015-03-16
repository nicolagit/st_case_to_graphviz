#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


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

void printlist(word *start) {
	word *w= start;
	for (; w != NULL ; w = w->next) {
		printf("Pos: %i, Word: %s\n", w->pos, w->text);
		printf("Size: %i\n", strlen(w->text));
		printf("Pointer prev: %i", w->prev);
		printf("Pointer next: %i\n\n", w->next);
	}
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
	printlist(start); //replace this function with the scraper
}

int main(int argc, char *argv[]) {
	FILE *in_file;
	in_file=fopen(argv[1], "r");
	readfile(in_file);
}
