#include "matmathlib.h"
#include <cstdio>

MatMathLib::MatMathLib()
{

}


// use vectors as parameters because want to reuse this multiply for variable sized arrays
std::vector<std::vector<int>>  MatMathLib::multiply(int LR, int RC, int LC, std::vector<std::vector<int>> LHS, std::vector<std::vector<int>> RHS)
{


    // Will hold the response, initialize it to the size. LHS # rows (column size), RHS # columns
    std::vector<int> column(LR);
    std::vector<std::vector<int>> product(RC, column);

    // move down LHS by row first
    for (int i = 0; i < LC; i++)
    {

        //walk across each column in RHS
        for (int j = 0; j < RC; j++)
        {
            int temp = 0;
            // iterate over each cell
            for (int k = 0; k < LR; k++)
            {
                // multiply with the corresponding item in RHS, update value
                product[i][j] += LHS[i][k] * RHS[j][k];
            }

        }

    }
    return product;
}
