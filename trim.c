#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* Reads a trace file produced by valgrind and an address marker file produced
 * by the program being traced. Outputs only the memory reference lines in
 * between the two markers
 */

int main(int argc, char **argv) {
    
    if(argc != 3) {
         fprintf(stderr, "Usage: %s tracefile markerfile\n", argv[0]);
         exit(1);
    }

    // Addresses should be stored in unsigned long variables
    // unsigned long start_marker, end_marker;

    unsigned long start_marker;
    unsigned long end_marker;
    char *trace_file = argv[1];
    char *marker_file = argv[2];
    FILE *trace_ptr = NULL;
    FILE *marker_ptr = NULL;

    trace_ptr = fopen(trace_file, "r");
    marker_ptr = fopen(marker_file, "r");
    

    fscanf(marker_ptr, "%lx %lx\n", &start_marker, &end_marker);
    
    int keep_going = 0;
    char c1;
    char c4;
    unsigned long hex;
    int dig;

    while (fscanf(trace_ptr,"%c%lx%c%d\n", &c1, &hex, &c4, &dig) != EOF) {

        if (keep_going > 0) {
            keep_going++;
        }
        if (hex == start_marker) {
            keep_going++;
        } else if (hex == end_marker) {
            keep_going = 0;
        }
        if (keep_going > 1) {
            printf("%c,%#lx\n", c1, hex);
        }
    }

    fclose(marker_ptr);
    fclose(trace_ptr);


    /* For printing output, use this exact formatting string where the
     * first conversion is for the type of memory reference, and the second
     * is the address
     */
    // printf("%c,%#lx\n", VARIABLES TO PRINT GO HERE);

    return 0;
}
