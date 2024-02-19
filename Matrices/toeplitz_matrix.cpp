#include <iostream>
using namespace std;

template<class T>
class Matrix{
    public:
        T *A;
        int n;
        Matrix(){
            n = 5;
            A = new T[n+n-1];
        }
        Matrix(int n){
            this->n=n;
            A = new T[n+n-1];
        }
        ~Matrix(){
            delete []A;
        }
        void Set(int i, int j, int x);
        T Get(int i, int j);
        void Display();
        int GetDimension(){return n;}
        void Create();
};

template<class T>
void Matrix<T>::Create(){
    cout<<"\nEnter the elements of the first row: ";
    for(int j=1;j<=n;j++){
        cout<<"Enter element at index (0,"<<j<<"): ";
        cin>>A[j-1];
    }
    cout<<"\nEnter the elements of the first column: ";
    for(int i=2;i<=n;i++){
        cout<<"Enter element at index ("<<i<<",0): ";
        cin>>A[n+i-2];
    }
}

template<class T>
void Matrix<T>::Display(){
    for(int i=1; i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<A[n+i-j-1]<<" ";
        }
        cout<<"\n";
    }
}

// Storing matrix using 1D array (Row Major Mapping):
template<class T>
void Matrix<T>::Set(int i, int j, int x){
    if(i<=j) A[j-i]=x;
    else A[n+i-j-1]=x;
}

template<class T>
T Matrix<T>::Get(int i, int j){
    if(i<=j) return A[j-i];
    else return A[n+i-j-1];
}

int main(){
    int sz,x;
    cout<<"\nEnter the dimension of the matrix: "<<endl;
    cin>>sz;
    Matrix<int> M(sz);
    M.Create();
    M.Display();
    return 0;
}