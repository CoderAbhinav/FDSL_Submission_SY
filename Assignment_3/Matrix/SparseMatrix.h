#pragma once
#include <iostream>

struct SparseMatrix
{
    int row;
    int col;
    int val;
};

SparseMatrix createSparseMatrix(int row, int col, int val){
    SparseMatrix rev;
    rev.col = col;
    rev.row = row;
    rev.val = val;
    return rev;
}