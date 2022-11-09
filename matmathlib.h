#ifndef MATMATHLIB_H
#define MATMATHLIB_H


#include <vector>


class MatMathLib
{
public:
    MatMathLib();

    // Matrix multiplication function for an m x n matrix times a n x o matrix
    static std::vector<std::vector<int>> multiply(int LR, int RC, int LC, std::vector<std::vector<int>> LHS, std::vector<std::vector<int>> RHS);
};

#endif // MATMATHLIB_H
