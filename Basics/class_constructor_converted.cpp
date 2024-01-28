#include <iostream>
using namespace std;

// Class is a object oriented programming concept.

class Rectangle{
private:
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
};

class Rectangle2{
private:
    int length;
    int breadth;
public:
    Rectangle2(int l, int b){ // This is a constructor.
        length=l;
        breadth=b;
    }
    int area(){
        return length*breadth;
    }
    void changeLength(int l){
        length=l;
    }
};

int main(){
    Rectangle r;
    r.init(10,5);
    cout<<"\n"<<r.area()<<endl;
    r.changeLength(20);
    cout<<"\n"<<r.area()<<endl;

    Rectangle2 r2(10,5); // It is initialized by the constructor, no need of an init function.
    cout<<"\n"<<r2.area()<<endl;
    r2.changeLength(20);
    cout<<"\n"<<r2.area()<<endl;
    return 0;
}