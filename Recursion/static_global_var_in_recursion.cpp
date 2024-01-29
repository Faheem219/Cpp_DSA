#include <iostream>
using namespace std;

// Static variable in recursion:
/*
int fun(int n){     // Treat static variable as global variable
    static int x=0; // Static variable is initialized only once
    if(n>0){        // It is not initialized every time the function is called
        x++;        // It retains its value even after the function call is over
        return fun(n-1)+x;
    }
}

int main(){
    int r;
    r=fun(5);
    cout<<r<<endl;
    return 0;
}
*/

// Global variable in recursion:
int x=0; // Global variable is initialized only once
int fun(int n){
    if(n>0){
        x++;
        return fun(n-1)+x;
    }
    return 0;
}

int main(){
    int r;
    r=fun(5);
    cout<<r<<endl;
    r=fun(5);
    cout<<r<<endl;
    return 0;
}