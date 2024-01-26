#include <stdlib.h>
#include <iostream>
#include "functions.h"

using std::cout, std::endl;

int main()
{
    int rows = 50;
    int cols = 200;
    life **board = nullptr;
    life **newGenBoard = nullptr;
    board = create2Darry(rows, cols);
    newGenBoard = create2Darry(rows, cols);

    int generations = 1000;

    populateArry(board, rows, cols);
    populateArry(newGenBoard, rows, cols);

    printArray(board, rows, cols);

    while(generations > 0)
    {
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                checkLife(board, newGenBoard, i, j, rows, cols);
            }
        }

        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                board[i][j].alive = newGenBoard[i][j].alive;
            }
        }

        cout << "Generation " << 1001-generations << endl;

        printArray(board, rows, cols);
        generations--;
    }

    delete2Darry(board, rows);
    delete2Darry(newGenBoard, rows);

    return 0;
}