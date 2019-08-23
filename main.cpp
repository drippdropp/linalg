#include <iostream>
#include "linalg.h"
int main()
{
    int col_v_1[2] = {2,-3};
    int col_v_2[2] = {3, 4};
    ColumnVector<int> col1{col_v_1, 2};
    ColumnVector<int> col2{col_v_2, 2};
    auto* vals = new ColumnVector<int>[2]{col1, col2};
    Matrix<int> mat1{1, 1, vals};



    return 0;
}