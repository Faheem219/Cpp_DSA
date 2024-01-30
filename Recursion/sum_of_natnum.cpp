#include <iostream>
using namespace std;

// Using recursion:
int sum(int n){
    if (n==0){
        return 0;
    }
    else{
        return sum(n-1)+n;
    }
}

// Using formula:
int sum1(int n){
    return n*(n+1)/2;
}

// Using Loop:
int sum2(int n){
    int s=0;
    for(int i=1;i<=n;i++){
        s+=i;
    }
    return s;
}

int main(){
    int n;
    cout<<"\nEnter a number: ";
    cin>>n;
    cout<<"\nSum of first "<<n<<" natural numbers is (recursion): "<<sum(n)<<"\n"<<endl;
    cout<<"\nSum of first "<<n<<" natural numbers is (formula): "<<sum1(n)<<"\n"<<endl;
    cout<<"\nSum of first "<<n<<" natural numbers is (loop): "<<sum2(n)<<"\n"<<endl;
    return 0;
}

// Usage of formula is recommended over usage of recursion and loop to save on 
// time and space complexity.