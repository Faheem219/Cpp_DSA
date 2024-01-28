#include <iostream>
using namespace std;

// This class just contains the headers of the different function.
class Rectangle{
    private:
    int length;
    int breadth;

    public:
    // Rectangle(){length=breadth=1;}  Default constructor.
    Rectangle(int l, int b);  // Parameterized constructor.
    int area(); // Facilitator.
    int perimeter(); // Facilitator.
    int getLength(){return length;} // Getter/ Accessor.
    void setLength(int l){length=l;} // Setter/ Mutator.
    ~Rectangle(); // Destructor.
};

// Class functions are defined outside the class.
Rectangle::Rectangle(int l, int b){
    length=l;
    breadth=b;
}

int Rectangle::area(){
    return length*breadth;
}

int Rectangle::perimeter(){
    return 2*(length+breadth);
}

Rectangle::~Rectangle(){
    cout<<"\nDestructor called."<<endl;
}


int main(){
    Rectangle r(10,5);
    cout<<"\n"<<r.area()<<endl;
    cout<<"\n"<<r.perimeter()<<endl;
    r.setLength(20);
    cout<<"\n"<<r.area()<<endl;
    cout<<"\n"<<r.perimeter()<<endl;
    cout<<"\n"<<r.getLength()<<endl;
    // r.~Rectangle(); Destructor is called automatically when the object
    // goes out of scope (when the program ends).
    // So it is not necessary to call the destructor explicitly.
    return 0;
}