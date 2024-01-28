#include <iostream>
using namespace std;

struct Rectangle{
    int length;
    int breadth;
};

int main(){
    Rectangle r = {10, 5}; // or struct Rectangle r = {10, 5}; struct keyword is optional in C++
    struct Rectangle *p = &r;

    p->length = 20; // (*p).length = 20; () are used because . has higher precedence than *
    cout << "\nlength = " << r.length << endl;

// Dynamically allocating memory for a struct:

    struct Rectangle *q;
    q = new Rectangle; // q = (struct Rectangle *)malloc(sizeof(struct Rectangle)); in C
    q->length = 15;
    q->breadth = 10;
    cout << "\nlength = " << q->length << endl<< "\nbreadth = " << q->breadth << endl;

    return 0;
}