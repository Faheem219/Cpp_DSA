#include <iostream>
using namespace std;

int fun(int m, int n){
    if(n==0)
        return 1;
    return fun(m, n-1)*m;
}

// This is a more efficient way of finding power as this uses only log(n) steps
// instead of n steps. This is because we are dividing n by 2 in each step.
// This is also called as binary exponentiation. Explanation:
// https://cp-algorithms.com/algebra/binary-exp.html

int fun1(int m, int n){
    if(n==0)
        return 1;
    if(n%2==0)
        return fun1(m*m, n/2);
    else
        return m*fun1(m*m, (n-1)/2);
}

// Using iteration:

int fun2(int m, int n){
    int res=1;
    for(int i=1;i<=n;i++)
        res*=m;
    return res;
}

int main(){
    int m, n;
    cout<<"\nEnter a number: ";
    cin>>m;
    cout<<"\nEnter the power: ";
    cin>>n;
    cout<<"\n"<<m<<" raised to the power "<<n<<" is (Recursion): "<<fun(m, n)<<"\n"<<endl;
    cout<<"\n"<<m<<" raised to the power "<<n<<" is (Efficient Recursion): "<<fun1(m, n)<<"\n"<<endl;
    cout<<"\n"<<m<<" raised to the power "<<n<<" is (Iteration): "<<fun2(m, n)<<"\n"<<endl;
    return 0;
}