#ifndef SQR_MATRIX
#define SQR_MATRIX
#include "Matrix.hpp"
#include "vector"
#include <cmath>

/**
 *该类继承自Matrix，实现了方阵特有的一系列方法
 * 包括迹，行列式，伴随矩阵，逆矩阵等等方法的实现
 */
namespace matrix {

    template<typename T>
    class SqrMatrix : public Matrix<T> {
    private:
        int row;
        T arr;
    public:

        explicit SqrMatrix(int row) : Matrix<T>(row, row) {
            this->row = row;
        }

        explicit SqrMatrix(int row,T arr[]) : Matrix<T>(row,row,arr) {
            this->row = row;
        }

        int getRow() const {
            return row;
        }
        T getArray() const {
            return arr;
        }

    //计算矩阵的迹
        T trace() {
            T ans = 0;
            for (int i = 0; i < row; ++i) {
                SqrMatrix<T> tmp = *this;
                ans += tmp[i][i];
            }
            return ans;
        }

    //计算矩阵的行列式
        T determinant() {
            return determinant(this->data, row);
        }

        static T determinant(const std::vector<std::vector<T>> arr, int layer) {
            T ans{0};
            if (layer == 1) {
                return arr[0][0];
            }
            if (layer == 2) {
                return (arr[0][0] * arr[1][1] - arr[0][1] * arr[1][0]);
            } else {
                for (int cnt2 = 0; cnt2 < layer; ++cnt2) {
                    std::vector<std::vector<T>> tmp(layer - 1);
                    std::vector<int> spand;
                    for (int cnt1 = 0; cnt1 < layer; ++cnt1) {
                        if (cnt2 != cnt1) {
                            spand.push_back(cnt1);
                        }
                    }
                    for (int i = 0; i < layer - 1; ++i) {
                        tmp[i].resize(layer - 1);
                        for (int j = 0; j < layer - 1; ++j) {
                            tmp[i][j] = arr[spand[i]][j + 1];
                        }
                    }
                    int sign = (int) pow(-1, 1 + cnt2 + 1);
                    ans += arr[cnt2][0] * sign * determinant(tmp, layer - 1);
                }
            }

            return ans;
        }


        //计算伴随矩阵
        int adjoint(const std::vector<std::vector<T>> &matrix, std::vector<std::vector<T>> &adjointMatrix, int rowSize) {
            if (matrix.size() != rowSize) {
                std::cout<<"This matrix is not a square matrix."<<std::endl;
                return -1;
            }
            for (int i = 0; i < matrix.size(); ++i) {
                if (matrix[i].size() != rowSize) {
                    std::cout<<"This matrix is not a square matrix."<<std::endl;
                    return -1;
                }
            }

            adjointMatrix.resize(rowSize);
            for (int i = 0; i < rowSize; ++i) {
                adjointMatrix[i].resize(rowSize);
            }

            for (int y = 0; y < rowSize; ++y) {
                std::vector<int> m_cols;
                for (int i = 0; i < rowSize; ++i) {
                    if (i != y) m_cols.push_back(i);
                }

                for (int x = 0; x < rowSize; ++x) {
                    std::vector<int> m_rows;
                    for (int i = 0; i < rowSize; ++i) {
                        if (i != x) m_rows.push_back(i);
                    }

                    std::vector<std::vector<T>> m(rowSize - 1);
                    for (int i = 0; i < rowSize - 1; ++i) {
                        m[i].resize(rowSize - 1);
                    }
                    for (int j = 0; j < rowSize - 1; ++j) {
                        for (int i = 0; i < rowSize - 1; ++i) {
                            m[j][i] = matrix[m_rows[j]][m_cols[i]];
                        }
                    }
                    int sign = (int) pow(-1, x + y);
                    adjointMatrix[y][x] = sign * determinant(m, rowSize - 1);
                }
            }
            return 0;
        }

        // 求逆矩阵
        SqrMatrix<T> inverse() {

            SqrMatrix<T> inverseMatrix(this->row);

            std::vector<std::vector<T>> origin;
            std::vector<std::vector<T>> answer;

            origin.resize(row);
            answer.resize(row);
            for (int i = 0; i < row; ++i) {
                origin[i].resize(row);
                answer[i].resize(row);
            }
            for (int i = 0; i < row; ++i) {
                for (int j = 0; j < row; ++j) {
                    origin[i][j] = this->data[i][j];
                }
            }
            inverse(origin, answer, row);
            for (int i = 0; i < row; ++i) {
                for (int j = 0; j < row; ++j) {
                    inverseMatrix.data[i][j] = answer[i][j];
                }
            }
            return inverseMatrix;
        }

        void inverse(const std::vector<std::vector<T>> &matrix, std::vector<std::vector<T>> &inv, int N) {
            T det = determinant(matrix, N);

            inv.resize(N);
            for (int i = 0; i < N; ++i) {
                inv[i].resize(N);
            }

            double coef = 1.f / det;
            std::vector<std::vector<T>> adj;
            if (adjoint(matrix, adj, N) != 0) {
                return;
            }

            for (int y = 0; y < N; ++y) {
                for (int x = 0; x < N; ++x) {
                    inv[y][x] = (T) (coef * adj[y][x]);
                }
            }
        }
    };
}
#endif