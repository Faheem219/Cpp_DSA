#include <iostream>
using namespace std;

int main(){
    // 1st method for creating 2D array:
    int A[3][4]={{1,2,3,4},{2,4,6,8},{1,3,5,7}}; // This is stored just like a 1D array
    // with 12 elements in stack.

    // 2nd method for creating 2D array using array of pointers:
    int *A1[3]; // Rows created in stack and columns created in heap.
    A1[0]=new int[4];
    A1[1]=new int[4];
    A1[2]=new int[4];

    // 3rd method for creating 2D array completely in heap:
    int **A2;
    A2=new int*[3]; // Both rows and columns are created in heap.
    A2[0]=new int[4];
    A2[1]=new int[4];
    A2[2]=new int[4];

    // Accessing 2D arrays:
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++) cout<<A[i][j]<<" ";
        cout<<"\n";
    }
    return 0;
}