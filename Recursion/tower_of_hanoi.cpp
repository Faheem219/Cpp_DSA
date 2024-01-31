#include <iostream>
using namespace std;

// This is a time consuming function having time complexity of 2^n 
// since the function is calling itself 2 times.
void TOH(int n, char A, char B, char C){
    if(n>0){
        TOH(n-1,A,C,B);
        printf("\nfrom %c to %c\n",A,C);
        TOH(n-1,B,A,C);
    }
}

int main(){
    int n;
    char A,B,C;
    cout<<"\nEnter the values to input into the TOH problem:";
    cin>>n>>A>>B>>C;
    TOH(n,A,B,C);
    return 0;
}