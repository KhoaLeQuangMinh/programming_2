#include "NonSquare.h"
#include <iostream>

NonSquare::NonSquare(Matrix& A, Vector& b) : LinearSystem(A, b) {
};

Vector NonSquare::Solve(){
    Matrix At = mpA->transpose();
    Matrix AtA = At * (*mpA);
    Matrix AtA_inv = AtA.inverse();
    Matrix pseudoInv = AtA_inv * At;

    Vector x = pseudoInv * (*mpb);

    return x;
};

Vector NonSquare::solve()
{
    int m = (this->mpA)->getRows();
    int n = (this->mpA)->getCols();
    assert((this->mpb)->getSize() == m);

    Matrix At = (this->mpA)->transpose();
    Matrix Gram(0,0); 
    Matrix GramInv(0,0);
    bool underdetermined = (m < n);
    const double THRESH = 1e6;
    double lambda = 1e-3;

    if (underdetermined)
    {
        // G = A Aᵀ (m×m)
        Gram = (*(this->mpA)) * At;
    }
    else
    {
        // G = Aᵀ A (n×n)
        Gram = At * (*(this->mpA));
    }
    Matrix Ginv = Gram.inverse();
    double cond = Gram.infnorm() * Ginv.infnorm();
    if (cond < THRESH)
    {
        GramInv = Ginv;
    }
    else
    {
        int sz = Gram.getRows();
        Matrix I(sz, sz);
        I.setIdentity();
        Matrix Greg = Gram + (I * lambda);
        GramInv = Greg.inverse();
    }
    if (underdetermined)
    {
        // x = Aᵀ (G⁻¹ b)
        Vector t = GramInv * (*(this->mpb));
        Vector x = At * t;
        return x;
    }
    else
    {
        // x = (G⁻¹ Aᵀ) b
        Matrix GinvAt = GramInv * At;
        Vector x = GinvAt * (*(this->mpb));
        return x;
    }
}
