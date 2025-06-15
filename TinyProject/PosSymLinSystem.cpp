#include "PosSymLinSystem.h"
#include <cmath>
#include <iostream>

PosSymLinSystem::PosSymLinSystem(Matrix& A, Vector& b) : LinearSystem(A, b) {
    Matrix At = A.transpose();
    if ((A - At).getDet() >= 1e-10) {
        throw CustomException("Matrix is not symmetric!");
    }
}

Vector PosSymLinSystem::Solve() {
    int n = mSize;
    Vector x(n); // Initial guess = 0
    Vector r = *mpb - (*mpA * x);
    Vector p = r;
    double rsold = r * r;

    for (int i = 0; i < n; i++) {
        Vector Ap = (*mpA) * p;
        double alpha = rsold / (p * Ap);
        x = x + p * alpha;
        r = r - Ap * alpha;

        double rsnew = r * r;
        if (std::sqrt(rsnew) < 1e-10)
            break;

        p = r + p * (rsnew / rsold);
        rsold = rsnew;
    }

    return x;
}
