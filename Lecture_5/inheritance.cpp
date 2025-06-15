#include <iostream>

using namespace std;


class Book{
    private:
        string Title;
        string Format;
        int Price;
        int YearPublished;
        string Publisher;
        string Author;
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
        void display() const {
            std::cout << Title << " by " << Author << " (" << YearPublished << ")" << std::endl;
        }
};
class Novel: public Book{
    private:
        string Genre;
    public:
        Novel() : Book(), Genre("Fiction") {}

        Novel(string Author, string Title, string Format, int Price, int YearPublished, string Publisher, string Genre)
            : Book(Author, Title, Format, Price, YearPublished, Publisher), Genre(Genre) {}
    
        void display() const {
            cout << "Genre: " << Genre << endl;
    }
};

int main(){
    Novel n("J.R.R. Tolkien", "The Hobbit", "Hardcover", 25, 1937, "Allen & Unwin", "Fantasy");
    n.Novel::display();
    n.Book::display();
    return 0;
}