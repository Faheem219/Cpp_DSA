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

// Linear search using iteration:
struct Node * LSearch(struct Node *p,int key){
    while(p){
        if(key==p->data) return p;
        p=p->next;
    }
    return NULL;
}

// Linear Search using recursion:
struct Node * LSearch_R(struct Node *p, int key){
    if(p==NULL) return NULL;
    if(key==p->data) return p;
    return LSearch_R(p->next,key); 
}

// Improving linear seach using transposition (move to head):
struct Node * ILSearch(struct Node *p, int key){
    struct Node *q;
    while(p){
        if(key==p->data){
            q->next=p->next; // q is the previous node of p
            p->next=first; // p is the new first node
            first=p; 
            return p;
        } 
        q=p;
        p=p->next;
    }
    return NULL;
}

int main(){
    struct Node *temp;
    int A[]={3,5,7,10,15};
    int c;
    create(A,5);
    Display(first);
    cout<<endl<<endl;
    temp=LSearch(first, 15);
    if(temp) cout<<"\nKey is found: "<<temp->data<<endl;
    else cout<<"\nKey not found"<<endl;

    temp=ILSearch(first,15);
    (temp)?cout<<"\nKey is found: "<<temp->data<<endl:cout<<"\nKey not found"<<endl;
    Display(first);
    cout<<endl<<endl;

    temp=LSearch_R(first,15);
    (temp)?cout<<"\nKey is found: "<<temp->data<<endl:cout<<"\nKey not found"<<endl;
    return 0;
}