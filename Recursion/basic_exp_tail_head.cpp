#include <iostream>
using namespace std;

// Tail Recursion: When recursive call is done at the end of the function
// Example 1 (Here recursive call is done after printing):
/*
void fun1(int n){
    if(n>0){
        cout<<n<<" ";
        fun1(n-1);
    }
}

int main(){
    int x=3;
    fun1(x);
    return 0;
}
*/

// Head Recursion: When recursive call is done at the beginning of the function
// Example 2 (Here recursive call is done before printing):

void fun2(int n){
    if(n>0){
        fun2(n-1); // This is called a recursive call
        cout<<n<<" ";
    }
}

int main(){
    int x=3;
    fun2(x);
    return 0;
}