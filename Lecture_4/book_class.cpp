#include <iostream>
#include <string>
using namespace std;

class Book{
    private:
        string Author;
        string Title;
        string Format;
        int Price;
        int YearPublished;
        string Publisher;
    public:
        Book() : Author("Unknown"), Title("Unknown"), Format("Unknown"), Price(0), YearPublished(0000), Publisher("Unknown"){};
        Book(string Author, string Title, string Format, int Price, int YearPublished, string Publisher){
            this->Author = Author;
            this->Title = Title;
            this->Format = Format;
            this->Price = Price;
            this->YearPublished = YearPublished;
            this->Publisher = Publisher;
        };
        void display() {
            std::cout << Title << " by " << Author << " (" << YearPublished << ")" << std::endl;
        }
};

int main(){
    Book a("J.K. Rowling", "Harry Potter", "Hardcover", 39, 1997, "Bloomsbury");
    a.display();
    return 0;
}