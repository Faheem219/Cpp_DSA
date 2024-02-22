#include <iostream>
using namespace std;

struct Elements{
    int i;
    int j;
    int x;
};

struct Sparse{
    int m;
    int n;
    int num;
    struct Elements *ele;
};

// Create a sparse matrix (Time Complexity: O(num))
void create(struct Sparse *s){
    cout<<"\nEnter dimensions:";
    cin>>s->m>>s->n;
    cout<<"\nEnter number of non zero elements:";
    cin>>s->num;
    s->ele=new Elements[s->num]; // (struct Elements *)malloc(s->num*sizeof(struct Elements));
    cout<<"\nEnter non zero elements:";
    for(int i=0;i<s->num;i++){
        cin>>s->ele[i].i>>s->ele[i].j>>s->ele[i].x;
    }
}

// Display the sparse matrix (Time Complexity: O(m*n))
void Display(struct Sparse s){
    int i,j,k=0;
    for(i=0;i<s.m;i++){
        for(j=0;j<s.n;j++){
            if(i==s.ele[k].i && j==s.ele[k].j)
                cout<<s.ele[k++].x<<" ";
            else 
                cout<<"0 ";
        }
        cout<<"\n";
    }
}

// Add two sparse matrices (Time Complexity: O(m+n)
struct Sparse * Add(struct Sparse s1, struct Sparse s2){
    struct Sparse *sum;
    int i,j,k;
    i=j=k=0;
    sum= new Sparse;
    sum->ele=new Elements[s1.num+s2.num];
    while(i<s1.num && j<s2.num){
        if(s1.ele[i].i<s2.ele[j].i) sum->ele[k++]=s1.ele[i++];
        else if(s1.ele[i].i>s2.ele[j].i) sum->ele[k++]=s2.ele[j++];
        else{
            if(s1.ele[i].j<s2.ele[j].j) sum->ele[k++]=s1.ele[i++];
            else if(s1.ele[i].j>s2.ele[j].j) sum->ele[k++]=s2.ele[j++];
            else{
                sum->ele[k]=s1.ele[i];
                sum->ele[k++].x=s1.ele[i++].x+s2.ele[j++].x;
            }
        }
    }
    for(;i<s1.num;i++) sum->ele[k++]=s1.ele[i];
    for(;j<s2.num;j++) sum->ele[k++]=s2.ele[j];
    sum->m=s1.m;
    sum->n=s1.n;
    sum->num=k;

    return sum;
}

int main(){
    struct Sparse s1,s2,*s3;
    create(&s1);
    cout<<"\n"<<endl;
    Display(s1);
    create(&s2);
    cout<<"\n"<<endl;
    Display(s2);
    s3=Add(s1,s2);
    cout<<"\nAddition:\n"<<endl;
    Display(*s3); // *s3 is used to dereference the pointer, deferecing a pointer means 
    // getting the value at the address stored in the pointer
    return 0;
}