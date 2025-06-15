#include <iostream>
#include "NonSquare.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#define MAX_ROWS 1000
#define MAX_LINE_LENGTH 1024


using namespace std;
int main() {
    // // System 1: General linear system
    // Matrix A1(3, 3);
    // A1(1,1) = 4; A1(1,2) = 1; A1(1,3) = 1;
    // A1(2,1) = 1; A1(2,2) = 3; A1(2,3) = 0;
    // A1(3,1) = 1; A1(3,2) = 0; A1(3,3) = 2;

    // Vector b1(3);
    // b1[0] = 6;
    // b1[1] = 5;
    // b1[2] = 6;

    // LinearSystem system1(A1, b1);
    // Vector x1 = system1.Solve();
    // std::cout << "Solution (LinearSystem):" << std::endl;
    // for (int i = 0; i < x1.getSize(); ++i) {
    //     std::cout << x1[i] << std::endl;
    // }

    // Vector Ax1 = A1 * x1;
    // std::cout << "Ax1 result:" << std::endl;
    // for (int i = 0; i < Ax1.getSize(); ++i) {
    //     std::cout << Ax1[i] << std::endl;
    // }

    // // System 2: Positive definite symmetric system
    // Matrix A2(3, 3);
    // A2(1,1) = 4; A2(1,2) = 1; A2(1,3) = 1;
    // A2(2,1) = 1; A2(2,2) = 3; A2(2,3) = 0;
    // A2(3,1) = 1; A2(3,2) = 0; A2(3,3) = 2;

    // Vector b2(3);
    // b2[0] = 6;
    // b2[1] = 5;
    // b2[2] = 6;

    // PosSymLinSystem system2(A2, b2);
    // Vector x2 = system2.Solve();
    // std::cout << "Solution (PosSymLinSystem):" << std::endl;
    // for (int i = 0; i < x2.getSize(); ++i) {
    //     std::cout << x2[i] << std::endl;
    // }

    // Vector Ax2 = A2 * x2;
    // std::cout << "Ax2 result:" << std::endl;
    // for (int i = 0; i < Ax2.getSize(); ++i) {
    //     std::cout << Ax2[i] << std::endl;
    // }

    // // System 3: Overdetermined system (least squares)
    // Matrix A3(4, 2);
    // A3(1, 1) = 1;  A3(1, 2) = 2;
    // A3(2, 1) = 2;  A3(2, 2) = 1;
    // A3(3, 1) = 3;  A3(3, 2) = 4;
    // A3(4, 1) = 4;  A3(4, 2) = 3;

    // Vector b3(4);
    // b3[0] = 8;
    // b3[1] = 7;
    // b3[2] = 20;
    // b3[3] = 18;

    // NonSquare system3(A3, b3);
    // Vector x3 = system3.Solve();

    // std::cout << "Solution (Least Squares):" << std::endl;
    // for (int i = 0; i < x3.getSize(); ++i) {
    //     std::cout << x3[i] << std::endl;
    // }



    
    ifstream infile("data.csv");
    if (!infile.is_open()) {
        cerr << "Failed to open file.\n";
        return 1;
    }

    char data[MAX_ROWS][MAX_LINE_LENGTH];
    char Line[MAX_LINE_LENGTH];
    char header[MAX_LINE_LENGTH];
    int rowCount = 0;
    int count = 0;

    while (infile.getline(Line, MAX_LINE_LENGTH) && rowCount < MAX_ROWS) {
        if (count == 0) {
            strcpy(header, Line);  
        } else {
            strcpy(data[rowCount], Line);  
            rowCount++;
        }
        count++;
    }
    infile.close();

    srand(time(nullptr));
    for (int i = 0; i < rowCount; ++i) {
        int j = std::rand() % rowCount;
        char temp[MAX_LINE_LENGTH];
        strcpy(temp, data[i]);
        strcpy(data[i], data[j]);
        strcpy(data[j], temp);
    }

    ofstream outfile("data.csv");
    for (int i = 0; i < rowCount; ++i) {
        outfile << data[i] << "\n";
    }

    outfile.close();
    cout << "Shuffled data written to data.csv\n";




    ifstream file("data.csv");
    string line;

    if(!file.is_open()){
        cout<< "Cannot open the file!"<<endl;
    }
    float train_rate = 0.8;
    int train = train_rate*209;
    int test = train+1;
    Matrix features(train, 6);
    Vector labels(train);
    Matrix features_test(209-test+1, 6);
    Vector test_labels(209-test+1);
    int idx_row = 1;
    int start = 1;
    while(getline(file, line)){
        stringstream ss(line);
        string cell;
        int idx = 1;
        int idx_col = 1;
        if(start >= 2){
            while(getline(ss, cell, ',')){
                if(idx_row > train){
                    if(idx>2 && idx < 9){
                        features_test(idx_row-train, idx_col) = stoi(cell);
                        idx_col++;
                    }
                    if(idx == 9){
                        test_labels(idx_row-train) = stoi(cell);
                        idx_col++;
                    }

                }
                else{
                    if(idx>2 && idx < 9){
                        features(idx_row, idx_col) = stoi(cell);
                        idx_col++;

                    }
                    if(idx == 9){
                        labels(idx_row) = stoi(cell);
                        idx_col++;
                    }
                }
                idx++;
            } 
        }  
        if(start >= 2){
            idx_row++;   
        }
        start++;
        
    }

    NonSquare normal_equation(features, labels);
    Vector parameters = normal_equation.solve();
    for (int i = 0; i < parameters.getSize(); ++i) {
        cout << parameters[i] << endl;
    }
    Vector y_predicted = features_test * parameters;
    Vector residual = test_labels - y_predicted;
    double rmse = 0;
    for(int i = 1; i <= residual.getSize(); i++){
        rmse += residual(i) * residual(i);
    }
    rmse /= residual.getSize();
    rmse = sqrt(rmse);
    cout<<rmse<<endl;
    file.close();
    return 0;
}
