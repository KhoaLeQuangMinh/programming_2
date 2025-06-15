#include <iostream>
#include <string>
using namespace std;

class Student{
    private:
        string name;
        int age;
        int intake;
        string major;
        string fav_food;
    public:
        Student(string name, int age, int intake, string major, string fav_food): name(name), age(age), intake(intake), major(major), fav_food(fav_food){}
        void Display(){
            cout<< "My name is "<< name <<" I'm "<< age << " I'm studying "<<major<<intake<<" My favorite food is "<<fav_food<<endl;
        }
        ~Student(){}
};

int main(){
    Student k("Khoa", 19, 2023, "CSE", "Fried Chicken");
    k.Display();
    return 0;
}