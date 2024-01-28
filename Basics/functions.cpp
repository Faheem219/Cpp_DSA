#include <iostream>
using namespace std;

/* If all the code is written in just main() it is called monolithic programming,
if its broken into several functions, it is called modular/procedural programming.*/

int add(int a, int b){ // This is called function prototype, 
    int c;             //int a & int b are called formal parameters.
    c=a+b;
    return c;
}

int sub(int a, int b);  // Function can be defined after main function as well, 
                        // but it should be declared before main function.
int main(){
    int x=10,y=5,z;
    z=add(x,y);         // x & y are called actual parameters.
    cout<<"\n"<<z<<endl;
    z=sub(x,y);
    cout<<"\n"<<z<<endl;
    return 0;
}

int sub(int a, int b){  
    int c;
    c=a-b;
    return c;
}