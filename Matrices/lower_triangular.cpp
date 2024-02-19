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
};

template<class T>
void Matrix<T>::Display(){
    for(int i=1; i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i>=j) cout<<A[i*(i-1)/2+j-1]<<" ";
            // For Column Major Mapping: cout<<A[size*(j-1)-(j-2)*(j-1)/2+i-j]<<" ";
            else cout<<"0 ";
        }
        cout<<"\n";
    }
}

// Storing matrix using 1D array (Row Major Mapping):
template<class T>
void Matrix<T>::Set(int i, int j, int x){
    if(i>=j) A[i*(i-1)/2+j-1]=x;
    // For Column Major Mapping: A[size*(j-1)-(j-2)*(j-1)/2+i-j]=x;
}

template<class T>
T Matrix<T>::Get(int i, int j){
    if(i>=j) return A[i*(i-1)/2+j-1];
    // For Column Major Mapping: return A[size*(j-1)-(j-2)*(j-1)/2+i-j];
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
            if(i>=j){
                cout<<"\nEnter value of ("<<i<<","<<j<<")th element: ";
                cin>>x;
                M.Set(i,j,x);
            }
        }
    }
    cout<<"\nDiagonal matrix is: \n";
    M.Display();
    cout<<"\n"<<M.Get(3,3);

    return 0;
}