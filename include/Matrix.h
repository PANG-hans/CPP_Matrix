//
// Created by Pang_Hans on 2021/6/10.
//

#ifndef MATRIX_MATRIX_H
#define MATRIX_MATRIX_H

#include <iostream>
#include <vector>
#include <complex>
#include <algorithm>

using namespace std;

namespace matrix {
    template<typename T>
    class Matrix {
    private:
        int row{};
        int col{};
        bool check_shape(Matrix);
    public:
        std::vector<std::vector<T> > data;

        Matrix(int row, int column);

        explicit Matrix(int row, int column, T array);

        void initial();

        T findMax();

        T findMin();

        T findRowMax(int rownum);

        T findColMax(int colnum);

        T findRowMin(int rownum);

        T findColMin(int colnum);

        T sum();

        T rowSum(int rownum);

        T colSum(int colnum);

        T avg();

        T rowAvg();

        T colAvg();
        //T rowComplexAvg();
        //T colComplexAvg();

        Matrix<T> add(Matrix);
        Matrix<T> subtract(Matrix);
        Matrix<T> scalar_multiplication(int);
        Matrix<T> scalar_division(int);
        Matrix<T> transposition();
        Matrix<T> conjugation();
        Matrix<T> element_wise_multiplication(Matrix);
        Matrix<T> matrix_matrix_multiplication(Matrix);
        Matrix<T> matrix_vector_multiplication(T[]);
        friend int dot_product(T[], T[]);
        friend void cross_product(T[], T[]);
        Matrix<T> reshape(int, int);
        Matrix<T> slice(bool, int, int);

    };

    template<typename T>
    Matrix<T>::Matrix(int row, int column) {
        this->row = row;
        this->column = column;
        initial();
    }

    template<typename T>
    void Matrix<T>::initial() {
        this->data.resize(row);
        for (int i = 0; i < row; ++i) {
            this->data[i].resize(col);
        }
    }

    template<typename T>
    Matrix<T>::Matrix(int row, int column, T array) : Matrix(row, column) {
        for (int i = 0; i < this->row; ++i) {
            for (int j = 0; j < col; ++j) {
                data[i][j] = array[i][j];
            }
        }
    }

    template<typename T>
    T Matrix<T>::findMax() {
        T max = this->data.front().front();
        for (const auto &iter : this->data) {
            max = std::max(std::max_element(std::begin(iter), std::end(iter)), max);
        }
        return max;
    }

    template<typename T>
    T Matrix<T>::findMin() {
        T min = this->data.front().front();
        for (const auto &iter : this->data) {
            min = std::min(std::min_element(std::begin(iter), std::end(iter)), min);
        }
        return min;
    }

    template<typename T>
    T Matrix<T>::findRowMax(int rownum) {
        T max = this->data.at(rownum).front();
        max = max(std::max_element(this->data.at(rownum).begin(), this->data.at(rownum).end()), max);
        return max;
    }

    template<typename T>
    T Matrix<T>::findColMax(int colnum) {
        T max = this->data[0][colnum];
        for (int i = 0; i < row; ++i) {
            max = max(max, this->data[i][colnum]);
        }
        return max;
    }

    template<typename T>
    T Matrix<T>::findRowMin(int rownum) {
        T min = this->data.at(rownum).front();
        min = min(std::min_element(this->data.at(rownum).begin(), this->data.at(rownum).end()), min);
        return min;
    }

    template<typename T>
    T Matrix<T>::findColMin(int colnum) {
        T min = this->data[0][colnum];
        for (int i = 0; i < row; ++i) {
            min = min(min, this->data[i][colnum]);
        }
        return min;
    }

    template<typename T>
    T Matrix<T>::sum() {
        T sum(0);
        for (auto r : this->data)
            for (auto c : r)
                sum += c;
    }

    template<typename T>
    T Matrix<T>::rowSum(int rownum) {
        T sum(0);
        for (auto m : this->data[rownum])
            sum += m;
    }

    template<typename T>
    T Matrix<T>::colSum(int colnum) {
        T sum(0);
        for (int i = 0; i < this->data.size(); ++i) {
            sum += this->data[i][colnum];
        }
        return sum;
    }

    template<typename T>
    T Matrix<T>::avg() {
        return this->sum() / (T) (this->row * this->col);
    }

    template<typename T>
    T Matrix<T>::rowAvg() {
        return this->rowSum() / (T) this->col;
    }

    template<typename T>
    T Matrix<T>::colAvg() {
        return this->colSum() / (T) this->row;
    }
    
    template<typename T>
    Matrix<T>::Matrix(int **arr, int row, int column) {
        row = row;
        col = column;
        data = new int *[row];
        for (int i = 0; i < row; i++) {
            data[i] = new int[col];
            for (int j = 0; j < col; j++) {
                data[i][j] = arr[i][j];
            }
        }
    }
    
    template<typename T>
    bool Matrix<T>::check_shape(Matrix mat) {
        return row == mat.row and col == mat.col;
    }

