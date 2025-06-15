#pragma once
#include "PosSymLinSystem.h"

class NonSquare: public LinearSystem{
    public:
        NonSquare(Matrix& A, Vector& b);
        Vector Solve (); //Normal equation
        Vector solve(); //Tikhonov
};