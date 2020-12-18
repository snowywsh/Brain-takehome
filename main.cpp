

#include "matrix.h"
#include <sstream>



int main(int argc, char **argv) {
    // sample commandline input: 
    // ./main t 2 3 1,2,3,4,5,6 
    // ./main m 2 3 1,2,3,4,5,6 3 1 3,2,1
    cout << "You have entered " << argc << " arguments:" << "\n"; 
    int sum = 0; 
    for (int i = 0; i < argc; ++i) {
        cout << argv[i] << '\t'; 
        if (i == argc-1)   cout<<'\n';

    }

    if (argc == 1){
        cout<<"Please call the program, entering operation and matrix dimensions, with each matrix followed by elements seperated by , "<<'\n';
        return 0;
    }
        
    if (strcmp(argv[1], "t") == 0){
        // to prevent segmentation fault 
        if (argc < 5) {
            cout<<"Input format error...";
            return -1;
        }
        int nr = atoi(argv[2]), nc = atoi(argv[3]);
        matrix m = matrix(nr, nc);
        string ele = argv[4];
        stringstream s_stream(ele); //create string stream from the string
        if (m.mfill(ele) == -1) {
            cout<< "Not enough elements for matrix..." << '\n';
            return -1;
        }
        matrix mtrans = m.transpose();
        cout<<"Transposed matrix is : "<<'\n';
        mtrans.mprint();

    }
    else if (strcmp(argv[1], "m") == 0){
        // to prevent segmentation fault 
        if (argc < 8) {
            cout<<"Input format error...";
            return -1;
        }
        int nr1 = atoi(argv[2]), nc1 = atoi(argv[3]);
        int nr2 = atoi(argv[5]), nc2 = atoi(argv[6]);
        if (nc1 != nr2) {
            cout<<"Matrices cannot be multiplied!";
            return 1;
        }
        matrix m1 = matrix(nr1, nc1);
        matrix m2 = matrix(nr2, nc2);
        string ele1 = argv[4];
        string ele2 = argv[7];
        if (m1.mfill(ele1) == -1) {
            cout<< "Not enough elements for the first matrix..." << '\n';
            return -1;
        }
        if (m2.mfill(ele2) == -1) {
            cout<< "Not enough elements for the second matrix..." << '\n';
            return -1;
        }
        matrix mmulti = m1.multiply(m2);
        cout<<"Multiplication output is : "<<'\n';
        mmulti.mprint();
    }
    else 
        cout<<"Please enter operation t/m..."<<'\n';
  
    return 0;  
}
