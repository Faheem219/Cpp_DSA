#include <iostream>
using namespace std;

// Simple method utilizing a recursive factorial function:
int fact(int n){
    if (n==0) return 1;
    return fact(n-1)*n;
}

int C(int n, int r){
    int t1,t2,t3;
    t1=fact(n);
    t2=fact(r);
    t3=fact(n-r);
    return t1/(t2*t3);
}

// Proper recursive function using pascals triangle:
int C1(int n, int r){
    if(r==0||n==r) return 1;
    else return C1(n-1,r-1)+C1(n-1,r);
}

int main(){
    int n,r;
    cout<<"\nEnter the value of n and r in nCr: ";
    cin>>n>>r;
    cout<<"\nValue of "<<n<<"C"<<r<<" is (Simple Method): "<<C(n,r)<<"\n"<<endl;
    cout<<"\nValue of "<<n<<"C"<<r<<" is (Proper Method): "<<C1(n,r)<<"\n"<<endl;
    return 0;
}