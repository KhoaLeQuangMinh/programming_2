#include <iostream>
#include <string.h>


using namespace std;

class Person{
    private:
        string name;
        int age;
        string id;
    public:
        Person(): name("Unknown"), age(0), id("Unknown"){}
        Person(string name, int age, string id): name(name), age(age), id(id){}
        string get_name(){
            return name;
        }
        int get_age(){
            return age;
        }
        string get_id(){
            return id;
        }
        void set_name(string name){
            this->name = name;
        }
        void set_age(int age){
            this->age = age;
        }
        void set_id(string id){
            this->id = id;
        }
        virtual ~Person(){}
};

class Employee: public Person{
    private:
        string department;
        double salary;
    public:
        Employee(string department, double salary, string name, int age, string id): Person(name, age, id), department(department), salary(salary){}
        virtual void displayInfo(){
            cout<<get_name()<<" "<< get_age() <<" "<< get_id() <<" "<<department<<salary<<endl;
        }
        ~Employee(){}
};

class Manager: public Employee{
    private:
        int teamSize;
    public:
        Manager(int teamSize, string department, double salary, string name, int age, string id): Employee(department, salary, name, age, id), teamSize(teamSize){}
        void displayInfor(){
            Employee::displayInfo();
            cout<< teamSize <<endl;
        }
        ~Manager(){}
};

class Staff: protected Employee{
    private:
        string shift;
    public:
        

};

int main(){

    return 0;
}