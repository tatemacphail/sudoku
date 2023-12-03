/*
 * Tate MacPhail
 * Created - Dec 3, 2023 4:25 AM
 *
 */

#ifndef SUDOKU_SOLVE_H
#define SUDOKU_SOLVE_H

#include "sudoku.h"

/*
 * Brute force by checking all numbers in each position
 * until the board is solved (lol)
 *
 * PARAMS:
 *      board - pointer to the board to solve
 * PRE:
 *      board != NULL && [board was filled] &&
 *      [board has a solution]
 * POST:
 *      board unchanged && solved board printed to terminal
 */
void bruteSolve(board_t* board);

#endif
