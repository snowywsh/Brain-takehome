

#include "matrix.h"

#include <sstream>




// private: 
//     int nrow;
//     int ncol;
//     vector<vector<float>> elements;

matrix::matrix(const int row, const int col) {
    nrow = row;
    ncol = col;
    elements = vector<vector<float> >(nrow, vector<float>(ncol, 0.0)); 
}

matrix::~matrix() {}

// get number of rows of the matrix
int matrix::getNrow() const{  
     return this->nrow;
}

// get number of columns of the matrix
int matrix::getNcol() const { 

     return this->ncol;
}

// get all the elements of the matrix
vector<vector<float> > matrix::getEle() const {
    return this->elements; 
}

// get a specific element given the index
float matrix::getEle(int r, int c) const {
    return this->elements[r][c];
}     
 
// change a specific element given the index
void matrix::setEle(int r, int c, float e) {
    this->elements[r][c] = e;   
}


// perform dot multiplication between two matrices when valid
matrix matrix::multiply(const matrix m) {
    int nr = m.getNrow(), nc = m.getNcol();
    int thisnr = this->getNrow(), thisnc = this->getNcol();
    
    matrix ans = matrix(thisnr, nc);
    if (thisnc == nr){
        for (int i = 0; i<thisnr; i++)
            for (int j = 0; j<nc; j++)
                for (int k = 0; k<nr; k++){
                    ans.elements[i][j] += this->getEle(i,k) * m.getEle(k,j);
                }
    }
    
    return ans;
}

// transpose matrix 
matrix matrix::transpose() {
    int newc = this->getNrow();
    int newr = this->getNcol(); 
    matrix newmtr = matrix(newr, newc);
    for (int i = 0; i<newr; i++)
        for (int j = 0; j<newc; j++){
            newmtr.elements[i][j] = this->getEle(j,i);
        }
    return newmtr; 
}

     
// print matrix to console
void matrix::mprint() {
    int nr = this->getNrow(), nc = this->getNcol();
    for (int i  = 0; i < nr; i++){  // each row on a new line
        for (int j = 0; j < nc; j++){
            cout<<this->getEle(i, j);
            if (j != nc-1)   cout<<", ";
        }
        cout<<'\n';
                 
    }
}

// get console input into matrix 
int matrix::mfill(string str) {
    int nr = this->getNrow(), nc = this->getNcol();
    stringstream s_stream(str);  //create string stream from the string
    int r = 0, c = 0; 
    while(s_stream.good() && r < nr) {
        string substr;
        getline(s_stream, substr, ',');  //get first string delimited by comma
        float e = stof(substr);
        this->setEle(r, c, e);
        c = (c+1) % nc;
        r = (c==0) ? r+1 : r; 
    }
    if (s_stream.good()) { // when input > matrix size
        cout<< "Additional element input discarded..." << '\n';
    }
    else if (r < nr) {  // when input < matrix size
        cout<< "Not enough elements for matrix..." << '\n';
        return -1;
    }
    cout<<"Matrix is : "<<'\n';
    this->mprint();
    return 0; 
}




   

