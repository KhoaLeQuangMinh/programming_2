#include <iostream>
using namespace std;

class Math {
public:
    int add(int a, int b) { return a + b; }
    double add(double a, double b) { return a + b; }
};

int main() {
    Math obj;
    cout << obj.add(5, 3) << endl;      // Calls add(int, int)
    cout << obj.add(2.5, 3.1) << endl;  // Calls add(double, double)
    return 0;
}