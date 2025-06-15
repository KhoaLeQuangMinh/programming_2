#include <iostream>
#include <string>
using namespace std;

class Shape{
    private:
        string color;
    public:
        Shape(): color("Red"){};
        virtual void draw(){
            cout<<"Color: "<<color<<endl;
            cout<<"This draws a shape"<<endl;
        };
};

class Square: public Shape{
    private:
        int length;
        int width;
    public:
        Square(): Shape(), length(10){
            width = length;
        };
        void draw(){
            cout<<"Length: "<<length<<endl;
            cout<<"Width: "<<width<<endl;
            cout<<"This draws a square"<<endl;
        };
};
class Circle: public Shape{
    private:
        int radius;
    public:
        Circle(): Shape(),radius(5){};
        void draw(){
            cout<<"Radius: "<<radius<<endl;
            cout<<"This draws a circle"<<endl;
        };
};
class Triagle: public Shape{
    private:
        int base;
        int height;
    public:
        Triagle(): Shape(), base(10), height(5){};
        void draw(){
            cout<<"Base: "<<base<<endl;
            cout<<"Height: "<<height<<endl;
            cout<<"This draws a triangle"<<endl;
        };
};

int main(){
    Shape *shape[3];
    shape[0] = new Square();
    shape[1] = new Circle();
    shape[2] = new Triagle();
    for(int i = 0; i < 3; i++){
        shape[i]->draw();
    };
};