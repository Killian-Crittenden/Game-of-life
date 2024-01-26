#ifndef FUNCTIONS_H
#define FUNCTIONS_H

struct life
{
    bool alive;
};

life **create2Darry(int rows, int cols);

void delete2Darry(life**& ary, int rows);

void populateArry(life**& ary, int rows, int cols);

void checkLife(life**& ary, life**& newAry, int row, int col, int maxRow, int maxCol);

void printArray(life** ary, int rows, int cols);

#endif