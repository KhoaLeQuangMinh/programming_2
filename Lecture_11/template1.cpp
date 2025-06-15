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
            Cols = other.Cols;
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
        T frobeniusNorm(){
            T summation = 0;
            for(int i = 0; i < Rows; i++){
                for(int j = 0; j< Cols; j++){
                    summation += mData[i][j]*mData[i][j];
                }
            }
            return sqrt(summation);
        };
        T rowSumNorm(){
            T maximum = -999;
            for(int i = 0; i < Rows; i++){
                T sumRow = 0;
                for(int j = 0; j < Cols; j++){
                    sumRow += abs(mData[i][j]);
                }
                if(sumRow > maximum){
                    maximum = sumRow;
                }
            }
            return maximum;
        }
        T totalNorm(){
            T maximum = -999;
            for(int i = 0; i < Rows; i++){
                for(int j = 0; j < Cols; j++){
                    if(maximum < abs(mData[i][j])){
                        maximum = abs(mData[i][j]);
                    }
                }
            }
            return maximum*Rows;
        }
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
    Matrix<double> Norm(3,3);
    Norm(0, 0) = 1; Norm(0, 1) = 2; Norm(0, 2) = 3;
    Norm(1, 0) = 4; Norm(1, 1) = 5; Norm(1, 2) = 6;
    Norm(2, 0) = 7; Norm(2, 1) = 8; Norm(2, 2) = 9;
    cout<<Norm.frobeniusNorm()<<endl;
    cout<<Norm.rowSumNorm()<<endl;
    cout<<Norm.totalNorm()<<endl;
    return 0;
}