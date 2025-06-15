#include <iostream>
using namespace std;

class Time{
    private:
        int hour;
        int minute;
        int second;
    public:
        Time():hour(0), minute(0), second(0){};
        Time(int hour, int minute, int second): hour(hour), minute(minute), second(second){};
        Time operator +(Time b){
            Time temp;
            temp.second = (this->second+b.second)%60;
            temp.minute += (this->second+b.second)/60;
            temp.minute = (temp.minute + this->minute+b.minute)%60;
            temp.hour += (this->minute+b.minute)/60;
            temp.hour = (temp.hour + this->hour+b.hour)%24;
            return temp;
        };
        int operator >(Time b){
            int seconds_this = 0;
            seconds_this += this->second + this->minute*60 + this->hour*3600;
            int seconds_b = 0;
            seconds_b += b.second + b.minute*60 + b.hour*3600;
            if(seconds_this > seconds_b){
                return 1;
            }
            return 0;
        }
        Time(const Time &other): second(other.second), minute(other.minute), hour(other.hour){};
        Time operator =(Time other){
            this->hour = other.hour;
            this->minute = other.minute;
            this->second = other.second;
            return *this;
        }
        void print(){
            cout<<"Hour: "<<this->hour<<" Minute: "<<this->minute<<" Second: "<< this->second<<endl;
        };
};

int main(){
    Time a(23,59,59);
    a.print();
    Time b;
    b = a;
    b.print();
    Time c;
    c = a + b;
    c.print();
    int x;
    x = b > a;
    if(x == 1){
        cout<<"b is larger than a"<<endl;
    }
    else{
        cout<<"b is not larger than a"<<endl;
    };
    a = b = c;
    a.print();
    return 0;
}