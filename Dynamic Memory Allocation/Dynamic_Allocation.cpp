#include <iostream>
using namespace std;

int main(){
    cout << " ------- Variable ------- " << endl;
    try{
        int *p = new int;
        *p = 1;
        int *q = new int(5);

        cout << *p << endl;     // Output: 1
        cout << *q << endl;     // Output: 5

        delete(p);
        delete(q);
    }
    catch(bad_alloc &b){    // memory allocation failure
        cout << "bad_alloc Exception" << endl;
        exit(-2);
    }

    cout << endl << " ------- 1D Array ------- " << endl;
    int arrLen = 10;
    try{
        int *dynArr = new int[10];
        for (int i = 0; i < arrLen; ++i) {    // access
            dynArr[i] = i;
            cout << dynArr[i] << " ";     // Output: 0 ~ 9
        }
        cout << endl;
        delete []dynArr;
    }
    catch(bad_alloc &){    // memory allocation failure
        cout << "bad_alloc Exception" << endl;
        exit(-2);
    }

    cout << endl << " ------- 2D Array ------- " << endl;
    int row = 5, col = 10;

    try{
        int **dynArr2 = new int*[row];      // Allocate row first
        for(int i = 0; i < row; ++i) {      // Allocate col
            dynArr2[i] = new int[col];
        }

        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                int index = i * col + j;
                dynArr2[i][j] = index;
                cout << dynArr2[i][j] << " ";     // Output: 0 ~ 49
            }
            cout << endl;
        }

        for(int i = 0; i < row; ++i){       // Deallocate col first
            delete []dynArr2[i];
        }
        delete []dynArr2;                   // Deallocate row
    }
    catch(bad_alloc &){     // memory allocation failure
        cout << "bad_alloc Exception" << endl;
        exit(-2);
    }
  return 0;
}
