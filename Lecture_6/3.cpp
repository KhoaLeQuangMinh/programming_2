#include <iostream>
#include <string>
using namespace std;

class Shape{
    private:
        string color;
    public:
        Shape(string color): color(color){};
        virtual void print(){
            cout<<"Color: "<<color<<endl;
            cout<<"This is a shape"<<endl;
        };
};

class Rectangle: public Shape{
    private:
        int length;
        int width;
    public:
        Rectangle(string color, int l, int w): Shape(color), length(l), width(w){};
        void print(){
            cout<<"Length: "<<length<<endl;
            cout<<"Width: "<<width<<endl;
            cout<<"This is a rectangle"<<endl;
        };
};
class Circle: public Shape{
    private:
        int radius;
    public:
        Circle(string color, int r): Shape(color),radius(r){};
        void print(){
            cout<<"Radius: "<<radius<<endl;
            cout<<"This is a circle"<<endl;
        };
};


int main(){
    Shape shape("Red");
    Rectangle rectangle("blue", 10, 5);
    Circle circle("Yellow", 7);
    shape.print();
    rectangle.print();
    circle.print();
};