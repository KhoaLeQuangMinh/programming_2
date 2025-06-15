#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Version a
// class Course{
//     private:
//         int courseCode;
//         string courseName;
//     public:
//         Course(int courseCode, string courseName): courseCode(courseCode), courseName(courseName){};
//         void describe(){
//             cout<<"Course code: "<< courseCode<< " - Course name: "<<courseName<<endl;
//         };
// };

// class Student{
//     private:
//         string name;
//         int studentID;
//         Course course;
//     public:
//         Student(string name, int studentID, int courseCode, string courseName): name(name), studentID(studentID), course(courseCode, courseName){};
//         void describe(){
//             cout<<"Student name: "<< name<<" - Student ID: "<< studentID<<endl;
//             course.describe();
//         }
// };

// Version b
class Course
{
private:
    int courseCode;
    string courseName;

public:
    Course(int courseCode, string courseName) : courseCode(courseCode), courseName(courseName) {};
    void describe()
    {
        cout << "Course code: " << courseCode << " - Course name: " << courseName << endl;
    };
};

class Student
{
private:
    string name;
    int studentID;
    Course *course;

public:
    Student(string name, int studentID, int courseCode, string courseName) : name(name), studentID(studentID)
    {
        course = new Course(courseCode, courseName);
    };
    void describe()
    {
        cout << "Student name: " << name << " - Student ID: " << studentID << endl;
        course->describe();
    }
    ~Student() {
        delete course;
    };
};

int main_1()
{
    Student student("David", 101, 111, "C++");
    student.describe();
    return 0;
}

class Product
{
private:
    double price;
    double weight;
    double discount;

public:
    Product() : price(0), weight(0), discount(0) {};
    Product(double p, double w, double d) : price(p), weight(w), discount(d) {};
    Product(const Product &other)
    {
        price = other.price;
        weight = other.weight;
        discount = other.discount;
    };
    Product operator+(const Product &other)
    {
        Product temp;
        temp.price = price + other.price;
        temp.weight = weight + other.weight;
        temp.discount = discount + other.discount;
        return temp;
    };
    Product &operator=(const Product &other)
    {
        if (this != &other)
        {
            price = other.price;
            weight = other.weight;
            discount = other.discount;
        }
        return *this;
    };
    int operator==(const Product &other)
    {
        if (weight == other.weight && price == other.price && discount == other.discount)
        {
            cout << "Equal" << endl;
            return 1;
        }
        else
        {
            cout << "Not Equal" << endl;
            return 0;
        }
    };
    void describe()
    {
        cout << "Price is: " << price << endl;
        cout << "Weight is: " << weight << endl;
        cout << "Discount is: " << discount << endl;
    };
};

int main_2()
{
    Product m0;
    m0.describe();

    Product m1(10.5, 2.3, 1.2);
    m1.describe();

    Product m2(15, 2.2, 0.5);
    m2.describe();

    Product m3 = m1 + m2;
    m3.describe();

    cout << "Is m3 = m1? " << (m3 == m1) << endl;
    m3 = m1;
    m3.describe();
    cout << "Is m3 = m1? " << (m3 == m1) << endl;
    return 0;
};

class Member
{
private:
    string name;
    int yob;

public:
    Member() : name("Unknown"), yob(0) {};
    Member(string name, int yob) : name(name), yob(yob) {};
    int getYear() { return yob; }

    virtual void describe()
    {
        cout << "Name: " << name << " Year of birth: " << yob<<" ";
    };
    virtual int type_is() = 0;
};
class Participant : public Member
{
private:
    string field;

public:
    Participant() : Member(), field("Unknown") {};
    Participant(string name, int yob, string field) : Member(name, yob), field(field) {};
    void describe()
    {
        Member::describe();
        cout << "Field: " << field << endl;
    };
    int type_is()
    {
        return 0;
    }
};

class Mentor : public Member
{
private:
    string subject;

public:
    Mentor() : Member(), subject("Unknown") {};
    Mentor(string name, int yob, string subject) : Member(name, yob), subject(subject) {};
    void describe()
    {
        Member::describe();
        cout << "Subject: " << subject << endl;
    };
    int type_is()
    {
        return 1;
    }
};

class Coordinator : public Member
{
private:
    string division;

public:
    Coordinator() : Member(), division("Unknown") {};
    Coordinator(string name, int yob, string division) : Member(name, yob), division(division) {};
    void describe()
    {
        Member::describe();
        cout << "Division: " << division << endl;
    };
    int type_is()
    {
        return 2;
    }
};

class Society
{
private:
    string name;
    vector<Member *> members;

public:
    Society() : name("Unknown")
    {
    };
    Society(string name) : name(name)
    {
    };
    void addMember(Member *member)
    {
        members.push_back(member);
    };
    void describe()
    {
        cout << "Society Name: " << name << endl;
        for (int i = 0; i < members.size(); i++)
        {
            members[i]->describe();
        }
    };
    int countCoordinator()
    {
        int count = 0;
        for (int i = 0; i < members.size(); i++)
        {
            if (members[i]->type_is() == 2)
            {
                count++;
            };
        }
        return count;
    };
    void sortBirthYear()
    {
        for (int i = 0; i < members.size(); i++)
        {
            for (int j = i + 1; j < members.size(); j++)
            {
                if (members[i]->getYear() > members[j]->getYear())
                {
                    Member *temp = members[i];
                    members[i] = members[j];
                    members[j] = temp;
                }
            }
        }
    };
    double aveMentorYearOfBirth()
    {
        int sum = 0;
        int count = 0;
        for (int i = 0; i < members.size(); i++)
        {
            if (members[i]->type_is() == 1)
            {
                sum += members[i]->getYear();
                count++;
            };
        }
        return sum / count;
    };
};

int main_3()
{
    Participant participant("Alice", 1995, "Art");
    participant.describe();
    Mentor mentor1("Bob", 1980, "Math");
    mentor1.describe();
    Mentor mentor2("Carol", 1970, "Science");
    mentor2.describe();
    Coordinator coordinator1("David", 1985, "Events");
    Coordinator coordinator2("Thomas", 1980, "Logistics");
    Society society("society1");
    society.addMember(&participant);
    society.addMember(&mentor1);
    society.addMember(&mentor2);
    society.addMember(&coordinator1);
    society.addMember(&coordinator2);
    society.describe();
    int numberOfCoordinators = society.countCoordinator();
    cout << " numberOfCoordinators : " << numberOfCoordinators << endl;
    society.sortBirthYear();
    society.describe();
    cout << " Average year of birth ( Mentors ): " << society.aveMentorYearOfBirth() << endl;
    return 0;
};

int main()
{
    cout << "QUESTION 1" << endl;
    main_1();
    cout << "QUESTION 2" << endl;
    main_2();
    cout << "QUESTION 3" << endl;
    main_3();
};
