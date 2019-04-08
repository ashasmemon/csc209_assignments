#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Constants that determine that address ranges of different memory regions

#define GLOBALS_START 0x400000
#define GLOBALS_END   0x700000
#define HEAP_START   0x4000000
#define HEAP_END     0x8000000
#define STACK_START 0xfff000000

int main(int argc, char **argv) {
    
    FILE *fp = NULL;

    if(argc == 1) {
        fp = stdin;

    } else if(argc == 2) {
        fp = fopen(argv[1], "r");
        if(fp == NULL){
            perror("fopen");
            exit(1);
        }
    } else {
        fprintf(stderr, "Usage: %s [tracefile]\n", argv[0]);
        exit(1);
    }

    /* Complete the implementation */
    int instr_count = 0;
    int modi_count = 0;
    int loads_count = 0;
    int stores_count = 0;
    // 
    int globals_count = 0;
    int heap_count = 0;
    int stack_count = 0;
    char c1;
    char c2;
    unsigned long hex;

    while (fscanf(fp, "%c%c%lx\n", &c1, &c2, &hex) != EOF) {

        if (c1 == 'I') {
            instr_count++;
        } else if (c1 == 'S') {
            stores_count++;
        } else if ( c1 == 'M') {
            modi_count++;
        } else if (c1 == 'L') {
            loads_count++;
        }
        
        if (hex <= GLOBALS_END && hex >= GLOBALS_START && c1 != 'I') {
            globals_count++;
        } else if (hex >= HEAP_START && hex <= HEAP_END && c1 != 'I') {
            heap_count++;
        } else if (hex >= STACK_START && c1 != 'I') {
            stack_count++;
        }

    }
    fclose(fp);


    /* Use these print statements to print the ouput. It is important that 
     * the output match precisely for testing purposes.
     * Fill in the relevant variables in each print statement.
     * The print statements are commented out so that the program compiles.  
     * Uncomment them as you get each piece working.
     */
    
    printf("Reference Counts by Type:\n");
    printf("    Instructions: %d\n", instr_count);
    printf("    Modifications: %d\n", modi_count);
    printf("    Loads: %d\n", loads_count);
    printf("    Stores: %d\n", stores_count);
    printf("Data Reference Counts by Location:\n");
    printf("    Globals: %d\n", globals_count);
    printf("    Heap: %d\n", heap_count);
    printf("    Stack: %d\n", stack_count);
    

    return 0;
}
