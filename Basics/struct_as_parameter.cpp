#include <iostream>
using namespace std;

struct Rectangle{
    int length;
    int breadth;
};

// To create a structure object in heap:

struct Rectangle *fun(){
    struct Rectangle *p;
    p=new Rectangle; // p=(struct Rectangle *)malloc(sizeof(struct Rectangle)); in C.
    p->length=10;
    p->breadth=5;
    return p;
}

// Call by value:

int area(struct Rectangle r1){ // struct Rectangle r is call by value.
    return r1.length*r1.breadth;
}

// Call by reference (inline function by compiler):

int area1(struct Rectangle &r2){ // struct Rectangle &r is call by reference.
    return r2.length*r2.breadth;
}

// Call by address:

void changeLength(struct Rectangle *r3, int l){ // struct Rectangle *r is call by address,
    r3->length=l;                               // l is call by value.
}// r3 is a pointer to struct Rectangle, so r3->length is same as (*r3).length.

// Even though you cannot pass a array by value, you can pass a struct by value.
// Even if the struct has an array inside it.

struct test{
    int A[5];
    int n;
};

void print(struct test t){
    for(int i=0;i<t.n;i++){
        cout<<t.A[i]<<" ";
    }
    cout<<endl;
}

int main(){
    struct Rectangle r={10,5};
    cout<<"\n"<<area(r)<<endl;
    cout<<"\n"<<area1(r)<<endl;
    changeLength(&r,20);
    cout<<"\n"<<area(r)<<endl;

    struct test t={{1,2,3,4,5},5};
    print(t);

    struct Rectangle *q=fun();
    cout<<"\n"<<q->length<<endl;
    return 0;
}