/**
 * queen.cc
 */

#include <iostream>
#include "queen.hh"

/**
 * Constructor
 */
nQueen::nQueen(int n)
{
    // Set up game board variables.
    size = n;
    board = new int[size];
    for (int i = 0; i < size; i++)
    {
        board[i] = 0;
    }

    char temp[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                   'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    for (int i = 0; i < 26; i++)
    {
        letters[i] = temp[i];
    }

    // No solutions yet.
    solutions = 0;
}

/**
 * Destructor
 */
nQueen::~nQueen()
{
    delete board;
}

/**
 * Determines if a position is attackable by a queen already placed. The function only needs to
 * detect attacks from queens in rows above. Left and right is taken care of by the solve function,
 * only checking a single row at a time.
 * I thought it would be slick to have an if condition for the up direction and another for
 * diagonals, but I could not get the diagonal detection to work without using two if conditions.
 *
 * @param column integer    The x-coordinate of spot to check.
 * @param row    integer    The y-coordinate of spot to check.
 */
bool nQueen::attackable(int column, int row)
{
    for (int i = 0; i < column; i++)
    {
        //  strait above       negative slope, above             positive slope, above
        if (board[i] == row || board[i] == row - (column - i) || board[i] == row + (column - i))
        {
            /* if(board[i] == board[column] || abs(board[column]-board[i]) == column - i) { */
            return true;
        }
    }
    return false;
}

/**
 * Recursively solves the queen placement one row at a time for board size.
 *
 * @param x integer     Column controlled by the recursion.
 */
void nQueen::   solve(int x)
{
    if (x == size)
    {
        std::cout << std::endl
                  << "  Solution " << ++solutions << std::endl;
        if (solutions < 10)
        {
            std::cout << "  ----------" << std::endl;
        }
        else
        {
            std::cout << "  -----------" << std::endl;
        }
        printPretty();
    }
    else
    {
        // x represents the column, i represents the row
        for (int i = 0; i < size; i++)
        {
            if (!attackable(x, i))
            {
                board[x] = i;
                solve(x + 1);
            }
        }
    }
}

/**
 * Prints a set of human readable coordinates for queen locations. Used at the end of prettyPrint(),
 * but could be useful for implementing a smaller, but still easy to read, output.
 */
void nQueen::printQueenCoords()
{
    std::cout << "  Queen Coordinates = {";
    for (int i = 0; i < size; i++)
    {
        if (i < size - 1)
        {
            std::cout << "(" << i + 1 << ", " << letters[board[i]] << "), ";
        }
        else
        {
            std::cout << "(" << i + 1 << ", " << letters[board[i]] << ")}" << std::endl
                      << std::endl;
        }
    }
}

/**
 * Print whole game board, makes for giant files when text output is saved. The standard chessboard
 * letter and number coordinate system is used, it is doubtful anyone will ever solve 27x27 or
 * higher.
 */
void nQueen::printPretty()
{
    // column marker across top
    std::cout << std::endl
              << "    ";
    for (int i = 0; i < size; i++)
    {
        std::cout << "  " << letters[i] << " ";
    }

    // top of board
    std::cout << std::endl
              << "    +";
    for (int i = 0; i < size; i++)
    {
        std::cout << "---+";
    }

    // for each row
    for (int i = 0; i < size; i++)
    {
        // row marker on left
        if (i < 9)
        {
            std::cout << std::endl
                      << "  " << i + 1 << " | ";
        }
        else
        {
            std::cout << std::endl
                      << " " << i + 1 << " | ";
        }

        // board contents
        for (int j = 0; j < size; j++)
        {
            if (board[i] == j)
            {
                if (j < 9)
                {
                    std::cout << "Q | ";
                }
                else if (j < 99)
                {
                    std::cout  << "Q| ";
                }
                else
                {
                    std::cout << "Q|"; // doubt we'll ever need this.
                }
            }
            else
            {
                std::cout << "  | ";
            }
        }

        // line between contents
        std::cout << std::endl
                  << "    +";
        for (int k = 0; k < size; k++)
        {
            std::cout << "---+";
        }
    }
    std::cout << std::endl
              << std::endl;
    printQueenCoords();
}
