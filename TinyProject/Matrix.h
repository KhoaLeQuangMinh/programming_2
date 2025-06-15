#pragma once
#include "Vector.h"
class Matrix{
    private:
        int mNumRows;
        int mNumCols;
        double** mData;
    public:
        Matrix(const Matrix& other);
        Matrix(int mNumRows, int mNumCols);
        Matrix& operator=(const Matrix& other);
        ~Matrix();
        int getRows();
        int getCols();
        double** getData() const;
        double& operator ()(int i, int j);
        // Matrix add Matrix
        Matrix operator +(Matrix other);
        // Matrix subtract Matrix
        Matrix operator -(Matrix other);
        // Dot product of 2 Matrixes
        Matrix operator *(Matrix other);
        // Matrix multiply by scalar
        Matrix operator *(double scalar);   
        //Unary add Matrix++
        Matrix operator ++(int); 
        //Unary add ++Matrix
        Matrix& operator ++();
        //Unary subtract Matrix--
        Matrix operator --(int);
        //Unary subtract --Matrix
        Matrix& operator --();
        //Determinant
        double getDet();
        Matrix inverse();
        Matrix psedoInv();
        Matrix transpose();
        void swapRows(int i , int j);
        //Matrix * Vector
        Vector operator*(Vector& vec);
        void print();
        double infnorm() const;
        void setIdentity();
};
//Scalar multiply by Matrix
Matrix operator*(double a, Matrix b);