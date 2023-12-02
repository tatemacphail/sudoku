/*
 * Tate MacPhail
 * Created - Dec 2, 2023 3:20 AM
 *
 */

#include "sudoku.h"
#include <stdlib.h>
#include <assert.h>

int main(int argc, char* argV[]){
    board_t board;
    FILE* input = NULL;

    switch (argc){
        case 1:
            fillBoardManual(&board);
            break;
        case 2:
            input = fopen(argV[1], "r");
            assert(input != NULL);
            fillBoard(&board, input, 0);
            break;
        case 3:
            input = fopen(argV[1], "r");
            assert(input != NULL);
            assert(argV[2][0] == '1' || argV[2][0] == '2');
            fillBoard(&board, input, argV[2][0] - '0');
            break;
        default:
            // TODO: readme instructions
            printf("Invalid arguments, reference readme\n");
            exit(1);
    }

    printBoard(&board);
}