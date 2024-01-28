#include <iostream>
using namespace std;

// Array can only be sent as a parameter by address, not by value.

// n is used because we need to know the size of the array declared in main function,
// which is not accessible in the print function.
// a is call by address, n is call by value, a is a pointer to the first element of the array.
void print(int a[], int n) // int a[] is same as int *a
{ 
    for(int i=0;i<n;i++){  // for each loop cannot be used on pointers
        cout<<a[i]<<" ";   // because pointers are not iterable.
    }                      // for(int x:a) is called for each loop.
    cout<<endl;
}

// Returning array as a paramater:
int * fun(int n){
    int *p;
    p=new int[n];
    return p;
}

int main(){
    int a[5]={1,2,3,4,5}; // Arrays are passed by address.
    print(a,5);
    int *A;
    A=fun(5);
    print(A,5);
    return 0;
}