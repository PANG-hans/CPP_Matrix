#include <iostream>
#include "../matrixLibrary/SqrMatrix.hpp"

using namespace matrix;
using namespace std;

int main() {
    //新建一个4*4的矩阵进行测试
    double array1[] = {1, 0, 2, -1,
                       3, 0, 0, 5,
                       2, 1, 4, -3,
                       1, 0, 5, 0};
    SqrMatrix<double> sqrMatrix1(4, array1);


    std::cout << "矩阵sqrMatrix1的大小为:" << sqrMatrix1.getRow() << endl;
    std::cout << "矩阵sqrMatrix1的内容为:" << endl;
    sqrMatrix1.showMatrix();

    std::cout << "矩阵qrMatrix1的转置矩阵内容为:" << endl;
    sqrMatrix1.transpose().showMatrix();

    std::cout << "矩阵sqrMatrix1的trace为:" << sqrMatrix1.trace() << std::endl;
    std::cout << "矩阵sqrMatrix1的行列式为:" << sqrMatrix1.determinant() << std::endl;
    std::cout << "矩阵sqrMatrix1的逆矩阵为:" << std::endl;
    SqrMatrix<double> sqrMatrix2(4);
    sqrMatrix2 = sqrMatrix1.inverse();
    sqrMatrix2.showMatrix();
    Matrix<double> sqrMatrix3(4, 4);

    std::cout << "设定一个新的4 * 4方阵 sqrMatrix4" << endl;

    double array2[] = {
            1, 3, 7, 8,
            2, 5, 9, 0,
            4, 6, 7, 9,
            3, 5, 8, 1
    };
    Matrix<double> sqrMatrix4(4, 4, array2);
    Matrix<double> sqrMatrix5(4, 4);

    std::cout << "矩阵sqrMatrix4的内容为:" << endl;
    sqrMatrix4.showMatrix();

    std::cout << "将矩阵sqrMatrix4 和 sqrMatrix1 相乘(叉乘）后得到新矩阵为:" << endl;
    sqrMatrix5 = sqrMatrix4 * sqrMatrix1;
    sqrMatrix5.showMatrix();

    std::cout << "将矩阵sqrMatrix4 和 sqrMatrix1 相加后得到新矩阵为:" << endl;
    sqrMatrix5 = sqrMatrix4 + sqrMatrix1;
    sqrMatrix5.showMatrix();

    std::cout << "将矩阵sqrMatrix4 和 sqrMatrix1 相减后得到新矩阵为:" << endl;
    sqrMatrix5 = sqrMatrix4 - sqrMatrix1;
    sqrMatrix5.showMatrix();
}
