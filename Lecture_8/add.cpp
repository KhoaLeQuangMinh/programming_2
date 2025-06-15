#include <iostream>
#include <string>

using namespace std;

class Simple{
    private:
        int a;
    public:
        Simple(int x = 0): a(x) {};
        Simple operator +(const Simple b) const {
            Simple temp;
            temp.a = this -> a + b.a;
            return temp;
        }
        Simple operator -(const Simple b) const{
            Simple temp;
            temp.a = this -> a - b.a;
            return temp;
        }
        //Prefix
        Simple& operator ++(){
            cout << "Prefix ++ operator called" << endl;
            a++;
            return *this;
        }
        //Postfix
        const Simple operator ++(int){
            cout << "Postfix ++ operator called" << endl;
            Simple temp = *this;
            a++;
            return temp;
        }
        //Prefix
        Simple& operator --(){
            cout << "Prefix -- operator called" << endl;
            a--;
            return *this;
        }
        //Postfix
        const Simple operator --(int){
            cout << "Postfix -- operator called" << endl;
            Simple temp = *this;
            a--;
            return temp;
        }
        void print_value(){
            cout << "Value of a: " << a << endl;
        }
};

int main(){
    Simple s1(10);
    Simple s2(20);
    Simple s3(30);
    Simple sum;
    sum = s1-- + s2++ + --s3; // Postfix -- called and Postfix ++ called and Prefix -- called
    sum.print_value();  // Expect: 10 (s1) + 20 (s2) + 29 (s3) = 59
    s1.print_value();  // s1 = 9
    s2.print_value();  // s2 = 21
    s3.print_value();  // s3 = 29

    (++s1).print_value();       //Prefix called 10
    (++(++s1)).print_value();   //Predix called twice 12 
}