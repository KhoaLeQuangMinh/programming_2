#include <iostream>
#include "Matrix.h"
#include <string>
using namespace std;

Matrix::Matrix(const Matrix& other){
    mNumCols = other.mNumCols;
    mNumRows = other.mNumRows;
    mData = new double*[mNumRows];
    for(int i = 0; i < mNumRows; i++){
        mData[i] = new double[mNumCols];
        for(int j = 0; j < mNumCols; j++){
            mData[i][j] = other.mData[i][j];
        }
    }
};
Matrix& Matrix::operator=(const Matrix& other){
    if(this == &other){return *this;};
    for(int i = 0; i < mNumRows; i++){
        delete[] mData[i];
    }
    delete[] mData;
    mNumRows = other.mNumRows;
    mNumCols = other.mNumCols;
    mData = new double*[mNumRows];
    for (int i = 0; i < mNumRows; i++) {
        mData[i] = new double[mNumCols];
        for (int j = 0; j < mNumCols; j++) {
            mData[i][j] = other.mData[i][j];
        }
    }
    return *this;
};
Matrix::Matrix(int mNumRows, int mNumCols){
    this->mNumCols = mNumCols;
    this->mNumRows = mNumRows;
    mData = new double*[mNumRows];
    for(int i = 0; i < mNumRows; i++){
        mData[i] = new double[mNumCols];
        for(int j = 0; j < mNumCols; j++){
            mData[i][j] = 0;
        }
    }
};
Matrix::~Matrix(){
    for(int i = 0; i < mNumRows; i++){
        delete[] mData[i];
    }
    delete[] mData;
    mData = nullptr;
};
int Matrix::getRows(){
    return mNumRows;
};
int Matrix::getCols(){
    return mNumCols;
};
double** Matrix::getData() const{
    return mData;
};
// indexing by 1
double& Matrix::operator ()(int i, int j){
    return mData[i-1][j-1];
};
// Matrix add Matrix
Matrix Matrix::operator +(Matrix other){
    if(mNumCols != other.mNumCols || mNumRows != other.mNumRows){
        throw CustomException("Addition Matrix must be of same sizes!");
    }
    Matrix temp(mNumRows,mNumCols);
    for(int i = 0; i < mNumRows; i++){
        for(int j = 0; j < mNumCols; j++){
            temp.mData[i][j] = mData[i][j] + other.mData[i][j];
        }
    }
    return temp;
};
// Matrix subtract Matrix
Matrix Matrix::operator -(Matrix other){
    if(mNumCols != other.mNumCols || mNumRows != other.mNumRows){
        throw CustomException("Addition Matrix must be of same sizes!");
    }
    Matrix temp(mNumRows,mNumCols);
    for(int i = 0; i < mNumRows; i++){
        for(int j = 0; j < mNumCols; j++){
            temp.mData[i][j] = mData[i][j] - other.mData[i][j];
        }
    }
    return temp;
};
// Dot product of 2 Matrixes
Matrix Matrix::operator*(Matrix other) {
    if (mNumCols != other.mNumRows) {
        throw CustomException("Multiplication must have same dimension of cols with other rows");
    }

    Matrix temp(mNumRows, other.mNumCols);
    for (int i = 0; i < mNumRows; ++i) {
        for (int j = 0; j < other.mNumCols; ++j) {
            temp.mData[i][j] = 0;
            for (int k = 0; k < mNumCols; ++k) {
                temp.mData[i][j] += mData[i][k] * other.mData[k][j];
            }
        }
    }
    return temp;
}

