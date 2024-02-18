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
    void FindDuplicates();
    void CountDuplicates();
    void FindDuplicates_US();
    void FindDuplicates_Hashing();
    T max();
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

// Finding duplicates in a sorted array (Time Complexity: O(n)):
template<class T>
void Array<T>::FindDuplicates(){
    int lastDuplicate = 0;
    for(int i=0;i<length-1;i++){
        if(A[i] == A[i+1] && A[i] != lastDuplicate){
            cout<<A[i]<<" ";
            lastDuplicate = A[i];
        }
    }
}

// Counting duplicates in a sorted array (Time Complexity: O(n)):
template<class T>
void Array<T>::CountDuplicates(){
    int lastDuplicate = 0;
    for(int i=0;i<length-1;i++){
        if(A[i] == A[i+1] && A[i] != lastDuplicate){
            int j = i+1;
            while(A[j] == A[i]) j++;
            cout<<A[i]<<" is appearing "<<j-i<<" times."<<endl;
            lastDuplicate = A[i];
        }
    }
}

// Finding duplicates in an unsorted array (Time Complexity: O(n^2)):
template<class T>
void Array<T>::FindDuplicates_US(){
    for(int i=0;i<length-1;i++){
        int count = 1;
        if(A[i] != -1){
            for(int j=i+1;j<length;j++){
                if(A[i] == A[j]){
                    count++;
                    A[j] = -1;
                }
            }
            if(count > 1) cout<<A[i]<<" is appearing "<<count<<" times."<<endl;
        }
    }
}

// Finding duplicates in any array using hashing (Time Complexity: O(n)):
template<class T>
void Array<T>::FindDuplicates_Hashing(){
    int *h= new int[max()+1];
    for(int i=0;i<=max();i++) h[i] = 0;
    for(int i=0;i<length;i++){
        h[A[i]]++;
    }
    for(int i=0;i<=max();i++){
        if(h[i] > 1) cout<<i<<" is appearing "<<h[i]<<" times."<<endl;
    }
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

    cout<<"\nDuplicates are: ";
    arr.FindDuplicates();

    cout<<"\nCount of duplicates: "<<endl;
    arr.CountDuplicates();

/*
    cout<<"\nDuplicates are (Unsorted array): ";
    arr.FindDuplicates_US();
*/

    cout<<"\nDuplicates are (Hashing): ";
    arr.FindDuplicates_Hashing();

    return 0;
}