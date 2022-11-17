/**
 * queen.hh
 * ---------------
 * header file for queen
 */

#ifndef NQUEEN_H
#define NQUEEN_H

class nQueen
{
private:
    int *board;       // Array representing game board.
    int size;         // Dimensions of game board, size x size.
    char letters[26]; // Array of letters used for display.

public:
    nQueen(int n);                        // Constructor
    ~nQueen();                            // Destructor
    void solve(int x = 0);                // Returns solutions.
    bool attackable(int column, int row); // Checks for viable queen placement.
    void printQueenCoords();              // Set representation of game board solutions.
    void printPretty();                   // Text representation of game board solutions.
    int solutions;                        // Counts total number of solutions found.
};

#endif
