#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

struct Complex{ // making complex number
    double real, imaginary;

    double magnitude(){
        return sqrt(real* real + imaginary* imaginary); // calculate magnitude
    }
};

void Swap(Complex *a, Complex *b){ // swap
    Complex temp = *a;
    *a = *b;
    *b = temp;
} 


int main(){
    std::ifstream infile("In.txt"); 
    float value;
    int i = 0;
    int n;
    infile >> n; // read the size
    Complex arr[n]; 
    double num1, num2;
    while (i < n) {
        infile >> num1 >> num2;
        Complex x = {num1, num2}; // make complex number
        arr[i] = x; // append to a list
        i++;
    }
    infile.close();
    
    for(int j = 0; j < i; j++ ){
        for(int k = 0; k < i - j - 1; k++){
            if(arr[k].magnitude() < arr[k+1].magnitude()){
                Swap(&(arr[k]), &(arr[k+1]));
            }
        }
    } // Bubble sort

    if(n<5){
        for(int j = 0; j < n; j++){
            cout << "The complex number is: " << arr[j].real << " " << arr[j].imaginary << "i" << " with magnitude of: " << arr[j].magnitude() <<endl;
        } // Print all magnitude numbers
    } else{
        for(int j = 0; j < 5; j++){
            cout << "The complex number is: " << arr[j].real << " " << arr[j].imaginary << "i" << " with magnitude of: " << arr[j].magnitude() <<endl;
        } // Print 5 largest magnitude numbers
    }
    return 0;
}