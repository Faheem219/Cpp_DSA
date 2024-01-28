#include <iostream>
using namespace std;

struct Rectangle{
    int length;
    int breadth;
};

void init(struct Rectangle *R, int l, int b){
    R->length=l;
    R->breadth=b;
}

int area(struct Rectangle R){
    return R.length*R.breadth;
}

void changeLength(struct Rectangle *R, int l){
    R->length=l;
}

int main(){
    int A;
    struct Rectangle r;
    init(&r,10,5);
    cout<<"\n"<<r.length<<" "<<r.breadth<<endl;

    A=area(r);
    changeLength(&r,20);
    cout<<"\n"<<A<<endl;

    return 0;
}

// To convert this code into a C++ code, using class and constructor:
// Converting modular code to an object oriented code.
// In detail in class_constructor.cpp:
/*
class Rectangle
{private:
    int length;
    int breadth;

public:
    void init(int l, int b){
        length=l;
        breadth=b;
    }

    int area(){
        return length*breadth;
    }
    void changeLength(int l){
        length=l;
    }
}

int main(){
    Rectangle r;
    r.init(10,5);
    cout<<"\n"<<r.area()<<endl;
    r.changeLength(20);
    cout<<"\n"<<r.area()<<endl;
    return 0;
}
*/