#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*first=NULL; // This pointer points to the first node of the linked list
// It is global and therefore accessible to all functions.

void create(int A[], int n){
    struct Node *t,*last;
    first = new Node;
    first->data=A[0];
    first->next=NULL;
    last=first;
    for(int i=1;i<n;i++){
        t=new Node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

// Displaying using iteration. Time = O(n), Space = O(1):
void Display(struct Node *p){
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
}

// Displaying using recursion. Time = O(n), Space = O(n):
void Display_R(struct Node *p){
    if(p){
        cout<<p->data<<" ";
        Display_R(p->next);
    }
}

// Counting elements in a linked list iteration. Time = O(n), Space = O(1):
int Count(struct Node *p){
    int count=0;
    while(p){
        count++;
        p=p->next;
    }
    return count;
}

// Counting elements using recursion. Time = O(n), Space = O(n):
int Count_R(struct Node *p){
    if(p==0) return 0;
    else return Count_R(p->next)+1;
}

// Sum of all elements in a linked list iteration:
int Add(struct Node *p){
    int sum=0;
    while(p){
        sum+=p->data;
        p=p->next;
    }
    return sum;
}

// Sum using recursion:
int Add_R(struct Node *p){
    if(p==0) return 0;
    return p->data+Add_R(p->next);
}

// Max element in a linked list iteration:
int Max(struct Node *p){
    int Max=INT32_MIN;
    while(p){
        if(p->data>Max) Max=p->data;
        p=p->next;
    }
    return Max;
}

// Max element recursion:
int Max_R(struct Node *p){
    int x=0;
    if(p==0) return INT32_MIN;
    x=Max_R(p->next);
    return x>p->data?x:p->data;
}

int main(){
    int A[]={3,5,7,10,15};
    int c;
    create(A,5);
    Display(first);
    cout<<endl<<endl;
    Display_R(first);
    cout<<endl<<endl<<Count(first);
    cout<<endl<<endl<<Count_R(first);
    cout<<endl<<endl<<Add(first);
    cout<<endl<<endl<<Add_R(first);
    cout<<endl<<endl<<Max(first);
    cout<<endl<<endl<<Max_R(first);
    return 0;
}