/*
Name: Stephen Mutinda Mutua 
Registration number: CT101/G/26532/25
Unit: Introduction To Programming And Problem Solving 
Description: A program to display a 2D array given.
*/
#include <stdio.h>// standard input output library 

int main () {// main function 
    
    // variable declaration, declare the array
    int scores[2][2][2] = {
        {{65,92},{84,72}},
        {{35,70},{59,67}}
        };
    int s;//loop ya kwanza
    int g;//loop 2
    int r;// loop 3
    
    //use a for loop to print 
        for (s = 0; s < 2; s++) {
            for (g = 0; g < 2; g++) { 
                for (r = 0; r < 2; r++) {
        printf("%d ", scores[s][g][r]);
                }
                printf("\n");
            }
            printf("\n");
        }
        return 0;
}
