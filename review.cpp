#include <iostream>
#include <fstream>
using namespace std;

float add(float a, float b){cout<<"Float was called"<<endl; return 1.0 +  a + b;}
int add(int a, int b){cout<<"Int was called"<<endl; return a + b;}

int main_1(){
    float a = 1.5;
    float b = 3.4;
    int c = 1;
    cout<<add(1, 3.4); // int và double nên chuyển double sang int nên called int int
    // add(c, b); ambiguous
    // add(b, c); ambiguous
    cout<<add(1, 2); // int int called int int
    cout<<add(a, b); // float float called float float
    // cout<<add(10.0, 20.0); ambiguous do double double chuyển sang int int hay float float đều tốn như nhau, không xác định được
    return 0;
}
class Point{
    private:
        int data;
    public:
        Point():data(0){};
        Point(int data): data(data){};
        // Point(const Point& point){
        //     this->data = point.data;
        // };
        Point& operator=(const Point& point){
            if(this != &point){
                data = point.data;
                return *this;
            }
            else{
                return *this;
            }
        };
        void print(){
            cout<<"Data is: "<<data<<endl;
            // cout<<"Datapoint printed in Data is: "<<b.datapoint<<endl; inaccessible since DataPoint is declared as Friend in Point but Point is not declared as friend with DataPoint
        }
    friend class DataPoint;
};
class DataPoint{
    private:
        int datapoint;
    public:
        DataPoint():datapoint(0){};
        void print(const Point& a){
            cout<<"Data of point printed in datapoint: "<< a.data<<endl;
        };
};
int main_2(){
    Point a(1);
    Point b = a; // copy constructor
    Point(c);
    c = a; // = operator
    // c = b;
    // a.print();
    // b.print();
    b.print();
    c.print();
    return 0;
}

int main_3(){
    Point a(1);
    DataPoint b;
    b.print(a); // b is declared as Friend in a
    return 0;
}

int file_manipulation(){
    ifstream infile("path/to/file"); // infile can be anything
    int value,n;
    int sum = 0;
    infile >> n; //Get first symbol in file, infile read value according to n
    // std::string line;
    // while (std::getline(file, line)) { ... } // these gonna read lines
    // file.read(buffer, size); these gonna read a blocka according to the buffer
    int n, x;
	std::ofstream fout("Ex2file"); // Overwrite everything in Ex2file
	std::cout<<"Input the number of integers:";
	std::cin >> n;
	fout<<n<<std::endl;
	std::cout<<"Input an array of integers:";
	for (int i=0; i<n;i++)
	{
		std::cin>>x;
		fout<<x<<" ";
	}
	fout.close();
    infile.close();
}
int constant(){
    char* message;
    char *p = message;
    char* const p = message; // p cannot point to another address
    const char* p = message; // message cannot be modified through p
}   

void pointers(){
    int x;
    void* ptr = &x;
    // *ptr;  // ❌ error: compiler doesn't know size or type
    int* intPtr = (int*)ptr;
    std::cout << *intPtr << std::endl;

}
