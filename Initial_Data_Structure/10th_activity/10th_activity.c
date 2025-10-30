#include <stdlib.h> 
#include <stdio.h>
#include <stdbool.h>
#include "mergeSort.h"
/*variables*/


/*VARIABLES*/
/*void FUNCTIONS*/
void CharIntoList();
/*VOID FUNCTIONS*/
int main(){
    int binaryLevels = 2^4;
    int fullTree[binaryLevels];
    int A = 1; int B = 9; int C = 2; int D = 13; int E = 3; int F = 10; int G = 15; int H = 11; int I = 14; int J = 12;
    /*

                            G
                D                           I                 
        B               F           H               J
    A       C       E       X   X       X        X     X
    
                                                    */
    int firstVars[10] = {A, B, C, D, E, F, G, H, I, J}; /*THIS WILL HELP TO KEEP TRACK OF THE INITIAL DEFINITION OF THE TREE*/
    printf("\n\nWelcome to this binary-trees program.\nWe will create a new tree based of the next variables.");
    /*Using the mergeSort method to find the positions in which the binary tree will need to be sorted*/
    return 0;
}
void CharIntoList(){

}