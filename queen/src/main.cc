/**
 * Main app to call n-queen
 * ----------
 * usage: ./a.out <number_of_queens>
 * example: ./a.out 8
 * 
 * -------------
 * Copyright: The main solution was written by James Pryor
 * I modified it to use in my class
 * 
 * Sina
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "queen.hh"

using namespace std;

int main(int argc, char **argv)
{

    if (argc < 0)
        abort;

    if (argc != 2)
    {
        cerr << "Usage: ./" << argv[1] << " Number_of_queens" << endl;
        cerr << "Default is 8 Queens";
    }

    int n = 8;
    if (argv[1] != NULL)
    {
        n = atoi(argv[1]);
        if (n > 20)
        {
            cout << "Try a number less than 20." << endl;
            return EXIT_FAILURE;
        }
    }

    // Start timer
    clock_t start, end;
    start = clock();

    nQueen solutions(n);
    solutions.solve();

    // stop timeer and output results.
    end = clock();
    cout << endl
         << "Found " << solutions.solutions << " for " << n << "x" << n << " board";
    cout << " in " << ((float)end - start) / CLOCKS_PER_SEC << " seconds." << endl
         << endl;

    return 0;
}
