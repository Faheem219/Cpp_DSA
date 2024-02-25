#include <iostream>
using namespace std;

class Term{
    public:
    int coeff;
    int exp;
};

class Poly{
private:
    int n;
    class Term *t;
public:
    Poly(int n){
        this->n=n;
        t=new Term[this->n];
    }
    ~Poly(){
        delete []t;
    }
    friend istream & operator>>(istream &is, Poly &p);
    friend ostream & operator<<(ostream &os, Poly &p);
    Poly operator+(Poly &p);
    double operator()(double x);
};

istream & operator>>(istream &is, Poly &p){
    cout<<"\nEnter the terms (coeff, exp):";
    for(int i=0;i<p.n;i++){
        cout<<"\nEnter:";
        cin>>p.t[i].coeff>>p.t[i].exp;
    }
    return is;
}

ostream & operator<<(ostream &os, Poly &p){
    cout<<"\nThe polynomial is: p(x) = ";
    for(int i=0; i<p.n; i++){
        cout<<" + "<<p.t[i].coeff<<".x^"<<p.t[i].exp;
    }
    return os;
}

double Poly::operator()(double x) {
    double result = 0.0;
    for (int i = 0; i < n; i++) {
        result += t[i].coeff * pow(x, t[i].exp);
    }
    return result;
}

// Polynomial Addition:
Poly Poly::operator+(Poly &p){
    int i,j,k;
    i=j=k=0;
    Poly *sum=new Poly(n+p.n);
    while(i<n && j<p.n){
        if(t[i].exp>p.t[j].exp) sum->t[k++]=t[i++];
        else if(t[i].exp<p.t[j].exp) sum->t[k++]=p.t[j++];
        else{
            sum->t[k].exp=t[i].exp;
            sum->t[k++].coeff=t[i++].coeff+p.t[j++].coeff;
        }
    }
    for(;i<n;i++) sum->t[k++]=t[i];
    for(;j<p.n;j++) sum->t[k++]=p.t[j];
    sum->n=k;
    return *sum;
}

int main(){
    class Poly p(3);
    class Poly q(3);
    double x,eval;
    cin>>p;
    cout<<p;
    cout<<"\nEnter the value of x:";
    cin>>x;
    eval=p(x);
    cout<<"\nValue of polynomial at x="<<x<<" is: "<<eval;
    cin>>q;
    cout<<q;
    Poly r=p+q;
    cout<<r;
    return 0;
}