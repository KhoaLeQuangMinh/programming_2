#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Version A
// class Manufacturer{
//     private:
//         int id;
//         string location;
//     public:
//         Manufacturer(int id, string location): id(id), location(location){};
//         void describe(){
//             cout<<"Manufacturer ID is: "<< id<< " at "<<location<<endl;
//         }
// };

// class Device{
//     private:
//         string name;
//         double price;
//         Manufacturer manufacturer;
//     public:
//         Device(string name, double price, int id, string location): name(name), price(price), manufacturer(id, location){};
//         void describe(){
//             cout<<"Device name is: "<< name<< " at "<<price<<endl;
//             manufacturer.describe();
//         }
// };

// Version B
class Manufacturer{
    private:
        int id;
        string location;
    public:
        Manufacturer(int id, string location): id(id), location(location){};
        void describe(){
            cout<<"Manufacturer ID is: "<< id<< " at "<<location<<endl;
        }
};

class Device{
    private:
        string name;
        double price;
        Manufacturer* manufacturer;
    public:
        Device(string name, double price, int id, string location): name(name), price(price){
            manufacturer = new Manufacturer(id, location);
        };
        void describe(){
            cout<<"Device name is: "<< name<< " at "<<price<<endl;
            manufacturer->describe();
        }
        ~Device(){
            delete manufacturer;
        };
};

int main_1(){
    Device mouse("mouse", 2.5, 9725, "Vietnam");
    mouse.describe();
    return 0;
}

class Beverage{
    private:
        float price;
        float topping_price;
        float condiment_price;
    public:
        Beverage():price(0), topping_price(0), condiment_price(0){};
        Beverage(float price, float topping_price, float condiment_price): price(price), topping_price(topping_price), condiment_price(condiment_price){};
        Beverage(const Beverage& other){
            price = other.price;
            topping_price = other.topping_price;
            condiment_price = other.condiment_price;
        };
        Beverage operator+(const Beverage& other){
            Beverage temp;
            temp.condiment_price = condiment_price + other.condiment_price;
            temp.price = price + other.price;
            temp.topping_price = topping_price + other.topping_price;
            return temp;
        }
        int operator==(const Beverage& other){
            if(price == other.price && condiment_price == other.condiment_price && topping_price == other.topping_price){
                return 1;
            }
            return 0;
        }
        void describe(){
            cout<<"Price is: "<< price;
            cout<<" Condiment_price is: "<< condiment_price;
            cout<<" Topping_price is: "<< topping_price<<endl;
        };


};

int main_2(){
    Beverage b0;
    b0.describe();
    Beverage b1(10.5, 2.3, 1.2);
    b1.describe();
    Beverage b2(15, 2.2, 0.5);
    b2.describe();
    Beverage b3(b1);
    b3.describe();
    b3 = b1 + b2;
    b3.describe();
    cout<< "Is b3 == b1"<< (b3 == b1)<<endl;
    b3 = b1;
    b3.describe();
    cout<< "Is b3 == b1"<< (b3 == b1)<<endl;
    return 0;
}

class People{
    protected:
        string name;
        int yob;
    public:
        People(): name("Unknown"), yob(0){};
        People(string name, int yob): name(name), yob(yob){};
        virtual void describe() = 0;
};

class Student: public People{
    private:
        string grade;
    public:
        Student(string name, int yob, string grade): People(name, yob), grade(grade){};
        void describe(){
            cout<<"Name is: "<< name<< " Born in: "<< yob<< "Grade is: "<< grade<< endl; 
        };
    
};

class Teacher: public People{
    private:
        string subject;
    public:
        Teacher(string name, int yob, string subject): People(name, yob), subject(subject){};
        void describe(){
            cout<<"Name is: "<< name<< " Born in: "<< yob<< "Subject is: "<< subject<< endl; 
        };
    
};

class Doctor: public People{
    private:
        string specialist;
    public:
        Doctor(string name, int yob, string specialist): People(name, yob), specialist(specialist){};
        void describe(){
            cout<<"Name is: "<< name<< " Born in: "<< yob<< "Specialist is: "<< specialist<< endl; 
        };
    
};

class Ward{
    private:
        string name;
        vector<People*> people;
    public:
        Ward(string name): name(name){};
        void addPerson( People* person){
            people.push_back(person);
        };
        void describe(){
            cout<<"Ward is: "<< name<<endl;
            for(int i = 0; i < people.size(); i++){
                people[i]->describe();
            }
        };
};

// THE REST OF QUESTION 3 IS THE SAME AS THE PRACTICE
// THIS IS THE QUESTION 3 FROM TEST 2

template<class T>
class Data{
    private:
        T first;
        T second;
    public:
        Data(T f, T s): first(f), second(s){};
        T sum(){
            T temp;
            temp = first + second;
            return temp;
        }

};

class Circle{
    private:
        int radius;
    public:
        Circle(int radius = 0): radius(radius){};
        Circle(const Circle& other){
            radius = other.radius;
        };
        Circle& operator=(const Circle& other){
            if(this != &other){
                radius = other.radius;
            }
            return *this;
        }
        
        Circle operator+(const Circle& other){
            Circle temp;
            temp.radius = radius + other.radius;
            return temp;
        }

        void describe(){
            cout<< "Radius of circle is: "<< radius<<endl;
        }
};

int main_3(){
    Data<int> intData(5,6);
    cout<< "sum 1: "<< intData.sum()<< endl;

    Circle circle1(5);
    Circle circle2(7);

    Data<Circle> circleData(circle1, circle2);
    Circle sumCircle = circleData.sum();
    sumCircle.describe();
    return 0;
};



int main(){
    cout<< "QUESTION 1"<<endl;
    main_1();
    cout<< "QUESTION 2"<<endl;
    main_2();
    cout<< "QUESTION 3"<<endl;
    main_3();
    return 0;
}
