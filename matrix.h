/*
requirement: 
You’ve been tasked with writing a high-performance, portable linear algebra library for a client who has an awful case of not-invented-here syndrome. 
This means you must only use standard libraries (and miss out on the decades of optimizations in various BLAS implementations). 
As a start, the client has asked for just transpose and multiplication of MxN matrices.

You should demonstrate the correctness of your solution. 
Your solution should be well-documented so that it can be used and maintained by the client’s engineering staff. 
You are free to choose the underlying matrix representation and interface.

C++

Your solution should be implemented in standard C++11 (g++ or clang++ on Linux). 
To keep things simple, the library may be header-only. 
You may include a Makefile/CMakeLists.txt, or you may specify the compiler command used to compile your source file: g++ main.cpp -std=c++11 -lthread
*/


/*
instruction: 
The matrix class is implementated for the purpose to perform transposition and multiplication among matrices.


To complie this from commandline:
g++ -std=c++11 matrix.cpp main.cpp -o matrix

To perform transposition (e.g.): 
./matrix t 2.3 5 1.1,2,2,3.3,4,1.0,2.3,5.5,1.1,2.2,6 

To perform multiplication (e.g.):
./matrix m 2 3 1,2,3,3,2,1 3 2 2,2,2,1,1,1,1
*/

#ifndef _MATRIX_H
#define _MATRIX_H


#include <iostream>
#include <vector>
using namespace std;



class matrix {

private: 
    int nrow;
    int ncol;
    vector<vector<float> > elements;



public:
    matrix(const int nrow, const int ncol);
    ~matrix();
    
    int getNrow() const; // get number of rows of the matrix
    int getNcol() const; // get number of columns of the matrix

    vector<vector<float> > getEle() const; // get all the elements of the matrix

    float getEle(int r, int c) const ; // get a specific element given the index
    void setEle(int r, int c, float e); // change a specific element given the index
    matrix multiply(matrix m);  // perform dot multiplication between two matrices when valid
    matrix transpose(); // transpose matrix 
    void mprint() ; // print matrix to console
    int mfill(string str); // get console input into matrix 

}; 


#endif 


