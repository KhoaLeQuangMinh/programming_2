#include <iostream>
#include <string>
using namespace std;

class Rational{
    private:
        int Denomenator;
        int Numerator;
        static int gcd (int a, int b) {
            if (b == 0)
                return a;
            else
                return gcd (b, a % b);
        } 
        void Reduce(){
            int Gcd = gcd(Numerator, Denomenator);
            Numerator = Numerator/Gcd;
            Denomenator = Denomenator/Gcd;

            if (Denomenator < 0) {
                Numerator = -Numerator;
                Denomenator = -Denomenator;
            }
        }
    public:
        Rational(): Denomenator(1), Numerator(1){};
        Rational(int numerator): Denomenator(1), Numerator(numerator){};
        Rational(int numerator, int denomenator) : Denomenator(denomenator), Numerator(numerator){
            while(Denomenator == 0){
                cout << "Denomenator can not be 0! Enter again"<< endl;
                cin >> denomenator;
                Denomenator = denomenator;
            };
            Reduce();
        };
        void changeDenomenator(int denomenator){
            Denomenator = denomenator;
            while(Denomenator == 0){
                cout << "Denomenator can not be 0! Enter again"<< endl;
                cin >> denomenator;
                Denomenator = denomenator;
            };
            Reduce();
        }
        void changeNumerator(int numerator){
            Numerator = numerator;
            Reduce();
        }
        void showValue() const{
            cout << Numerator << "/" << Denomenator << endl;
        }
};

int main(){
    Rational a(5); // Output 5/1
    Rational b; // Output 1/1
    Rational c(20,-5); // Output -4/1
    Rational d(1,0); // Would make user prompt again the denomenator
    a.showValue();
    b.showValue();
    c.showValue();
    d.showValue();
    c.changeDenomenator(-60);
    c.showValue(); // Would result in 1/15 since the previous fraction would be -4 and now it be -4/-60 which is 1/15
    return 0;
}
