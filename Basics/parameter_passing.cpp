#include <iostream>
using namespace std;

// This is pass by value, the formal parameters are copied to actual parameters.

void swap(int a, int b){ //Only the formal parameters are changed,
    int temp;            //actual parameters remain unchanged.
    temp=a;
    a=b;
    b=temp;
    cout<<"\nInside swap function: "<<a<<" "<<b<<endl;
}

// This is call by address, the formal parameters are the addresses of actual parameters.

void swap1(int *a, int *b){ //Both the formal and actual parameters are changed.
    int temp;             
    temp=*a;
    *a=*b;
    *b=temp;
    cout<<"\nInside swap1 function: "<<*a<<" "<<*b<<endl;
}

// This is call by reference, the formal parameters are the aliases of actual parameters.
// This is only allowed in C++, dont use this for complex programs.
// Because this may be converted to an inline function by the compiler, which causes
// this to become a monolithic program instead of being modular.

void swap2(int &a, int &b){ //Both the formal and actual parameters are changed.
    int temp;             
    temp=a;
    a=b;
    b=temp;
    cout<<"\nInside swap2 function: "<<a<<" "<<b<<endl;
}

int main(){
    int a,b;
    a=10;
    b=20;
    swap(a,b);
    cout<<"\nInside main function (swap): "<<a<<" "<<b<<endl;
    swap1(&a,&b);
    cout<<"\nInside main function (swap1): "<<a<<" "<<b<<endl;
    swap2(a,b);
    cout<<"\nInside main function (swap2): "<<a<<" "<<b<<endl;
    return 0;
}