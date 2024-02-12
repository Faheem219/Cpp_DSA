#include <iostream>
using namespace std;

class Array{
private:
    int size;
    int length;
public:
    int *A;
    Array(){
        size = 5;
        A = new int[size];
        length = 5;
    }
    Array(int sz){
        size = sz;
        A = new int[size];
        length = 5;
    }
    ~Array(){
        delete []A;
    }
    void Display();
    void Insert(int index, int value);
    void Delete(int index);
    Array* Merge(Array arr2);
    Array* Union(Array arr2);
    Array* Intersection(Array arr2);
    Array* Difference(Array arr2);
};

void Array::Display(){
    cout<<"\nElements are\n";
    for(int i=0;i<length;i++) 
        cout<<A[i]<<" ";
}

void Array::Insert(int index, int value){
    if(index >= 0 && index <= length){
        for(int i=length; i>index; i--)
            A[i] = A[i-1];
        A[index] = value;
        length++;
    }
}

void Array::Delete(int index){
    if(index >= 0 && index < length){
        for(int i=index; i<length-1; i++)
            A[i] = A[i+1];
        length--;
    }
}

Array* Array::Merge(Array arr2){
    int i,j,k;
    i=j=k=0;
    Array *arr3 = new Array(size + arr2.size);
    while (i<length && j<arr2.length){
        if(A[i]<arr2.A[j]) arr3->A[k++]=A[i++];
        else arr3->A[k++]=arr2.A[j++];
    }
    for(;i<length;i++) arr3->A[k++]=A[i];
    for(;j<arr2.length;j++) arr3->A[k++]=arr2.A[j];
    arr3->length=k;
    arr3->size=size+arr2.size;
    return arr3;
}

Array* Array::Union(Array arr2){
    int i,j,k;
    i=j=k=0;
    Array *arr3 = new Array(size + arr2.size);
    while (i<length && j<arr2.length){
        if(A[i]<arr2.A[j]) arr3->A[k++]=A[i++];
        else if(arr2.A[j]<A[i]) arr3->A[k++]=arr2.A[j++];
        else{
            arr3->A[k++]=A[i++];
            j++;
        }
    }
    for(;i<length;i++) arr3->A[k++]=A[i];
    for(;j<arr2.length;j++) arr3->A[k++]=arr2.A[j];
    arr3->length=k;
    arr3->size=size+arr2.size;
    return arr3;
}

Array* Array::Intersection(Array arr2){
    int i,j,k;
    i=j=k=0;
    Array *arr3 = new Array(size + arr2.size); // allocate memory for arr3
    while (i<length && j<arr2.length){
        if(A[i]<arr2.A[j]) i++;
        else if(arr2.A[j]<A[i]) j++;
        else{
            arr3->A[k++]=A[i++];
            j++;
        }
    }
    arr3->length=k;
    arr3->size=size+arr2.size;
    return arr3;
}

Array* Array::Difference(Array arr2){
    int i,j,k;
    i=j=k=0;
    Array *arr3 = new Array(size + arr2.size); // allocate memory for arr3
    while (i<length && j<arr2.length){
        if(A[i]<arr2.A[j]) arr3->A[k++]=A[i++];
        else if(arr2.A[j]<A[i]) j++;
        else{
            i++;
            j++;
        }
    }
    for(;i<length;i++) arr3->A[k++]=A[i];
    arr3->length=k;
    arr3->size=size+arr2.size;
    return arr3;
}


int main(){
    Array *arr1, *arr2, *arr3;
    int choice, index, value;
    int n;

    cout<<"\nPlease enter size of the Array 1: ";
    cin>>n;
    arr1 = new Array(n);

    cout<<"\nEnter number of numbers to be stored in Array 1: ";
    cin>>n;
    cout<<"\nEnter all elements:\n";
    for(int i=0; i<n; i++)
        cin>>arr1->A[i];

    cout<<"\nPlease enter size of the Array 2: ";
    cin>>n;
    arr2 = new Array(n);

    cout<<"\nEnter number of numbers to be stored in Array 2: ";
    cin>>n;
    cout<<"\nEnter all elements:\n";
    for(int i=0; i<n; i++)
        cin>>arr2->A[i];

    do{
        cout<<"\n\nMenu:\n";
        cout<<"1. Display\n";
        cout<<"2. Insert\n";
        cout<<"3. Delete\n";
        cout<<"4. Merge\n";
        cout<<"5. Union\n";
        cout<<"6. Intersection\n";
        cout<<"7. Difference\n";
        cout<<"8. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice){
            case 1:
                cout<<"\nArray 1:";
                arr1->Display();
                cout<<"\nArray 2:";
                arr2->Display();
                break;
            case 2:
                cout<<"\nEnter index: ";
                cin>>index;
                cout<<"Enter value: ";
                cin>>value;
                arr1->Insert(index, value);
                break;
            case 3:
                cout<<"\nEnter index: ";
                cin>>index;
                arr1->Delete(index);
                break;
            case 4:
                arr3 = arr1->Merge(*arr2);
                cout<<"\nMerged Array:";
                arr3->Display();
                break;
            case 5:
                arr3 = arr1->Union(*arr2);
                cout<<"\nUnion Array:";
                arr3->Display();
                break;
            case 6:
                arr3 = arr1->Intersection(*arr2);
                cout<<"\nIntersection Array:";
                arr3->Display();
                break;
            case 7:
                arr3 = arr1->Difference(*arr2);
                cout<<"\nDifference Array:";
                arr3->Display();
                break;
            case 8:
                cout<<"\nExiting...";
                break;
            default:
                cout<<"\nInvalid choice!";
        }
    }while(choice != 8);

    return 0;
}