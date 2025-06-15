#include <iostream>
#include "LinearSystem.h"
#include <string>

using namespace std;

LinearSystem::LinearSystem(Matrix & A, Vector & b){
    mpA = new Matrix(A);
    mpb = new Vector(b);
    mSize = (*mpA).getCols();
};
LinearSystem::LinearSystem(LinearSystem& LES){
    mSize = LES.mSize;
    mpA = new Matrix(*(LES.mpA));
    mpb = new Vector(*(LES.mpb));
};
LinearSystem::~LinearSystem(){
    delete mpA;
    delete mpb;
};
Vector LinearSystem::Solve() {
    Matrix A(*mpA);     // Copy matrix
    Vector b(*mpb);     // Copy vector

    for (int k = 1; k <= mSize; ++k) {
        // Pivoting
        int pivotRow = k;
        double maxVal = abs(A(k, k));
        for (int i = k + 1; i <= mSize; ++i) {
            if (abs(A(i, k)) > maxVal) {
                maxVal = abs(A(i, k));
                pivotRow = i;
            }
        }

        if (abs(maxVal) < 1e-10)
            throw CustomException("Matrix is singular");

        if (pivotRow != k) {
            A.swapRows(k - 1, pivotRow - 1);
            b.swapRows(k - 1, pivotRow - 1);
        }

        // Elimination
        for (int i = k + 1; i <= mSize; ++i) {
            double factor = A(i, k) / A(k, k);
            for (int j = k; j <= mSize; ++j) {
                A(i, j) -= factor * A(k, j);
            }
            b[i - 1] -= factor * b[k - 1];
        }
    }

    // Back substitution
    Vector x(mSize);
    for (int i = mSize; i >= 1; --i) {
        double sum = 0.0;
        for (int j = i + 1; j <= mSize; ++j) {
            sum += A(i, j) * x[j - 1];
        }
        x[i - 1] = (b[i - 1] - sum) / A(i, i);
    }

    return x;
}

