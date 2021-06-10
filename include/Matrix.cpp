//
// Created by Pang_Hans on 2021/6/10.
//

#include "Matrix.h"
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;
using namespace matrix;

int main() {
    int arr[5][5] = {{1, 2, 3, 4, 5},
               {6, 7, 8, 9, 10},
               {11, 12, 13, 14, 15},
               {16, 17, 18, 19, 20},
               {21, 22, 23, 24, 25}
    };

    Matrix<int> mm = Matrix<int>(5, 5, arr);
    cout << mm.rowSum(2);


}