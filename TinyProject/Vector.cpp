#include <iostream>
#include "Vector.h"
#include <string>
using namespace std;

Vector::Vector(): mSize(0), mData(NULL){};
Vector::Vector(const Vector& other){
    mSize = other.mSize;
    mData = new double[mSize];
    for(int i = 0; i < mSize; i++){
        mData[i] = other.mData[i];
    }
};
Vector::Vector(int mSize): mSize(mSize){
    mData = new double[mSize];
};
int Vector::getSize(){return mSize;};
const double* Vector::getData()const{return mData;};

Vector& Vector::operator =(const Vector& other){
    if (this == &other) return *this;
    delete[] mData;
    mSize = other.mSize;
    mData = new double[mSize];
    for(int i = 0; i < mSize; i++){
        mData[i] = other.mData[i];
    }
    return *this;
};
Vector::~Vector(){delete[] mData;};
// Vector add Vector
Vector Vector::operator +(Vector other){
    Vector temp(mSize);
    if(mSize != other.mSize){
        throw CustomException("Addition of 2 vectors must be of the same size!");
    }
    for(int i = 0; i < mSize; i++){
        temp.mData[i] =  mData[i] + other.mData[i];
    }
    return temp;
};
// Vector subtract Vector
Vector Vector::operator -(Vector other){
    Vector temp(mSize);
    if(mSize != other.mSize){
        throw CustomException("Subtraction of 2 vectors must be of the same size!");
    }
    for(int i = 0; i < mSize; i++){
        temp.mData[i] =  mData[i] - other.mData[i];
    }
    return temp;
};
// Dot product of 2 Vectors
double Vector::operator *(Vector other){
    double dotProduct = 0;
    if(mSize != other.mSize){
        throw CustomException("Dot product of 2 vectors must be of the same size!");
    }
    for(int i = 0; i < mSize; i++){
        dotProduct +=  mData[i] * other.mData[i];
    }
    return dotProduct;
};
// Vector multiply by scalar
Vector Vector::operator *(double scalar){
    Vector temp(mSize);
    for(int i = 0; i < mSize; i++){
        temp.mData[i] =  mData[i]*scalar;
    }
    return temp;
};   
Vector operator *(double scalar, Vector other){
    int size = other.getSize();
    Vector temp(size);
    for(int i = 0; i < size; i++){
        temp[i] =  other.getData()[i]*scalar;
    }
    return temp;
};
//Unary add Vector++
Vector Vector::operator ++(int){
    Vector temp(mSize);
    temp = *this;
    for(int i = 0; i < mSize; i++){
        mData[i]++;
    }
    return temp;
}; 
//Unary add ++Vector
Vector& Vector::operator ++(){
    for(int i = 0; i < mSize; i++){
            mData[i]++;
        }
    return *this;
};
//Unary subtract Vector--
Vector Vector::operator --(int){
    Vector temp(mSize);
    temp = *this;
    for(int i = 0; i < mSize; i++){
        mData[i]--;
    }
    return temp;
};
//Unary subtract --Vector
Vector& Vector::operator --(){
    for(int i = 0; i < mSize; i++){
            mData[i]--;
    }
    return *this;
};
// [] overwrite
double& Vector::operator [](int idx){
    if(idx > mSize-1){
        throw CustomException("Index out of range!");
    }
    return mData[idx];
};
// () overwrite
double& Vector::operator ()(int idx){
    return this->mData[idx-1];
};

void Vector::swapRows(int i, int j) {
    if (i == j) return;
    if (i < 0 || i >= mSize || j < 0 || j >= mSize)
        throw CustomException("Index out of bounds!");
    swap(mData[i], mData[j]);
}

void Vector::print(){
    cout<<"Value of vector is: "<<endl;
    for(int i = 0; i < mSize; i++){
        cout<<mData[i]<<endl;
    }
};

