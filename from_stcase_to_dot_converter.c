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
 * States for state machine and initialization
 */
typedef enum {
	s0_START=0,
	s1_Fetch_Next_Word=1,
	s2_Found_TITLE=2,
	s3_Found_NODE=3,
	s4_Found_TRANSITION=4,
	s5_Print_TRANSITION=5,
	s6_Fault=6,
	s7_EXIT=7,
	sm_END=8,
}StateType;
StateType StateMachineActual = s0_START;
/**
 * Structure for the state machine
 */
typedef struct {
	StateType State;
	void (*func)(void);
}StateMachineType;
/**
 * Prototype functions for STATES-FUNCTIONS table
*/
void Fun_s0_START(void);
void Fun_s1_Fetch_Next_Word(void);
void Fun_s2_Found_TITLE(void);
void Fun_s3_Found_NODE(void);
void Fun_s4_Found_TRANSITION(void);
void Fun_s5_Print_TRANSITION(void);
void Fun_s6_Fault(void);
void Fun_s7_EXIT(void);
/**
 * Table with STATES-FUNCTIONS for the state machine
*/
StateMachineType StateMachine[] = {
	{ s0_START,		Fun_s0_START },
	{ s1_Fetch_Next_Word,	Fun_s1_Fetch_Next_Word },
	{ s2_Found_TITLE,	Fun_s2_Found_TITLE },
	{ s3_Found_NODE,	Fun_s3_Found_NODE },
	{ s4_Found_TRANSITION,	Fun_s4_Found_TRANSITION },
	{ s5_Print_TRANSITION,	Fun_s5_Print_TRANSITION },
	{ s6_Fault,		Fun_s6_Fault },
	{ s7_EXIT,		Fun_s7_EXIT }
};
/**
 * Functions for the state machine
 */
void Fun_s0_START(void) {
	//ADD THE CODE HERE!!!
	//StateMachineActual = s0_START;
}
void Fun_s1_Fetch_Next_Word(void) {
	//ADD THE CODE HERE!!!
	//StateMachineActual = 
}
void Fun_s2_Found_TITLE(void) {
	//ADD THE CODE HERE!!!
	//StateMachineActual = 
}
void Fun_s3_Found_NODE(void) {
	//ADD THE CODE HERE!!!
	//StateMachineActual = 
}
void Fun_s4_Found_TRANSITION(void) {
	//ADD THE CODE HERE!!!
	//StateMachineActual = 
}
void Fun_s5_Print_TRANSITION(void) {
	//ADD THE CODE HERE!!!
	//StateMachineActual = 
}
void Fun_s6_Fault(void) {
	//ADD THE CODE HERE!!!
	//StateMachineActual = 
}
void Fun_s7_EXIT(void) {
	//ADD THE CODE HERE!!!
	//StateMachineActual = 
}
/**
 * Run the state machine
 */
void RunStateMachine(void) {
	if(StateMachineActual < sm_END) {
		(*StateMachine[StateMachineActual].func)();
	} else {
		// Fault StateMachine out of range
	}
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
