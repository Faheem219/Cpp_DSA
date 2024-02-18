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
    T MissingElement();
    T MissingElement_S();
    T MissingElement_H();
};

template<class T>
void Array<T>::Display(){
    cout<<"\nElements are\n";
    for(int i=0;i<length;i++) 
        cout<<A[i]<<" ";    
}

// Find multilple missing elements in a sorted array (Time complexity O(n)):
template<class T>
T Array<T>::MissingElement(){
    T diff = A[0];
    for(int i=0;i<length;i++){
        if(A[i]-i != diff){
            while(diff<A[i]-i){
                cout<<i+diff<<" ";
                diff++;
            }
        }
    }
    return 0;
}

// Find multiple missing elements using Hash table/Bitset (Time complexity O(n), 
// this is more efficient than the previous method, but it requires extra space):
template<class T>
T Array<T>::MissingElement_H(){
    T diff = A[0];
    T* hashTable = new T[length];
    for(int i=0;i<length;i++){
        hashTable[i] = 0;
    }
    for(int i=0;i<length;i++){
        hashTable[A[i]] = 1;
    }
    for(int i=0;i<length;i++){
        if(hashTable[i] == 0){
            cout<<i<<" ";
        }
    }
    delete[] hashTable;
    return 0;
}

// Find a single missing element in a sorted array (Time complexity O(n)):
template<class T>
T Array<T>::MissingElement_S(){
    T diff = A[0];
    for(int i=0;i<length;i++){
        if(A[i]-i != diff){
            return i+diff;
        }
    }
    return 0;
}

int main(){
    Array <int> arr(5);
    arr.A[0] = 6;
    arr.A[1] = 7;
    arr.A[2] = 8;
    arr.A[3] = 9;
    arr.A[4] = 11;
    arr.MissingElement();
    arr.MissingElement_H();
    return 0;
}