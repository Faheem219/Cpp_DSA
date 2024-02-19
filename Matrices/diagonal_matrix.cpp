#include <iostream>
using namespace std;

template<class T>
class Matrix{
    public:
        T *A;
        int size;
        Matrix(){
            size = 5;
            A = new T[size];
        }
        Matrix(int size){
            this->size=size;
            A = new T[size];
        }
        ~Matrix(){
            delete []A;
        }
        void Set(int i, int j, int x);
        T Get(int i, int j);
        void Display();
};

template<class T>
void Matrix<T>::Set(int i, int j, int x){
    if(i==j) A[i-1]=x;
}

template<class T>
T Matrix<T>::Get(int i, int j){
    if(i==j) return A[i-1];
    else return 0;
}

template<class T>
void Matrix<T>::Display(){
    for(int i=0; i<size;i++){
        for(int j=0;j<size;j++){
            if(i==j) cout<<A[i]<<" ";
            else cout<<"0 ";
        }
        cout<<"\n";
    }
}

int main(){
    int sz,x;
    cout<<"\nEnter the size of the diagonal matrix: "<<endl;
    cin>>sz;
    Matrix<int> M(sz);
    cout<<"\nEnter all diagonal elements:\n";
    for(int i=0; i<sz; i++){
        cout<<"\nEnter value of ("<<i+1<<","<<i+1<<")th element: ";
        cin>>x;
        M.Set(i+1,i+1,x);
    }
    cout<<"\nDiagonal matrix is: \n";
    M.Display();
    cout<<"\n"<<M.Get(3,3);
    return 0;
}
