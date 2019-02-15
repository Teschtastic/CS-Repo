//
//  main.cpp
//  Sodoku Solver
//
//  Created by Sean Tesch on 1/24/17.
//  Copyright © 2017 Sean Tesch. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "sudoku.h"

using namespace std;

int main(int argc, char *argv[])
{
    ifstream input_file;
    int valid, i, j;
    Sudoku puzzle;
    
    if (argc == 2)
    {
        input_file.open(argv[1]);
        if (input_file.fail())
        {
            cout << "Unable to open input file " << argv[1] << endl;
            exit(-1);
        }
    }
    else
    {
        cout << "Incorrect number of parameters\nUsage: " << argv[0] << " <input filename>" << endl;
        exit(-1);
    }
    
    puzzle.fillPuzzle(input_file);
    input_file.close();
    
    cout << "Puzzle to Solve:" << endl;
    puzzle.printPuzzle();
    if (puzzle.solve())
    {
        cout << "Solution found:" << endl;
        puzzle.printPuzzle();
    }
    else
        cout << "Puzzle is unsolvable!" << endl;
    
}