// Matrix multiply by scalar
Matrix Matrix::operator *(double scalar){
    Matrix temp(mNumRows, mNumCols);
    for(int i = 0; i < mNumRows; i++){
        for(int j = 0; j < mNumCols; j++){
            temp.mData[i][j] = mData[i][j]*scalar;
        }
    }
    return temp;
};   
//Unary add Matrix++
Matrix Matrix::operator ++(int){
    Matrix temp(*this);
    for(int i = 0; i < mNumRows; i++){
        for(int j = 0; j < mNumCols; j++){
            mData[i][j]++;
        }
    }
    return temp;
}; 
//Unary add ++Matrix
Matrix& Matrix::operator ++(){
    for(int i = 0; i < mNumRows; i++){
        for(int j = 0; j < mNumCols; j++){
            mData[i][j]++;
        }
    }
    return *this;
};
//Unary subtract Matrix--
Matrix Matrix::operator --(int){
    Matrix temp(*this);
    for(int i = 0; i < mNumRows; i++){
        for(int j = 0; j < mNumCols; j++){
            mData[i][j]--;
        }
    }
    return temp;
};
//Unary subtract --Matrix
Matrix& Matrix::operator --(){
    for(int i = 0; i < mNumRows; i++){
        for(int j = 0; j < mNumCols; j++){
            mData[i][j]--;
        }
    }
    return *this;
};
//Determinant
double Matrix::getDet(){
    if (mNumRows != mNumCols) {
        throw CustomException("Determinant is only defined for square matrices.");
    }

    double** temp = new double*[mNumRows];
    for (int i = 0; i < mNumRows; ++i) {
        temp[i] = new double[mNumCols];
        for (int j = 0; j < mNumCols; ++j) {
            temp[i][j] = mData[i][j];
        }
    }

    double det = 1.0;
    for (int i = 0; i < mNumRows; ++i) {
        int pivot = i;
        for (int j = i + 1; j < mNumRows; ++j) {
            if (abs(temp[j][i]) > abs(temp[pivot][i])) {
                pivot = j;
            }
        }

        if (abs(temp[pivot][i]) < 1e-10) {
            det = 0;
            break;
        }

        if (i != pivot) {
            swap(temp[i], temp[pivot]);
            det *= -1;
        }

        det *= temp[i][i];
        for (int j = i + 1; j < mNumRows; ++j) {
            double f = temp[j][i] / temp[i][i];
            for (int k = i; k < mNumCols; ++k) {
                temp[j][k] -= f * temp[i][k];
            }
        }
    }
    return det;
};
Matrix Matrix::inverse(){
    if (mNumRows != mNumCols)
        throw CustomException("Inverse only defined for square matrices.");

    int n = mNumRows;
    Matrix result(n, n);
    Matrix temp(*this);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            result.mData[i][j] = (i == j ? 1.0 : 0.0);

    for (int i = 0; i < n; ++i) {
        double pivot = temp.mData[i][i];
        if (abs(pivot) < 1e-10)
            throw runtime_error("Singular matrix.");
        for (int j = 0; j < n; ++j) {
            temp.mData[i][j] /= pivot;
            result.mData[i][j] /= pivot;
        }
        for (int k = 0; k < n; ++k) {
            if (k == i) continue;
            double factor = temp.mData[k][i];
            for (int j = 0; j < n; ++j) {
                temp.mData[k][j] -= factor * temp.mData[i][j];
                result.mData[k][j] -= factor * result.mData[i][j];
            }
        }
    }
    return result;
};
Matrix Matrix::transpose() {
    Matrix transposed(mNumCols, mNumRows);
    for (int i = 0; i < mNumRows; ++i) {
        for (int j = 0; j < mNumCols; ++j) {
            transposed.mData[j][i] = mData[i][j];
        }
    }
    return transposed;
}

Matrix Matrix::psedoInv(){
    Matrix At = this->transpose();
    Matrix AtA = At * (*this);
    Matrix AtA_inv = AtA.inverse();
    return AtA_inv * (At);
};
//Scalar multiply by Vector
Matrix operator*(double a, Matrix b){
    Matrix temp(b.getRows(), b.getCols());
    for(int i = 0; i < b.getRows(); i++){
        for(int j = 0; j < b.getCols(); j++){
            temp(i+1,j+1) = b.getData()[i][j]*a;
        }
    }
    return temp;
};
void Matrix::swapRows(int i, int j) {
    if (i == j) return;

    if (i < 0 || i >= mNumRows || j < 0 || j >= mNumRows) {
        throw CustomException("Row index out of range!");
    }

    swap(mData[i], mData[j]);
}

Vector Matrix::operator*(Vector& vec) {
    int rows = this->getRows();
    int cols = this->getCols();

    if (vec.getSize() != cols) {
        throw CustomException("Matrix-vector size mismatch");
    }

    Vector result(rows);
    for (int i = 0; i < rows; ++i) {
        double sum = 0.0;
        for (int j = 0; j < cols; ++j) {
            sum += mData[i][j] * vec.getData()[j];
        }
        result(i + 1) = sum;
    }
    return result;
}

void Matrix::print(){
    cout<< "Value of Matrix is: "<<endl;
    for(int i = 0; i< mNumRows; i++){
        for(int j = 0; j< mNumCols; j++ ){
            cout<<mData[i][j]<<" ";
        }
        cout<<endl;
    }
};

double Matrix::infnorm() const
{
    double maxRowSum = 0.0;
    for (int i = 0; i < this->mNumRows; i++)
    {
        double rowSum = 0.0;
        for (int j = 0; j < this->mNumCols; j++)
        {
            rowSum += fabs(this->mData[i][j]);
        }
        maxRowSum = max(maxRowSum, rowSum);
    }
    return maxRowSum;
}
void Matrix::setIdentity()
{
    assert(this->mNumCols == this->mNumRows && this->mNumCols != 0);
    for (int i = 0; i < this->mNumRows; i++)
    {
        for (int j = 0; j < this->mNumCols; j++)
        {
            this->mData[i][j] = (i == j ? 1 : 0);
        }
    }
}