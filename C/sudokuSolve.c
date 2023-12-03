/*
 * Tate MacPhail
 * Created - Dec 3, 2023 4:31 AM
 *
 */

#include "sudoku.h"
#include "sudokuSolve.h"
#include <stdio.h>

int main(int argc, char* argV[]){
    if (argc != 3){
        printf("Invalid # of args, see readme\n"); //TODO: make a darn readme
        exit(1);
    }

    // process input
    board_t* board;
    FILE* input = fopen(argV[1], "r");
    assert(input != NULL);
    switch (argV[2][0]){
        case '0':
        case '1':
            fillBoard(board, input, argV[2][0] - '0');
            fclose(input);
        default:
            printf("Invalid input format selected\n");
            exit(1);
    }

    bruteSolve(board);
    printBoard(board);
}

void bruteSolve(board_t* board){
    // this is a logistical nightmare. its bed time.
}