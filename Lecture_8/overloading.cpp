#include <iostream>
#include <string>
using namespace std;

class Simple{
    private:
        int a;
    public:
        //Prefix
        Simple(int x = 0): a(x) {};
        Simple& operator ++(){
            cout << "++ operator called" << endl;
            a++;
            return *this;
        }
        //Postfix
        Simple operator ++(int){
            cout << "++ operator called" << endl;
            Simple temp = *this;
            this->a++;
            return temp;
        }
        void print_value(){
            cout << "Value of a: " << a << endl;
        }
};

int main() {
    Simple s;
    Simple s1 = ++s;
    Simple s2 = s++;
    s.print_value();
    s1.print_value();
    s2.print_value();
    return 0;
}