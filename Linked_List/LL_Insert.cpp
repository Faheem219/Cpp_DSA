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

void Display(struct Node *p){
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
}

int Count(struct Node *p){
    int count=0;
    while(p){
        count++;
        p=p->next;
    }
    return count;
}

void Insert(struct Node *p,int pos, int x){
    struct Node *t;
    if(pos<0 || pos>Count(p)) return; // Checking also that p is not null (pos is outside linked list)
    t=new Node;
    t->data=x;
    if(pos==0){
        t->next=first;
        first=t;
    }
    else{
        for(int i=0; i<pos-1; i++){
            p=p->next;
        }
        t->next=p->next;
        p->next=t;
    }
}

int main(){
    struct Node *temp;
    int A[]={3,5,7,10,15};
    int c;
    create(A,5);
    Display(first);
    cout<<endl<<endl;
    Insert(first,3,25);
    Display(first);
    cout<<endl<<endl;
    return 0;
}