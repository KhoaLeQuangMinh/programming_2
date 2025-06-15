#include <iostream>  
#include <vector>    
#include <algorithm> 


int calculateGCD(int a, int b) {
    while (b) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

class FareyNumber {
private:
    int nominator;  
    int denominator;

   
    void simplify() {
        if (nominator == 0) { 
            denominator = 1;
            return;
        }
        if (denominator < 0) {
            nominator = -nominator;
            denominator = -denominator;
        }
        int common_divisor = calculateGCD(std::abs(nominator), denominator);
        nominator /= common_divisor;
        denominator /= common_divisor;
    }

public:
    // Destructor (empty, as we're not managing raw pointers inside the class)
    ~FareyNumber() {};

    // Constructor: Initializes nominator and denominator.
    // Default values ensure a valid starting fraction (0/1).
    FareyNumber(int no = 0, int de = 1) : nominator(no), denominator(de) {
        // Handle invalid denominator input
        if (denominator == 0) {
            std::cerr << "Warning: Denominator cannot be zero. Setting to 1." << std::endl;
            denominator = 1; // Default to 1 to avoid division by zero
        }
        simplify(); // Always simplify fraction upon creation
    }

    // Copy Constructor: Creates a new FareyNumber object from an existing one.
    FareyNumber(const FareyNumber& a) : nominator(a.nominator), denominator(a.denominator) {
        // No need to call simplify here as the source 'a' should already be simplified
    }

    // Assignment Operator: Assigns the value of one FareyNumber to another.
    FareyNumber& operator=(const FareyNumber& a) {
        if (this != &a) { // Avoid self-assignment
            nominator = a.nominator;
            denominator = a.denominator;
            // No need to simplify here as the source 'a' should already be simplified
        }
        return *this;
    }

    // Operator+ overload: Calculates the mediant of two FareyNumbers.
    // The mediant of a/b and c/d is (a+c)/(b+d).
    // The result is automatically simplified by the constructor.
    FareyNumber operator+(const FareyNumber& other) const {
        return FareyNumber(nominator + other.nominator, denominator + other.denominator);
    }

    // Operator>: Compares two FareyNumbers based on their decimal value.
    // Returns 1 if this fraction is greater than 'other', 0 otherwise.
    int operator>(const FareyNumber& other) const {
        // Correctly compare using floating-point values
        // static_cast<double> ensures floating-point division
        if (static_cast<double>(nominator) / denominator > static_cast<double>(other.nominator) / other.denominator) {
            return 1;
        }
        return 0;
    }

    // Operator<: Compares two FareyNumbers. Needed for std::sort.
    bool operator<(const FareyNumber& other) const {
        return static_cast<double>(nominator) / denominator < static_cast<double>(other.nominator) / other.denominator;
    }

    // Operator==: Compares two FareyNumbers for equality.
    bool operator==(const FareyNumber& other) const {
        // After simplification, two fractions are equal if their nominator and denominator match
        return nominator == other.nominator && denominator == other.denominator;
    }

    int getNominator() const {
        return nominator;
    }

    int getDenominator() const {
        return denominator;
    }

    void print() const {
        std::cout << nominator << "/" << denominator;
    }
};

// Main function to execute the Farey sequence generation
int main() {
    std::vector<FareyNumber> sequence;

    // Initialize the sequence for F_1: {0/1, 1/1}
    sequence.push_back(FareyNumber(0, 1));
    sequence.push_back(FareyNumber(1, 1));

    int goal_N; // This will be the order N of the Farey sequence to calculate
    std::cout << "Enter the order N for the Farey sequence: ";
    std::cin >> goal_N;

    if (goal_N < 1) {
        std::cout << "Order N must be at least 1." << std::endl;
        return 1; // Exit with error code
    }

    // cur_N represents the current maximum denominator being considered for mediants.
    // We start from 2 because F_1 is already initialized.
    for (int cur_N = 2; cur_N <= goal_N; ++cur_N) {
        // Use a temporary vector to store new mediants found in this iteration
        // to avoid modifying the sequence while iterating over it.
        std::vector<FareyNumber> new_mediants;

        // Iterate through the current sequence to find adjacent pairs
        for (size_t i = 0; i < sequence.size() - 1; ++i) {
            // Calculate the mediant of adjacent fractions
            FareyNumber mediant_val = sequence[i] + sequence[i+1]; // Uses the overloaded operator+

            if (mediant_val.getDenominator() == cur_N) {
                new_mediants.push_back(mediant_val);
            }
        }

        for (const auto& f : new_mediants) {
            sequence.push_back(f);
        }

        std::sort(sequence.begin(), sequence.end());
    }

    std::cout << "Farey Sequence of order " << goal_N << ": {";
    for (size_t i = 0; i < sequence.size(); ++i) {
        sequence[i].print();
        if (i < sequence.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "}" << std::endl;

    return 0; 
}
