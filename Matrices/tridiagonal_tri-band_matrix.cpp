#include <iostream>
using namespace std;

template<class T>
class Matrix{
    public:
        T *A;
        int n;
        Matrix(){
            n = 5;
            A = new T[3*n-2];
        }
        Matrix(int n){
            this->n=n;
            A = new T[3*n-2];
        }
        ~Matrix(){
            delete []A;
        }
        void Set(int i, int j, int x);
        T Get(int i, int j);
        void Display();
        int GetDimension(){return n;}
};

template<class T>
void Matrix<T>::Display(){
    for(int i=1; i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) cout<<A[n-1+i-1]<<" ";
            else if(i-j==1) cout<<A[i-1]<<" ";
            else if(j-i==1) cout<<A[2*n-1+i-1]<<" ";
            else cout<<"0 ";
        }
        cout<<"\n";
    }
}

// Storing matrix using 1D array (Row Major Mapping):
template<class T>
void Matrix<T>::Set(int i, int j, int x){
    if(i==j) A[n-1+i-1]=x;
    else if(i-j==1) A[i-1]=x;
    else if(j-i==1) A[2*n-1+i-1]=x;
}

template<class T>
T Matrix<T>::Get(int i, int j){
    if(i==j) return A[n-1+i-1];
    else if(i-j==1) return A[i-1];
    else if(j-i==1) return A[2*n-1+i-1];
    else return 0;
}

int main(){
    int sz,x;
    cout<<"\nEnter the dimension of the matrix: "<<endl;
    cin>>sz;
    Matrix<int> M(sz);
    cout<<"\nEnter all elements:\n";
    for(int i=1; i<=sz;i++){
        for(int j=1;j<=sz;j++){
            if(i==j){
                cout<<"Enter element at index ("<<i<<","<<j<<"): ";
                cin>>x;
                M.Set(i,j,x);
            }
            else if(i-j==1){
                cout<<"Enter element at index ("<<i<<","<<j<<"): ";
                cin>>x;
                M.Set(i,j,x);
            }
            else if(j-i==1){
                cout<<"Enter element at index ("<<i<<","<<j<<"): ";
                cin>>x;
                M.Set(i,j,x);
            }
        }
    }
    M.Display();
    return 0;
}