#include <iostream>
using namespace std;

// Taylor Series of e^x using recursion;
double e(int x, int n)
{
    static double p=1,f=1;
    double r;
    if (n==0)
        return 1;
    else{
        r=e(x,n-1);
        p*=x;
        f*=n;
        return r+(p/f);
    }
}

// Using loop:
double e3(int x,int n){
    double s=1,num=1,den=1;
    for(int i=1;i<=n;i++){
        num*=x;
        den*=i;
        s+=num/den;
    }
    return s;
}

// Using Efficient loop (reducing operations):
double e1(int x,int n){
    double s=1;
    for(;n>0;n--){
        s=1+x*s/n;
    }
    return s;
}

// Using efficient recusion (making use of static variables and reducing multiplications):
double e2(int x,int n){
    static double s=1;
    if(n==0)
        return s;
    s=1+x*s/n;
    return e2(x,n-1);
}

int main(){
    int x,n;
    cout<<"\nEnter the value of x in e^x:";
    cin>>x;
    cout<<"\nEnter the number of terms till which series to be calculated:";
    cin>>n;
    cout<<"\nThe result is (Recursion): "<<e(x,n)<<"\n"<<endl;
    cout<<"\nThe result is (Loop): "<<e3(x,n)<<"\n"<<endl;
    cout<<"\nThe result is (Efficient Loop): "<<e1(x,n)<<"\n"<<endl;
    cout<<"\nThe result is (Efficient Recursion): "<<e2(x,n)<<"\n"<<endl;
    return 0;
}