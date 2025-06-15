#include <iostream>
#include <string>
using namespace std;

class Animal{
    private:
        string name;
        int age;
    public:
        Animal(string name, int age): name(name), age(age){}
        void set_value(string name, int age){
            this->name = name;
            this->age = age;
        }
        virtual void Display(){
            cout<< name << " "<< age<<endl;
        }
        virtual ~Animal(){}
};

class Dolphin: public Animal{
    private:
        string fact;
    public:
        Dolphin(string name, int age): Animal(name, age), fact("This is a mammal"){}
        void Display(){
            Animal::Display();
            cout<< fact<<endl;
        }
        ~Dolphin(){}
};

class Zebra: public Animal{
    private:
        string fact;
    public:
        Zebra(string name, int age): Animal(name, age), fact("This could cause illusion"){}
        void Display(){
            Animal::Display();
            cout<< fact<<endl;
        }
        ~Zebra(){}
};

int main(){
    Dolphin d("Khang", 21);
    Zebra z("Khoa", 21);
    d.Display();
    z.Display();
    return 0;
}