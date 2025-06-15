#include <iostream>
#include <string>
using namespace std;

class Person{
    private:
        string name;
        int age;
    public:
        Person(string name, int age): name(name), age(age){}
        virtual void SetAge(int age){
            this->age = age;
        }
        int getage(){
            return age;
        }
        void sayHello() {
            cout << "Hello!" << endl;
        }
        virtual ~Person(){}
};

class Student: public Person{
    public:
        Student(string name, int age): Person(name, age){}
        void GoToClass(){
            cout<< "I'm going to class"<<endl;
        }
        void SetAge(int age){
            Person::SetAge(age);
        }
        void ShowAge(){
            cout<<"My age is: " << getage() << " years old"<<endl;
        }
        void greet() {
            cout << "Hi, I'm a student!" << endl;
        }
        ~Student(){}
};

class Teacher: public Person{
    private:
        string subject;
    public:
        Teacher(string name, int age): Person(name, age){}
        void Explain(){
            cout<< "Explanation begins"<<endl;
        }
        ~Teacher(){}
};

class StudentAndTeacherTest{
    public:
        void Main(){
            Person p("Khoa", 19);
            p.sayHello();
            Student s("Khang", 19);
            s.SetAge(21);
            s.ShowAge();
            s.greet();
            Teacher t("Hiếu", 30);
            t.sayHello();
            t.Explain();
        }
        ~StudentAndTeacherTest(){}
};

int main(){
    StudentAndTeacherTest a;
    a.Main();
    return 0;
}