    template<typename T>
    Matrix<T> Matrix<T>::add(Matrix mat) {
        if (!check_shape(mat)) {
            cout << "Not same shape matrix." << endl;
            return *this;
        }
        int **arr = new int *[row];
        for (int i = 0; i < row; i++) {
            arr[i] = new int[col];
            for (int j = 0; j < col; j++) {
                arr[i][j] = data[i][j] + mat.data[i][j];
            }
        }
        return Matrix(arr, row, col);
    }

    template<typename T>
    Matrix<T> Matrix<T>::subtract(Matrix mat) {
        if (!check_shape(mat)) {
            std::cout << "Not same shape data." << std::endl;
            return *this;
        }
        int **arr = new int *[row];
        for (int i = 0; i < row; i++) {
            arr[i] = new int[col];
            for (int j = 0; j < col; j++) {
                arr[i][j] = data[i][j] - mat.data[i][j];
            }
        }
        return Matrix(arr, row, col);
    }

    template<typename T>
    Matrix<T> Matrix<T>::scalar_multiplication(int scalar) {
        int **arr = new int *[row];
        for (int i = 0; i < row; i++) {
            arr[i] = new int[col];
            for (int j = 0; j < col; j++) {
                arr[i][j] = data[i][j] * scalar;
            }
        }
        return Matrix(arr, row, col);
    }

    template<typename T>
    Matrix<T> Matrix<T>::scalar_division(int scalar) {
        int **arr = new int *[row];
        for (int i = 0; i < row; i++) {
            arr[i] = new int[col];
            for (int j = 0; j < col; j++) {
                arr[i][j] = data[i][j] * scalar;
            }
        }
        return Matrix(arr, row, col);
    }

    template<typename T>
    Matrix<T> Matrix<T>::transposition() {
        int **arr = new int *[col];
        for (int i = 0; i < col; i += 1) {
            arr[i] = new int[row];
            for (int j = 0; j < row; j += 1) {
                arr[i][j] = data[j][i];
            }
        }
        return Matrix(arr, col, row);
    }

    template<typename T>
    T Matrix<T>::conjugation() {
        //do nothing for real number data
        return Matrix(data, col, row);
    }

    template<typename T>
    Matrix<T> Matrix<T>::element_wise_multiplication(Matrix mat) {
        if (!check_shape(mat)) {
            cout << "Not same shape data." << endl;
            return *this;
        }
        int **arr = new int *[row];
        for (int i = 0; i < row; i++) {
            arr[i] = new int[col];
            for (int j = 0; j < col; j++) {
                arr[i][j] = data[i][j] * mat.data[i][j];
            }
        }
        return Matrix(arr, row, col);
    }

    template<typename T>
    Matrix<T> Matrix<T>::matrix_matrix_multiplication(Matrix mat) {
        if (col != mat.row) {
            cout << "Column length not equal to row length of another data." << endl;
            return *this;
        }
        int **arr = new int *[row];
        for (int i = 0; i < row; i++) {
            arr[i] = new int[mat.col];
            for (int j = 0; j < mat.col; j++) {
                arr[i][j] = 0;
                for (int x = 0; x < col; x++) {
                    arr[i][j] += data[i][x] * mat.data[x][j];
                }
            }
        }
        return Matrix(arr, row, mat.col);
    }

    template<typename T>
    Matrix<T> Matrix<T>::matrix_vector_multiplication(T *vector) {
        if (col != length(vector)) {
            cout << "Column length not equal to length of vector." << endl;
            return *this;
        }
        int **arr = new int *[row];
        for (int i = 0; i < row; i++) {
            arr[i] = new int[1];
            arr[i][0] = 0;
            for (int x = 0; x < row; x++) {
                arr[i][0] += data[i][x] * vector[x];
            }
        }
        return Matrix(arr, row, 1);
    }

    template<typename T>
    int dot_product(T *vector1, T *vector2) {
        if (length(vector1) != length(vector2)) {
            cout << "Not same length vector." << endl;
            return 0;
        }
        int result = 0;
        for (int i = 0; i < length(vector1); i++) {
            result += vector1[i] * vector2[i];
        }
        return result;
    }

    template<typename T>
    void cross_product(T *, T *) {

    }

    template<typename T>
    Matrix<T> Matrix<T>::reshape(int row, int column) {
        if (row * column != row * col) {
            cout << "Not same shape." << endl;
            return *this;
        }
        int **arr = new int *[row];
        for (int i = 0; i < row; i++) {
            arr[i] = new int[column];
            for (int j = 0; j < column; j++) {
                arr[i][j] = data[(i * column + j) / col][(i * column + j) % col];
            }
        }
        return Matrix(arr, row, column);
    }

    template<typename T>
    Matrix<T> Matrix<T>::slice(bool row, int start, int end) {
        if (start >= end) {
            cout << "Illegal input." << endl;
            return *this;
        }
        int **arr;
        if (row) {
            arr = new int *[end - start];
            for (int i = start; i < end; i++) {
                for (int j = 0; j < col; j++) {
                    arr[i - start][j] = data[i][j];
                }
            }
            return Matrix(arr, end - start, col);
        } else {
            arr = new int *[row];
            for (int i = 0; i < row; i++) {
                for (int j = start; j < end; j++) {
                    arr[i][j - start] = data[i][j];
                }
            }
            return Matrix(arr, row, end - start);
        }
    }


}
#endif //MATRIX_MATRIX_H
