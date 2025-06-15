#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

class CSStudent{
    private:
        int studentID;
        string studentName;
        string studentAddress;
        string scholarship;
    public:
        CSStudent(): studentID(0), studentName("Unknown"), studentAddress("Unknown"), scholarship("None"){};
        CSStudent(int studentID, string studentName, string studentAddress, string scholarship): studentID(studentID), studentAddress(studentAddress), studentName(studentName), scholarship(scholarship){};
        int getStudentID(){return studentID;}
        string getName(){return studentName;}
        string getAddress(){return studentAddress;}
        string getScholarship(){return scholarship;}
        void setStudentID(int ID){studentID = ID;}
        void setName(string name){studentName = name;}
        void setAddress(string address){studentAddress = address;}
        void setScholarship(string scholarship){this->scholarship = scholarship;}
        void print(){
            cout<<"Name is: "<< studentName<< " - ID: "<< studentID<< " - Address: "<< studentAddress<< " - Scholarship status: "<< scholarship<<endl;
        }

};

class Quadrilaterals{
    protected:
        double widths;
        double heights;
        double area;
    public:
        Quadrilaterals(double widths, double heights): widths(widths), heights(heights){};
        virtual void print(){
            cout<<"Area is: "<< area<< endl;
        };
        virtual double areaCalculate() = 0;
};

class Rectangle: public Quadrilaterals{
    public:
        Rectangle(double heights, double widths):Quadrilaterals( widths, heights) {};
        double areaCalculate(){
            area = heights*widths;
            return  area;
        }
        void print(){
            areaCalculate();
            cout<<"This is a Rectangle and the ";
            Quadrilaterals::print();
        }
};

class Parallelogram: public Quadrilaterals{
    public:
        Parallelogram(double heights, double widths):Quadrilaterals(widths, heights) {};
        double areaCalculate(){
            area = heights*widths;
            return  area;
        }
        void print(){
            areaCalculate();
            cout<<"This is a Parallelogram and the ";
            Quadrilaterals::print();
        }
};

class Trapezium: public Quadrilaterals{
    private:
        double small_widths;
    public:
        Trapezium(double h, double w, double sw):Quadrilaterals(w, h), small_widths(sw) {};
        double areaCalculate(){
            area = (widths + small_widths)/2 * heights;
            return  area;
        }
        void print(){
            areaCalculate();
            cout<<"This is a Trapezium and the ";
            Quadrilaterals::print();
        }
};

class Complex{
    private:
        double img;
        double real;
    public:
        Complex(): img(0), real(0){};
        Complex(double img, double real): img(img), real(real){};
        double Modulus(){
            return sqrt(img*img + real*real);
        }
        int operator>(Complex& other){
            if(Modulus() > other.Modulus()){
                return 1;
            }
            return 0;
        }
        Complex& operator=(const Complex& other){
            if(&other == this){
                return *this;
            }
            img = other.img;
            real = other.real;
            return *this;
        }
        void print(){
            cout<<"Complex number is: "<<real<<"+"<<"i"<<img<<" with Modulus of: "<< Modulus()<<endl;
        }

};


int main_2(){
    Quadrilaterals * N[] = {new Rectangle(2,4), new Parallelogram(4,2), new Trapezium(3,4,2)};
    for(int i = 0; i < 3; i++){
        N[i]->print();
    }
    return 0;
}

int main_3(){
    int n;
    cout<<"Insert the length of the list: ";
    cin>>n;
    vector<Complex*> arr;
    double img;
    double real;
    for(int i = 0; i< n; i++){
        cout<<"Input your real, img pair: ";
        cin>>real>>img;
        arr.push_back(new Complex(img, real));
    }
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(arr[i]->Modulus() < arr[j]->Modulus()){
                Complex * temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for(int i = 0; i< n; i++){
        arr[i]->print();
    }
    return 0;
}
int main(){
    cout<<"QUESTION 2"<<endl;
    main_2();
    cout<<"QUESTION 3"<<endl;
    main_3();
}
