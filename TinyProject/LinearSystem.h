#pragma once
#include "Matrix.h"
class LinearSystem{
    protected:
        int mSize;
        Matrix* mpA;
        Vector* mpb;
    public:
        LinearSystem( Matrix& A,  Vector& b);
        LinearSystem(LinearSystem& LES);
        virtual ~LinearSystem();
        virtual Vector Solve();
};  
