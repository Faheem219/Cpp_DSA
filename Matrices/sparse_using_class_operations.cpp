#include <iostream>
using namespace std;

class Element{
    public:
    int i;
    int j;
    int x;
};

class Sparse{
private:
    int m;
    int n;
    int num;
    Element *ele;
public:
    Sparse(int m, int n, int num){
        this->m=m;
        this->n=n;
        this->num=num;
        ele=new Element[this->num];
    }
    ~Sparse(){
        delete []ele;
    }

// operator>> and operator<< are overloaded operators, which are used 
// to overload the cin and cout operators (overload means to give a new
// definition to an already defined operator) 

    friend istream & operator>>(istream &is, Sparse &s); // cin>>s;
    friend ostream & operator<<(ostream &os, Sparse &s); // cout<<s;

// Operator overloading in C++ can be done using both member functions and friend functions
    Sparse operator+(Sparse &s);
};

// This is a friend function, so it can access private members of the class
istream & operator>>(istream &is, Sparse &s){
    cout<<"\nEnter non-zero elements:";
    for(int i=0;i<s.num;i++){
        cin>>s.ele[i].i>>s.ele[i].j>>s.ele[i].x;
    }
    return is; // istream and ostream are classes, so we can use them as return types
}

// Since this is a friend function, scope resolution operator is not used
ostream & operator<<(ostream &os, Sparse &s){
    int k=0;
    cout<<endl;
    for(int i=0;i<s.m;i++){
        for(int j=0;j<s.n;j++){
            if(s.ele[k].i==i && s.ele[k].j==j) cout<<s.ele[k++].x<<" ";
            else cout<<"0 ";
        }
        cout<<endl;
    }
    return os;
}

Sparse Sparse::operator+(Sparse &s){
    int i,j,k;
    if(m!=s.m || n!=s.n) return Sparse(0,0,0);
    i=j=k=0;
    Sparse *sum=new Sparse(m,n,num+s.num);
    while(i<num && j<s.num){
        if(ele[i].i<s.ele[j].i) sum->ele[k++]=ele[i++];
        else if(ele[i].i>s.ele[j].i) sum->ele[k++]=s.ele[j++];
        else{
            if(ele[i].j<s.ele[j].j) sum->ele[k++]=ele[i++];
            else if(ele[i].j>s.ele[j].j) sum->ele[k++]=s.ele[j++];
            else{
                sum->ele[k]=ele[i];
                sum->ele[k++].x=ele[i++].x+s.ele[j++].x;
            }
        }
    }
    for(;i<num;i++) sum->ele[k++]=ele[i];
    for(;j<s.num;j++) sum->ele[k++]=s.ele[j];
    sum->m=m;
    sum->n=n;
    sum->num=k;

    return *sum;
}


int main(){
    Sparse s1(5,5,5);
    Sparse s2(5,5,5);
    cin>>s1;
    cout<<s1;
    cin>>s2;
    cout<<s2;

    Sparse sum=s1+s2;
    cout<<sum;
    return 0;
}