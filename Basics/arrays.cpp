#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int B[n];
    for (int y:B)
    {
        cout<<y<<endl;
    }
    
    /*
    int A[5]={1,2,3,4,5};
    printf("%lu\n",sizeof(A));

    for (int x:A)
    {
        cout<<x<<endl;
    }
    return 0;
    */
}
