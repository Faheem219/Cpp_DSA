#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

struct Rectangle
{
        int length;
        int breadth;
} r1,r2;

struct Card
{
    int face;
    string shape;
    int color;
};

int main(){
    struct Rectangle r={10,5};
    r.length=15;
    r.breadth=10;
    cout<<"\nArea of the rectangle is: "<<r.length*r.breadth<<endl;
    cout<<"\nSize of Structure is: "<<sizeof(r)<<endl;
    
    r1.length=10;r1.breadth=5;
    r2.length=15;r2.breadth=10;
    printf("\nLength of r1 is: %d\nBreadth of r1 is: %d\n",r1.length,r1.breadth);

    struct Card deck[52]={
        {1,"Spade",0},{2,"Spade",0},{3,"Spade",0},{4,"Spade",0},{5,"Spade",0},{6,"Spade",0},{7,"Spade",0},{8,"Spade",0},{9,"Spade",0},{10,"Spade",0},{11,"Spade",0},{12,"Spade",0},{13,"Spade",0},
        {1,"Heart",1},{2,"Heart",1},{3,"Heart",1},{4,"Heart",1},{5,"Heart",1},{6,"Heart",1},{7,"Heart",1},{8,"Heart",1},{9,"Heart",1},{10,"Heart",1},{11,"Heart",1},{12,"Heart",1},{13,"Heart",1},
        {1,"Diamond",1},{2,"Diamond",1},{3,"Diamond",1},{4,"Diamond",1},{5,"Diamond",1},{6,"Diamond",1},{7,"Diamond",1},{8,"Diamond",1},{9,"Diamond",1},{10,"Diamond",1},{11,"Diamond",1},{12,"Diamond",1},{13,"Diamond",1},
        {1,"Club",0},{2,"Club",0},{3,"Club",0},{4,"Club",0},{5,"Club",0},{6,"Club",0},{7,"Club",0},{8,"Club",0},{9,"Club",0},{10,"Club",0},{11,"Club",0},{12,"Club",0},{13,"Club",0}
    };
    cout<<"\n"<<deck[0].shape<<endl<<deck[0].face<<endl;
    return 0;
}