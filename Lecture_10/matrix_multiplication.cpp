#include <iostream>
#include <cmath>
#include <cassert>
using namespace std;

template <class T>
class Matrix{
    private:
        int Rows;
        int Cols;
        T ** mData;
    public:
        Matrix(int Rows, int Cols): Rows(Rows), Cols(Cols){
            mData = new T*[Rows];
            for (int i = 0; i < Rows; i++){
                mData[i] = new T[Cols];
                for (int j = 0; j < Cols; j++){
                    mData[i][j] = 0;
                }
            }
        };
        T& operator ()(int i, int j){
            return mData[i][j];
        };
        ~Matrix(){
            for(int i = 0; i < Rows; i++){
                delete[] mData[i];
            }
            delete[] mData;
        };
        Matrix(const Matrix& other): Rows(other.Rows), Cols(other.Cols) {
            mData = new T*[Rows];
            for (int i = 0; i < Rows; i++) {
                mData[i] = new T[Cols];
                for (int j = 0; j < Cols; j++) {
                    mData[i][j] = other.mData[i][j];
                }
            }
        }
        Matrix& operator=(const Matrix& other){
            if(this == &other){return *this;};
            for(int i = 0; i < Rows; i++){
                delete[] mData[i];
            }
            delete[] mData;
            Rows = other.Rows;
            Rows = other.Cols;
            mData = new double*[Rows];
            for (int i = 0; i < Rows; i++) {
                mData[i] = new double[Cols];
                for (int j = 0; j < Cols; j++) {
                    mData[i][j] = other.mData[i][j];
                }
            }
            return *this;
        };
        Matrix operator *(const Matrix& other) const {
            assert(Cols == other.Rows);
            Matrix temp(Rows, other.Cols);
            for(int i = 0; i < Rows; i++){
                for(int j = 0; j < other.Cols; j++){
                    for(int k = 0; k < Cols; k++){
                        temp(i,j) += mData[i][k] * other.mData[k][j];
                    }
                }
            }
            return temp;
        };
        void print() {
            for (int i = 0; i < Rows; i++) {
                for (int j = 0; j < Cols; j++) {
                    cout << mData[i][j] << " ";
                }
                cout << endl;
            }
        }

        int getRows() const { return Rows; };
        int getCols() const { return Cols; };
};
int main(){
    // int test
    cout << "Int matrix multiplication:" << endl;
    Matrix<int> A(2, 3);
    Matrix<int> B(3, 2);
    A(0, 0) = 1; A(0, 1) = 2; A(0, 2) = 3;
    A(1, 0) = 4; A(1, 1) = 5; A(1, 2) = 6;
    B(0, 0) = 7;  B(0, 1) = 8;
    B(1, 0) = 9;  B(1, 1) = 10;
    B(2, 0) = 11; B(2, 1) = 12;
    Matrix<int> C = A * B;
    C.print();
    cout << endl;

    // float test
    cout << "Float matrix multiplication:" << endl;
    Matrix<float> Af(2, 3);
    Matrix<float> Bf(3, 2);
    Af(0, 0) = 1.1f; Af(0, 1) = 2.2f; Af(0, 2) = 3.3f;
    Af(1, 0) = 4.4f; Af(1, 1) = 5.5f; Af(1, 2) = 6.6f;
    Bf(0, 0) = 7.7f;  Bf(0, 1) = 8.8f;
    Bf(1, 0) = 9.9f;  Bf(1, 1) = 10.1f;
    Bf(2, 0) = 11.11f; Bf(2, 1) = 12.12f;
    Matrix<float> Cf = Af * Bf;
    Cf.print();
    cout << endl;

    // double test
    cout << "Double matrix multiplication:" << endl;
    Matrix<double> Ad(2, 3);
    Matrix<double> Bd(3, 2);
    Ad(0, 0) = 1.11; Ad(0, 1) = 2.22; Ad(0, 2) = 3.33;
    Ad(1, 0) = 4.44; Ad(1, 1) = 5.55; Ad(1, 2) = 6.66;
    Bd(0, 0) = 7.77;  Bd(0, 1) = 8.88;
    Bd(1, 0) = 9.99;  Bd(1, 1) = 10.10;
    Bd(2, 0) = 11.11; Bd(2, 1) = 12.12;
    Matrix<double> Cd = Ad * Bd;
    Cd.print();

    return 0;
}