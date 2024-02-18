#include <iostream>
using namespace std;

template<class T>
class Array{
private:
    int size;
public:
    T *A;
    int length;
    Array(){
        size = 5;
        A = new T[size];
        length = 0;
    }
    Array(int sz){
        size = sz;
        A = new T[size];
        length = 0;
    }
    ~Array(){
        delete []A;
    }
    void Display();
    void SumK(int k);
    T max();
    void SumK_Hashing(int k);
    void SumK_Sorted(int k);
    void MinMax();
};

template<class T>
void Array<T>::Display(){
    cout<<"\nElements are\n";
    for(int i=0;i<length;i++) 
        cout<<A[i]<<" ";    
}

template<class T>
T Array<T>::max(){
    T max = A[0];
    for(int i=1;i<length;i++){
        if(A[i] > max) max = A[i];
    }
    return max;
}

// Finding a pair of elements with sum K in any array (Time Complexity: O(n^2)):
// The array should not have any duplicates.
template<class T>
void Array<T>::SumK(int k){
    for(int i=0;i<length-1;i++){
        for(int j=i+1;j<length;j++){
            if(A[i] + A[j] == k){
                cout<<"\n"<<A[i]<<" + "<<A[j]<<" = "<<k<<endl;
            }
        }
    }
}

// Finding a pair of elements with sum K using hashing (Time Complexity: O(n)):
// The array should not have any duplicates.
template<class T>
void Array<T>::SumK_Hashing(int k){
    int *H = new int[max()+1];
    for(int i=0;i<=max();i++) H[i] = 0;
    for(int i=0;i<length;i++){
        if(H[k-A[i]] != 0){
            cout<<"\n"<<A[i]<<" + "<<k-A[i]<<" = "<<k<<endl;
        }
        H[A[i]]++;
    }
}

// Finding a pair of elements with sum k in a sorted array (Time Complexity: O(n)):
// The array should not have any duplicates.
template<class T>
void Array<T>::SumK_Sorted(int k){
    int i = 0, j = length-1;
    while(i < j){
        if(A[i] + A[j] == k){
            cout<<"\n"<<A[i]<<" + "<<A[j]<<" = "<<k<<endl;
            i++;
            j--;
        }
        else if(A[i] + A[j] < k) i++;
        else j--;
    }
}

// Finding maximum and minimum elements in a single scan (Time Complexity: O(n)):
template<class T>
void Array<T>::MinMax(){
    T min, max;
    min=max=A[0];
    for(int i=1;i<length;i++){
        if(A[i] < min) min = A[i];
        else if(A[i] > max) max = A[i];
    }
    cout<<"\nThe minimum and maximum elements are: "<<min<<" and "<<max<<endl;
}

int main(){
    int sz;
    cout<<"\nEnter the size of the array: "<<endl;
    cin>>sz;
    Array<int> arr(sz);
    cout<<"\nEnter the number of elements: "<<endl;
    cin>>arr.length;
    cout<<"\nEnter the elements: "<<endl;
    for(int i=0;i<arr.length;i++){
        cin>>arr.A[i];
    }
    arr.Display();

    int k;
    cout<<"\nEnter the value of K: "<<endl;
    cin>>k;
    arr.SumK(k);

    arr.SumK_Hashing(k);
    arr.SumK_Sorted(k);
    arr.MinMax();

    return 0;
}