#include <iostream>
#include <cmath>
using namespace std;

class Complex{
    private:
        double real;
        double img;
    public:
        Complex(): real(0), img(0){};
        Complex(double real, double img): real(real), img(img){};
        Complex operator =(const Complex &other){
            this->real = other.real;
            this->img = other.img;
            return *this;
        }
        int operator >(Complex other){
            double this_value = sqrt(this->real*this->real + this->img*this->img);
            double other_value = sqrt(other.real*other.real + other.img*other.img);
            if (this_value > other_value){
                return 1;
            }
            return 0;
        }
        int operator <(Complex other){
            double this_value = sqrt(this->real*this->real + this->img*this->img);
            double other_value = sqrt(other.real*other.real + other.img*other.img);
            if (this_value < other_value){
                return 1;
            }
            return 0;
        }
        void print(){
            cout<<"The complex is: "<<this->real<<" "<<this->img<<endl;
        }
};
int main(){
    Complex* arr;
    int n;
    cout<<"Size of array: ";
    cin>>n;
    arr = new Complex[n];
    for (int i = 0 ; i < n; i++){
        double a;
        double b;
        cout<<"Input a and b for "<<i+1<<" Complex number ";
        cin>>a>>b;
        arr[i] = Complex(a, b);

    }
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(arr[i] < arr[j]){
                Complex temp;
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for (int i = 0 ; i < n; i++){
        arr[i].print();
    }   
    delete[] arr;
    return 0;
}