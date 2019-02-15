//
//  Sodoku.cpp
//  Sodoku Solver
//
//  Created by Sean Tesch on 1/24/17.
//  Copyright © 2017 Sean Tesch. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "sudoku.h"
using namespace std;

Sudoku::Sudoku()
{
    int i, j;
    
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
            setElement(i,j,0);
    }
}

Sudoku::~Sudoku()
{
}

int Sudoku::getElement(int x, int y)
{
    if (x >= 0 && x < 9 && y >= 0 && y < 9)
        return(puzzle[x][y]);
    else
    {
        cout << "Sudoku::getElement - Requested array element does not exist";
        cout  << endl;
        return(0);
    }
}

void Sudoku::setElement(int x, int y, int value)
{
    if (x >= 0 && x < 9 && y >= 0 && y < 9)
        puzzle[x][y] = value;
    else
    {
        cout << "Sudoku::setElement - Requested array element does not exist";
        cout  << endl;
    }
}

bool Sudoku::solve()
{
    int row, col;
    if (!findOpenCell(row, col))
        return true;
    for (int digit = 1; digit <= 9; digit++)
    {
        if (!rowGood(row, digit) && !colGood(col, digit) && !squareGood(row - row % 3, col - col % 3, digit))
        {
            puzzle[row][col] = digit;
            if (solve())
                return true;
            puzzle[row][col] = 0;
        }
    }
    return false;
}

bool Sudoku::rowGood(int row, int guess)
{
    for (int col = 0; col < 9; col++)
        if (getElement(row, col) == guess)
            return true;
    return false;
}

bool Sudoku::colGood(int col, int guess)
{
    for (int row = 0; row < 9; row++)
        if (getElement(row, col) == guess)
            return true;
    return false;
}

bool Sudoku::squareGood(int boxRow, int boxCol, int guess)
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (getElement(row + boxRow, col + boxCol) == guess)
                return true;
    return false;
}

void Sudoku::fillPuzzle(ifstream &infile)
{
    int i,j,value;
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
        {
            infile >> value;
            setElement(i,j,value);
        }
    }
}

void Sudoku::printPuzzle()
{
    int i, j;
    
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
            cout << getElement(i,j) << " ";
        cout << endl;
    }
}

bool Sudoku::findOpenCell(int &row, int &col)
{
    for (row = 0; row < 9; row++)
        for (col = 0; col < 9; col++)
            if (getElement(row, col) == 0)
                return true;
    return false;
}
