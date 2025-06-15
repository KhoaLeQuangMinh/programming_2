#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>

using namespace std;
class Shape{
    protected:
        string type;
        string label;
        double values[10];
        int length;
    public: 
        Shape(string type, string label, double input[], int n): type(type), label(label), length(n){
            for(int i = 0; i < n; i++){
                values[i] = input[i];
            };
        };
        virtual double area() = 0;
        virtual ~Shape(){};
};
class Square: public Shape{
    public:
        Square(string label, double input[], int n): Shape("Square", label, input, n){};
        double area() override {
            double sideLength = std::abs(values[2] - values[0]);
            return sideLength * sideLength;
        }
};
class Rectangle: public Shape{
    public:
        Rectangle(string label, double input[], int n): Shape("Rectangle", label, input, n){};
        double area() override {
            double length = std::abs(values[2] - values[0]);
            double width = std::abs(values[3] - values[1]);
            return length * width;
        }
};
class Triagle: public Shape{
    public:
        Triagle(string label, double input[], int n): Shape("Triangle", label, input, n){};
        double area() override {
            double x1 = values[0], y1 = values[1];
            double x2 = values[2], y2 = values[3];
            double x3 = values[4], y3 = values[5];

            return std::abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0;
        }
};
class Parallelogram: public Shape{
    public:
        Parallelogram(string label, double input[], int n): Shape("Parallelogram", label, input, n){};
        double area() override {
            double x1 = values[0], y1 = values[1];
            double x2 = values[2], y2 = values[3];
            double x3 = values[4], y3 = values[5];
            double x4 = values[6], y4 = values[7];

            double ABx = x2 - x1, ABy = y2 - y1;
            double ADx = x4 - x1, ADy = y4 - y1;

            double crossProduct = std::abs(ABx * ADy - ABy * ADx);
            return crossProduct;
        }
};
int main() {
    ifstream file("input.txt"); 
    string line;

    int numLines;
    file >> numLines;
    file.ignore();
    ofstream outputFile("output.txt");

    outputFile << numLines << endl;
    for (int i = 0; i < numLines; ++i) {
        std::getline(file, line);
        std::istringstream iss(line);

        char label;
        iss >> label;

        double values[10];
        int count = 0;

        while (iss >> values[count]) {
            ++count;
        }

        cout << "Label: " << label << "\nNumbers: ";
        for (int j = 0; j < count; ++j) {
            std::cout << values[j] << " ";
        }
        cout << "\n";
        double areaResult = 0.0;
        switch (label) {
            case 's': {
                Square square("Square", values, count);
                cout << "Area of Square: " << square.area() << endl;
                areaResult = square.area();
                break;
            }
            case 'r': {
                Rectangle rectangle("Rectangle", values, count);
                cout << "Area of Rectangle: " << rectangle.area() << endl;
                areaResult = rectangle.area();
                break;
            }
            case 't': {
                Triagle triangle("Triangle", values, count);
                cout << "Area of Triangle: " << triangle.area() << endl;
                areaResult = triangle.area();
                break;
            }
            case 'p': {
                Parallelogram parallelogram("Parallelogram", values, count);
                cout << "Area of Parallelogram: " << parallelogram.area() << endl;
                areaResult = parallelogram.area();
                break;
            }
            default:
                cout << "Unknown shape type" << endl;
        }
        outputFile << label << " ";
        for (int j = 0; j < count; ++j) {
            outputFile << values[j] << " ";
        }
        outputFile << "-> " << areaResult << endl;
    }
    file.close();
    outputFile.close();
    return 0;
}
