#include <iostream>
#include <string>
using namespace std;

class Mother{
    private:
        string name;
    public:
        Mother(string name): name(name){}
        virtual void Display(){
            cout<< "The mother is "<< name << endl;
        } 
        string get_name(){
            return name;
        }
        virtual ~Mother(){}
};

class Daughter: public Mother{
    public:
        Daughter(string name): Mother(name){}
        void Display(){
            cout<< "The daughter is "<< get_name() << endl;
        }
        ~Daughter(){};
};


int main(){
    Daughter Bin("Bin");
    Bin.Display();
    return 0;
}