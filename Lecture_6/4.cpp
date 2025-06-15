#include <iostream>
using namespace std;
#include <string>

class A1{
    public:
        A1(){
            cout<<"A1 constructor"<<endl;
        }
        ~A1(){
            cout<<"A1 destructor"<<endl;
        }
};

class A2{
    public:
        A2(){
            cout<<"A2 constructor"<<endl;
        }
        ~A2(){
            cout<<"A2 destructor"<<endl;
        }
};
class B1{
    public:
        B1(){
            cout<<"B1 constructor"<<endl;
        }
        ~B1(){
            cout<<"B1 destructor"<<endl;
        }
};
class B2{
    public:
        B2(){
            cout<<"B2 constructor"<<endl;
        }
        ~B2(){
            cout<<"B2 destructor"<<endl;
        }
};
class C1: public A1, public A2{
    public:
        C1(){
            cout<<"C1 constructor"<<endl;
        }
        ~C1(){
            cout<<"C1 destructor"<<endl;
        }
};
class C2: public B1, public B2{
    public:
        C2(){
            cout<<"C2 constructor"<<endl;
        }
        ~C2(){
            cout<<"C2 destructor"<<endl;
        }
};
class D: public C1, public C2{
    public:
        D(){
            cout<<"D constructor"<<endl;
        }
        ~D(){
            cout<<"D destructor"<<endl;
        }
};
int main(){
    D d;
    return 0;
}
