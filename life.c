#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void print_state(char *state, int size);
void update_state(char *state, int size);


int main(int argc, char **argv) {

    if (argc != 3) {
    	fprintf(stderr, "Usage: USAGE: life initial n\n");
    	return 1;
    }

    int size = strlen(argv[1]);
    int total_reps = strtol(argv[2], NULL, 10);
    char *state;
    state = argv[1];

    // loop thru total_reps times to get the new states of the game.
    for (int i = 0; i != total_reps; i++) {
        print_state(state, size);
        update_state(state, size);
    }
    
    // TODO: complete the main function

}