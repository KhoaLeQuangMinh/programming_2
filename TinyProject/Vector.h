#pragma once
#include <string>
#include <cassert>
using std::string;
class CustomException{
    private:
        string message;
    public:
        CustomException(const char* msg):message(msg){};
        const char* what() const throw(){
            return message.c_str();
        }
};
class Vector{
    private:
        int mSize;
        double * mData;
    public:
        Vector();
        Vector(const Vector& other);
        Vector(int mSize);
        ~Vector();
        int getSize();
        const double* getData()const;
        // Vector add Vector
        Vector& operator =(const Vector& other);
        Vector operator +(Vector other);
        // Vector subtract Vector
        Vector operator -(Vector other);
        // Dot product of 2 Vectors
        double operator *(Vector other);
        // Vector multiply by scalar
        Vector operator *(double scalar);   
        //Unary add Vector++
        Vector operator ++(int); 
        //Unary add ++Vector
        Vector& operator ++();
        //Unary subtract Vector--
        Vector operator --(int);
        //Unary subtract --Vector
        Vector& operator --();
        // [] overwrite
        double& operator [](int idx);
        // () overwrite
        double& operator ()(int idx);
        void swapRows(int i, int j);
        void print();
};
//Scalar multiply by Vector
Vector operator*(double a, Vector b);
