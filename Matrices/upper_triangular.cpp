#include <iostream>
using namespace std;

template<class T>   
class Matrix{
    public:
        T *A;
        int n;
        Matrix(){
            n = 5;
            A = new T[n*(n+1)/2];
        }
        Matrix(int n){
            this->n=n;
            A = new T[n*(n+1)/2];
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
    cout<<"\nEnter the elements of the matrix: ";
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i<=j){
                cout<<"Enter element at index ("<<i<<","<<j<<"): ";
                cin>>A[(i-1)*n - (i-2)*(i-1)/2 + (j-i)];
            }
        }
    }
}

template<class T>
void Matrix<T>::Display(){
    for(int i=1; i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i<=j) cout<<A[(i-1)*n - (i-2)*(i-1)/2 + (j-i)]<<" ";
            // For Column Major Mapping: cout<<A[j*(j-1)/2+i-1]<<" ";
            else cout<<"0 ";
        }
        cout<<"\n";
    }
}

// Storing matrix using 1D array (Row Major Mapping):
template<class T>
void Matrix<T>::Set(int i, int j, int x){
    if(i<=j) A[(i-1)*n - (i-2)*(i-1)/2 + (j-i)]=x;
    // For Column Major Mapping: A[j*(j-1)/2+i-1]=x;
}

template<class T>
T Matrix<T>::Get(int i, int j){
    if(i<=j) return A[(i-1)*n - (i-2)*(i-1)/2 + (j-i)];
    // For Column Major Mapping: return A[j*(j-1)/2+i-1];
    else return 0;
}

int main(){
    int sz,x;
    cout<<"\nEnter the dimension of the matrix: "<<endl;
    cin>>sz;
    Matrix<int> M(sz);
    cout<<"\nEnter all elements:\n";
    M.Create();
    M.Display();
    cout<<"\n"<<M.Get(3,3);
    return 0;
}