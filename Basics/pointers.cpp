#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Rectangle
{
        int length;
        int breadth;
};

int main(){
    int a=10;
    int *p=&a;
    /* or we can assign value to pointer like this:
    int *p;
    p=&a;
    */
    cout<<"\n"<<p<<endl<<*p<<endl;
    cout<<"\nSize of a is: "<<sizeof(a)<<endl<<"Size of p is: "<<sizeof(p)<<"\n"<<endl;

    int A[5]={1,2,3,4,5};
    int *p1=A; /* or int *p1=&A[0]; Since A is a pointer to the first element of the array,
    there is no need for &A*/
    for (int i=0;i<5;i++)
    {
        cout<<p1[i]<<endl;
    }
    cout<<"\n"<<endl;

// Malloc (Memory Allocation) and Free (Deallocate) in C:

    int *q;
    q=(int *)malloc(5*sizeof(int)); /*malloc returns void pointer,
    it is a function in C for allocating memory in heap*/
    q[0]=10;q[1]=20;q[2]=30;q[3]=40;q[4]=50;
    for (int i=0;i<5;i++){
        cout<<q[i]<<endl; //This is a array inside a heap
    }
    cout<<"\n"<<endl;

    free(q); /*free is a function in C for deallocating memory in heap*/
    
    for (int i=0;i<5;i++){
        cout<<q[i]<<endl;
    }

// New (Memory Allocation) and Delete (Deallocate) in C++:

    int *q1;
    q1=new int[5]; /*new is an operator in C++ for allocating memory in heap*/
    q1[0]=10;q1[1]=20;q1[2]=30;q1[3]=40;q1[4]=50;
    cout<<"\n"<<endl;
    for (int i=0;i<5;i++){
        cout<<q1[i]<<endl; //This is a array inside a heap
    }

    delete []q1; /*delete is an operator in C++ for deallocating memory in heap.
    [] is used for deallocating array data type, for any other data type,
    just write the data type's name.*/

// Size of pointer:

    cout<<"\n"<<endl;
    int *q2;
    char *q3;
    float *q4;
    double *q5;
    struct Rectangle *q6;
    cout<<sizeof(q2)<<endl<<sizeof(q3)<<endl<<sizeof(q4)<<endl<<sizeof(q5)<<endl<<sizeof(q6)<<endl;

    return 0;
}