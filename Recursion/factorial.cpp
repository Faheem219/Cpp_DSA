#include <iostream>
using namespace std;

// Factorial of a number using recursion:

int fun(int n){
    if(n==0)
        return 1;
    return fun(n-1)*n;
}

// Using iteration:

int fun1(int n){
    int fact=1;
    for(int i=1;i<=n;i++)
        fact*=i;
    return fact;
}

int main(){
    int x;
    cout<<"\nEnter a number: ";
    cin>>x;
    cout<<"\nFactorial of "<<x<<" is (recursion): "<<fun(x)<<"\n"<<endl;
    cout<<"\nFactorial of "<<x<<" is (iteration): "<<fun1(x)<<"\n"<<endl;
    return 0;
}