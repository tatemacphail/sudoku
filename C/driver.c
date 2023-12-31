/*
 * Tate MacPhail
 * Created - Dec 2, 2023 3:20 AM
 *
 */

#include "sudoku.h"
#include <stdlib.h>
#include <assert.h>

void runMenu(int* printToggle, board_t* board);
void processMenuInput(char input, board_t* board, int* printToggle);

int main(int argc, char* argV[]){
    board_t board;
    FILE* input = NULL;
    // construct board
    switch (argc){
        case 1:
            fillBoardManual(&board);
            break;
        case 2:
            input = fopen(argV[1], "r");
            assert(input != NULL);
            fillBoard(&board, input, 0);
            fclose(input);
            break;
        case 3:
            input = fopen(argV[1], "r");
            assert(input != NULL);
            assert(argV[2][0] == '0' || argV[2][0] == '1');
            fillBoard(&board, input, argV[2][0] - '0');
            fclose(input);
            break;
        default:
            // TODO: readme instructions
            printf("Invalid arguments, reference readme\n");
            exit(1);
    }
    printBoard(&board);

    // gameplay loop
    int menuToggle = 1;
    while (!checkForWin(&board)){
        runMenu(&menuToggle, &board);
    }
    printf("You Win! Congrats! Here is your solved puzzle:\n");
    printBoard(&board);
}

void runMenu(int* printToggle, board_t* board){
    char input;
    if (*printToggle){
        printf("------------------------------\n"
               "Welcome to sudoku! Choose one:\n"
               "  c. Change a position\n"
               "  p. Print board\n"
               "  m. Print menu\n"
               "  t. Toggle menu reprinting\n"
               "  s. Save board to file\n"
               "  q. Exit Game\n"
               "------------------------------\n");
    }
    input = getchar();
    // clear line
    while (getchar() != '\n');
    processMenuInput(input, board, printToggle);
}

void processMenuInput(char input, board_t* board, int* printToggle){
    int row = 0, col = 0;
    char val = '\0';
    char saveFile[80] = "saves/";
    switch (input){
        case 'c': //TODO: validate input or get better system
            do {
                printf("Row [1-9]: ");
                row = getchar() - '0';
                while (getchar() != '\n');
                printf("Col [1-9]: ");
                col = getchar() - '0';
                while (getchar() != '\n');
                if (!checkPosModifiable(board, row, col))
                    printf("Position cannot be changed!\n");
            } while (!checkPosModifiable(board, row, col));
            printf("Value [0-9]: ");
            val = getchar();
            while (getchar() != '\n');
            printf("%c\n", val);
            changePos(board, row, col, val);
            return;
        case 'p':
            printBoard(board);
            return;
        case 'm':
            printf("\n------------------------------\n"
                   "Welcome to sudoku! Choose one:\n"
                   "  c. Change a position\n"
                   "  p. Print board\n"
                   "  m. Print menu\n"
                   "  t. Toggle menu reprinting\n"
                   "  s. Save board to file (\"By Character\" format)\n"
                   "  q. Exit Game\n"
                   "------------------------------\n");
            return;
        case 't':
            *printToggle = !(*printToggle);
            return;
        case 's':
            printf("File Name: ");
            scanf("%[^\n]s", saveFile+6);
            getchar(); // clear \n
            // write to 'saves/[filename]'
            FILE* out = fopen(saveFile, "w");
            assert(out != NULL);
            for (row = 0; row < 9; row++) {
                for (col = 0; col < 9; col++) {
                    fputc(board->values[row][col], out);
                }
            }
            fclose(out);
            printf("Game state saved to %s.\n", saveFile);
            return;
        case 'q':
            exit(1);
        default:
            printf("Invalid input.\n");
            return;
    }
}

