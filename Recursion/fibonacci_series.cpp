#include <iostream>
using namespace std;

// Using recursion: (Excessive Recursion, since this calls the function for the
// same values again and again. This is time and storage consuming)
// This has time complexity of order of 2^n which is more than just using loop 
// which has time complexity of order of n
int fib(int n){
    if(n<=1)
    return n;
    return fib(n-2)+fib(n-1);
}

// Using loop:
int fib1(int n){
    int t0=0,t1=1,s;
    if(n<=1)return n;
    for(int i=2;i<=n;i++){
        s=t0+t1;
        t0=t1;
        t1=s;
    }
    return s;
}

int F[100];
// Efficient Recursion (Time complexity of order of n):
// Memoization: Storing the results of the calls (in a global array in this case),
// so that they can be utilized if the same call is made rather than calling 
// the function again, avoiding excessive calls reducing time & space complexity.
int fib2(int n){
    if(n<=1){
        F[n]=n;
        return n;
    }
    else{
        if (F[n-2]==-1)
        F[n-2]=fib2(n-2);
        if (F[n-1]==-1)
        F[n-1]=fib2(n-1);
        F[n]=F[n-2]+F[n-1];
        return F[n-2]+F[n-1];
    }
}

int main(){
    int x;
    for(int i=0;i<100;i++)
    F[i]=-1;
    cout<<"\nEnter an integer: ";
    cin>>x;
    cout<<"\nFibonnaci value of "<<x<<"th term is (Recursion): "<<fib(x)<<"\n"<<endl;
    cout<<"\nFibonnaci value of "<<x<<"th term is (Loop): "<<fib1(x)<<"\n"<<endl;
    cout<<"\nFibonnaci value of "<<x<<"th term is (Efficient Recursion): "<<fib2(x)<<"\n"<<endl;
    return 0;
}

