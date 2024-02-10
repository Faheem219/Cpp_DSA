#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
// Static Arrays:
    // This array is created in stack, it cannot be resized.

    // Initialization of array:
    int x=10; // Scalar variable
    int A[5]; // Vector variable, garbage value will be stored
    int A1[5]={1,2,3,4,5}; 
    int A2[5]={1,3}; // The rest of the array will be initialized with 0's
    int A3[]={1,2,3,4,5,6,7,8,9}; // Array of the same size as the list will be created.

    // Accessing array:
    for(int i=0;i<5;i++) printf("\n%d",A1[i]);
    printf("\n%d",2[A1]);
    printf("\n%d",*(A1+2)); // Using pointer to access array element

    // Adderesses of an array:
    for(int i=0;i<5;i++) printf("\n%u",&A1[i]); // Depends on the data type of the array.
    
// Dynamic Arrays:
    // Creating an array in heap, it can be resized using a method.

    int *p;
    p=new int[5]; //in C: p=(int *)malloc(5*sizeof(int)); malloc is avail. in stdlib.h
    // Accesing array from the heap:
    p[0]=5;
    p[1]=3;
    p[2]=7;
    p[3]=1;
    p[4]=9;
    for(int i=0;i<5;i++) cout<<"\n"<<p[i]<<endl;

    // How to increase size of array:
    int *q=new int[10];
    for(int i=0;i<5;i++) q[i]=p[i];
    delete []p; //in C: free(p);
    p=q;
    q=NULL;
    for(int i=0;i<10;i++) cout<<"\n"<<p[i]<<endl;
    return 0;
}