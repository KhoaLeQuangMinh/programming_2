#pragma once
#include "LinearSystem.h"
class PosSymLinSystem: public LinearSystem{
    public:
        PosSymLinSystem(Matrix& A, Vector& b);
        Vector Solve();
};