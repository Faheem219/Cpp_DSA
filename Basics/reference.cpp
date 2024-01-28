#include <iostream>
using namespace std;

int main(){
    int a = 10;
    int &r = a;
    cout << "\na = " << a << endl;
    cout << "\nr = " << r << endl;
    r++;
    cout << "\na = " << a << endl;

    int b=30;
    r=b;
    cout << "\na = " << a << endl;
    return 0;
}