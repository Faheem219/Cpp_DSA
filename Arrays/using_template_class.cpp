#include <iostream>
using namespace std;

template<class T>
class Array{
private:
    T *A;
    int size;
    int length;
public:
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
    void Insert(int index, T value);
    void Delete(int index);
};

template<class T>
void Array<T>::Display(){
    cout<<"\nElements are\n";
    for(int i=0;i<length;i++) 
        cout<<A[i]<<" ";
}

template<class T>
void Array<T>::Insert(int index, T value){
    if(index >= 0 && index <= length){
        for(int i=length; i>index; i--)
            A[i] = A[i-1];
        A[index] = value;
        length++;
    }
}

template<class T>
void Array<T>::Delete(int index){
    if(index >= 0 && index < length){
        for(int i=index; i<length-1; i++)
            A[i] = A[i+1];
        length--;
    }
}

int main(){
    Array<float> arr(10);
    arr.Insert(0, 5.2);
    arr.Insert(1, 10.9);
    arr.Insert(2, 15.4);
    arr.Display();
    return 0;
}