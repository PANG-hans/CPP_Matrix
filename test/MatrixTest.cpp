#include "../matrixLibrary/Matrix.hpp"
#include "complex"

using namespace std;
using namespace matrix;

int main() {
    cout << "建立一个3 * 4 的复数类型矩阵matrix1,它的内容为：" << endl;
    complex<double> array1[12] = {{1,  2},
                                  {3,  4},
                                  {5,  6},
                                  {7,  8},
                                  {9,  10},
                                  {11, 12},
                                  {13, 14},
                                  {15, 16},
                                  {17, 18},
                                  {19, 20},
                                  {21, 22},
                                  {23, 24}};
    Matrix<complex<double>> matrix1(3, 4, array1);
    matrix1.showMatrix();
    cout << "建立一个4 * 3 的复数类型矩阵matrix2,它的内容为：" << endl;
    complex<double> array2[12] = {{-1,  -2},
                                  {-3,  -4},
                                  {-5,  -6},
                                  {-7,  -8},
                                  {-9,  -10},
                                  {-11, -12},
                                  {-13, -14},
                                  {-15, -16},
                                  {-17, -18},
                                  {-19, 20},
                                  {-21, -22},
                                  {-23, -24}};
    Matrix<complex<double>> matrix2(4, 3, array2);
    matrix2.showMatrix();
    cout << "matrix1 * matrix2 的结果为" << endl;
    (matrix1 * matrix2).showMatrix();
    cout << "matrix2 * matrix1 的结果为" << endl;
    (matrix2 * matrix1).showMatrix();
    cout << "matrix1 - matrix1 的结果为" << endl;
    (matrix1 - matrix1).showMatrix();
    cout << "matrix2 + matrix2 的结果为" << endl;
    (matrix2 + matrix2).showMatrix();
    cout << "matrix1 和 matrix1 的Hadamard product结果为" << endl;
    matrix1.elementMultiply(matrix1).showMatrix();


    cout << "建立一个3 * 4 的double类型矩阵matrix3,它的内容为：" << endl;
    double array3[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    Matrix<double> matrix3(3, 4, array3);
    matrix3.showMatrix();
    cout << "matrix3的转置为:" << endl;
    matrix3.transpose().showMatrix();

    cout << "matrix3的最大值为:" << matrix3.findMax() << endl;
    cout << "matrix3的最小值为:" << matrix3.findMin() << endl;
    cout << "matrix3的平均值为:" << matrix3.average() << endl;

    cout << "接下来演示标量乘除法." << endl;
    cout << "matrix1 * 5 的结果为:" << endl;
    (matrix1 * 5).showMatrix();
    cout << "5 * matrix1 的结果为:" << endl;
    (5 * matrix1).showMatrix();
    cout << "matrix1 / 5 的结果为:" << endl;
    (matrix1 / 5).showMatrix();



}