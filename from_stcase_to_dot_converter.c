#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char *output_file_name = "output.dot";
struct transition {
	int number;
	char *start;
	char *end;
	char *comment;
};


char* find_string_between(char *left, char *right, FILE *file){
	char string[100];
	char string0[100];
	char string1[100];
	char string2[100];
	char *graph_name = malloc(sizeof(string));
	while (fscanf(file, "%s", &string) == 1) {
		strcpy(string2, string1);
		strcpy(string1, string0);
		strcpy(string0, string);
		if (strcmp(string2,left)==0 && (strcmp(string0,right)==0)) {
			strcpy(graph_name, string1);
			break;
		}
	}
	return graph_name;
}


char* find_nodes(FILE *file) {
	char string[100]; last[2];
	struct node {
		char *name;
		struct node *next;
	};
	while (fscanf(file, "%s", &string) ==1) {
		//Fetch last char of each word
		for (i=0; i<2; i++) {
			last[i] = string[strlen(string)-(1-i)];
		}
		if (strcmp(last, ":") == 0) {
			strcpy(node, string);
	}

	char *nodes_list = malloc(sizeof(node));
}


//void print_output_file(){
//	printf(out_file, "text");
//}


int main(int argc, char *argv[]) {
	FILE *in_file;
	FILE *out_file;
	char *graph_name;

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

	// Fetch the name of the graph from the case's statement
	graph_name = find_string_between("CASE", "OF", in_file);

	// Generates a list of nodes from the format "NAME:"
	node = find_nodes(in_file);

	// Create the output file
	out_file = fopen(output_file_name, "w");
	fprintf(out_file,graph_name);

	// Close files and free up memory
	fclose(in_file);
	fclose(out_file);
	free(graph_name);

}
