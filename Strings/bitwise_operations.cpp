#include <iostream>
using namespace std;

int main(){
    int a=5,b=9;
    // In memory, the numbers are stored in binary format
    // (starting index from the right hand side, ie, from 0 to 7). 
    // All bits are shifted to the left by 1 position and the rightmost bit is replaced by 0.

    // Left Shift Operator (<<) (Multiplies by 2^n) (n=1 in this case):
    // 5: 0101 (in binary) // 10: 1010 (in binary)
    cout<<"\nLeft Shift Operator:"<<endl;
    cout<<(a<<1)<<endl;

    // Right Shift Operator (>>) (Divides by 2^n) (n=1 in this case):
    // 9: 1001 (in binary) // 4: 0100 (in binary)
    cout<<"\nRight Shift Operator:"<<endl; 
    cout<<(b>>1)<<endl;

    // Bitwise AND Operator (&):
    // 5: 0101 (in binary) // 9: 1001 (in binary) 
    // 0101 & 1001 = 0001 (in binary) = 1 (in decimal)
    cout<<"\nBitwise AND Operator:"<<endl;
    cout<<(a&b)<<endl;

    // Bitwise OR Operator (|):
    // 5: 0101 (in binary) // 9: 1001 (in binary)
    // 0101 | 1001 = 1101 (in binary) = 13 (in decimal)
    cout<<"\nBitwise OR Operator:"<<endl;
    cout<<(a|b)<<endl;

    // Bitwise XOR Operator (^):
    // 5: 0101 (in binary) // 9: 1001 (in binary)
    // 0101 ^ 1001 = 1100 (in binary) = 12 (in decimal)
    cout<<"\nBitwise XOR Operator:"<<endl;
    cout<<(a^b)<<endl;

    // Bitwise NOT Operator (~):
    // 5: 0101 (in binary) // 9: 1001 (in binary)
    // ~0101 = 1010 (in binary) = -6 (in decimal)
    cout<<"\nBitwise NOT Operator:"<<endl;
    cout<<(~a)<<endl;

// MASKING OPERATION (Knowing wether a particular bit is on or off):
    int x=16,y=1;
    // 16: 0001 0000 (in binary) // 1: 0000 0001 (in binary)
    // Checking whether the 5th bit is on or off:
    cout<<"\nMasking Operation:"<<endl;
    y<<=4;
    if(x&y){
        cout<<"5th bit is on"<<endl;
    }
    else{
        cout<<"5th bit is off"<<endl;
    }

    // Checking whether the 3rd bit is on or off:
    y=1;
    y<<=2;
    if(x&y){
        cout<<"3rd bit is on"<<endl;
    }
    else{
        cout<<"3rd bit is off"<<endl;
    }

// MERGING OPERATION (Setting a particular bit to 1):
    int z=32;
    // 32: 0010 0000 (in binary)
    // Setting the 4th bit to 1:
    cout<<"\nMerging Operation:"<<endl;
    y=1;
    y<<=3;
    z=z|y;
    cout<<z<<endl;

    return 0;
}