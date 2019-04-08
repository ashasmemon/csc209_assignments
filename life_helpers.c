#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void print_state(char *ch, int size) {
    /**
     * Take in a char array ch and its size and return void.
     * Print the char array and then the new line character
     * 
     */

    printf("%s", ch);
    printf("\n");

}

void update_state(char *ch, int size) {
    /**
     * Take in a char array and its size and return void. 
     * Update the state of the array according to the rules of the game.
     * 
     */

    char arr[size - 2];

    for (int i = 1; i < size - 1; i++){
        int before = i - 1;
        int after = i + 1;
        char x = 'X';
        char dot = '.';

        if (ch[before] == ch[after]) {
            arr[i - 1] = dot;
            // *(ch + i) = dot;
            //ch[i] = ".";
        } else {
            arr[i - 1] = x;
            // *(ch + i) = x;
            // ch[i] = "X";
        }
    } 
    for (int j = 0; j < size - 2; j++) {
        ch[j + 1] = arr[j];
    }

}