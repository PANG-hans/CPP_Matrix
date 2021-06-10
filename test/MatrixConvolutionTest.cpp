#include <iostream>
#include "../matrixLibrary/MatrixConvolution.hpp"
using namespace matrix;
using namespace std;

int main(){
    double array3[] = {
            1,2,3,4,
            5,6,7,8,
            9,10,11,12,
            13,14,15,16
    };
    double array4[] = {
            1,2,1,
            0,0,0,
            -1,-2,-1
    };

    Matrix<double> matrix4(4, 4,array3);
    Matrix<double> kernal(3, 3,array4);
    Matrix<double> matrix5(4, 4);
    matrix5 = matrix4.convolution(kernal);
    std::cout<<"卷积前矩阵"<<std::endl;
    matrix4.showMatrix();
    std::cout << "卷积核" << std::endl;
    kernal.showMatrix();
    std::cout << "卷积结果" << std::endl;
    matrix5.showMatrix();
}

