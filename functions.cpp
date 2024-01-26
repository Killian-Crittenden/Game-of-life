#include <stdlib.h>
#include <iostream>
#include <time.h> 
#include "functions.h"

using std::cout, std::endl;

life **create2Darry(int rows, int cols)
{
    life **array = new life *[rows] {};
    for(int i = 0; i < rows; i++)
    {
        array[i] = new life[cols];
    }

    return array;
}

void delete2Darry(life**& ary, int rows)
{
    for(int i = 0; i < rows; i++)
    {
        delete [] ary[i];
    }
    delete [] ary;
}

void populateArry(life**& ary, int rows, int cols)
{
    srand(time(NULL));
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            if((rand()%2) == 0)
            {
                ary[i][j].alive = false;
            }
            else{
                ary[i][j].alive = true;
            }
        }
    }
}

void checkLife(life**& ary, life**& newAry, int row, int col, int maxRow, int maxCol)
{
    int numAlive = 0;

    // check if the point is the top left corner
    if(row == 0 && col == 0)
    {
        // point to the right
        if(ary[row][col+1].alive == true)
        {
            numAlive++;
        }
        // point above
        if(ary[row+1][col].alive == true)
        {
            numAlive++;
        }
        // point to the bottom right
        if(ary[row+1][col+1].alive == true)
        {
            numAlive++;
        }
    }
    // check if the point is the top right corner
    else if(row == 0 && col == maxCol-1)
    {
        // point to the left
        if(ary[row][col-1].alive == true)
        {
            numAlive++;
        }
        // point bottom left
        if(ary[row+1][col-1].alive == true)
        {
            numAlive++;
        }
        // point below
        if(ary[row+1][col].alive == true)
        {
            numAlive++;
        }
    }
    // checck if the point is the bottom left corner
    else if(row == maxRow-1 && col == 0)
    {
        // point right
        if(ary[row][col+1].alive == true)
        {
            numAlive++;
        }
        // point above
        if(ary[row-1][col].alive == true)
        {
            numAlive++;
        }
        // point top right
        if(ary[row-1][col+1].alive == true)
        {
            numAlive++;
        }
    }
    // check if the point is the bottom right corner
     else if(row == maxRow-1 && col == maxCol-1)
    {
        // point above
        if(ary[row-1][col].alive == true)
        {
            numAlive++;
        }
        // point to the left
        if(ary[row][col-1].alive == true)
        {
            numAlive++;
        }
        // point to the top left
        if(ary[row-1][col-1].alive == true)
        {
            numAlive++;
        }
    }
    else if(row == 0)
    {
        // point right
        if(ary[row][col+1].alive == true)
        {
            numAlive++;
        }
        // point below
        if(ary[row+1][col].alive == true)
        {
            numAlive++;
        }
        // point bottom right
        if(ary[row+1][col+1].alive == true)
        {
            numAlive++;
        }
        // point left
        if(ary[row][col+1].alive == true)
        {
            numAlive++;
        }
        // point bottom left
        if(ary[row+1][col-1].alive == true)
        {
            numAlive++;
        }
    }
    else if(row == maxRow-1)
    {
        // point above
        if(ary[row-1][col].alive == true)
        {
            numAlive++;
        }
        // point right
        if(ary[row][col+1].alive == true)
        {
            numAlive++;
        }
        // point top right
        if(ary[row-1][col+1].alive == true)
        {
            numAlive++;
        }
        // point left
        if(ary[row][col-1].alive == true)
        {
            numAlive++;
        }
        // point top left
        if(ary[row-1][col-1].alive == true)
        {
            numAlive++;
        }
    }
    else if(col == 0)
    {
        // point right
        if(ary[row][col+1].alive == true)
        {
            numAlive++;
        }
        // point above
        if(ary[row-1][col].alive == true)
        {
            numAlive++;
        }
        // point bottom right
        if(ary[row+1][col+1].alive == true)
        {
            numAlive++;
        }
        // point bottom
        if(ary[row+1][col].alive == true)
        {
            numAlive++;
        }
        // point top right
        if(ary[row-1][col+1].alive == true)
        {
            numAlive++;
        }
    }
    else if(col == maxCol-1)
    {
        // point bottom
        if(ary[row+1][col].alive == true)
        {
            numAlive++;
        }
        // point left
        if(ary[row][col-1].alive == true)
        {
            numAlive++;
        }
        // point top left
        if(ary[row-1][col-1].alive == true)
        {
            numAlive++;
        }
        // point top
        if(ary[row-1][col].alive == true)
        {
            numAlive++;
        }
        // point bottom left
        if(ary[row+1][col-1].alive == true)
        {
            numAlive++;
        }
    }
    else
    {
        // point right
        if(ary[row][col+1].alive == true)
        {
            numAlive++;
        }
        // point left
        if(ary[row][col-1].alive == true)
        {
            numAlive++;
        }
        // point top left
        if(ary[row-1][col-1].alive == true)
        {
            numAlive++;
        }
        // point top
        if(ary[row-1][col].alive == true)
        {
            numAlive++;
        }
        // point top right
        if(ary[row-1][col+1].alive == true)
        {
            numAlive++;
        }
        // point bottom left
        if(ary[row+1][col-1].alive == true)
        {
            numAlive++;
        }
        // point bottom
        if(ary[row+1][col].alive == true)
        {
            numAlive++;
        }
        // point bottom right
        if(ary[row+1][col+1].alive == true)
        {
            numAlive++;
        }
    }

    if(ary[row][col].alive == true && (numAlive <= 1 || numAlive >= 4))
    {
        newAry[row][col].alive = false;
    }
    else if(ary[row][col].alive == false && numAlive == 3)
    {
        newAry[row][col].alive = true;
    }
    else
    {
        newAry[row][col].alive = ary[row][col].alive;
    }
}

void printArray(life** ary, int rows, int cols)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            if(ary[i][j].alive==true)
            {
                cout << "1";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}