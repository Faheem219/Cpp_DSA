#include <iostream>
using namespace std;

struct Array{
    int *A;
    int size;
    int length;
};

void Display(struct Array arr){
    cout<<"\nElements are\n";
    for(int i=0;i<arr.length;i++) 
        cout<<arr.A[i]<<" ";
}

void Insert(struct Array &arr, int index, int value){
    if(index >= 0 && index <= arr.length){
        for(int i=arr.length; i>index; i--)
            arr.A[i] = arr.A[i-1];
        arr.A[index] = value;
        arr.length++;
    }
}

void Delete(struct Array &arr, int index){
    if(index >= 0 && index < arr.length){
        for(int i=index; i<arr.length-1; i++)
            arr.A[i] = arr.A[i+1];
        arr.length--;
    }
}

struct Array Merge(struct Array arr1, struct Array arr2){
    struct Array arr3;
    arr3.size = arr1.size + arr2.size;
    arr3.A = new int[arr3.size];
    int i = 0, j = 0, k = 0;
    while(i < arr1.length && j < arr2.length){
        if(arr1.A[i] < arr2.A[j])
            arr3.A[k++] = arr1.A[i++];
        else
            arr3.A[k++] = arr2.A[j++];
    }
    for(; i < arr1.length; i++)
        arr3.A[k++] = arr1.A[i];
    for(; j < arr2.length; j++)
        arr3.A[k++] = arr2.A[j];
    arr3.length = arr1.length + arr2.length;
    return arr3;
}

struct Array Union(struct Array arr1, struct Array arr2){
    struct Array arr3;
    arr3.size = arr1.size + arr2.size;
    arr3.A = new int[arr3.size];
    int i = 0, j = 0, k = 0;
    while(i < arr1.length && j < arr2.length){
        if(arr1.A[i] < arr2.A[j])
            arr3.A[k++] = arr1.A[i++];
        else if(arr2.A[j] < arr1.A[i])
            arr3.A[k++] = arr2.A[j++];
        else{
            arr3.A[k++] = arr1.A[i++];
            j++;
        }
    }
    for(; i < arr1.length; i++)
        arr3.A[k++] = arr1.A[i];
    for(; j < arr2.length; j++)
        arr3.A[k++] = arr2.A[j];
    arr3.length = k;
    return arr3;
}

struct Array Intersection(struct Array arr1, struct Array arr2){
    struct Array arr3;
    arr3.size = arr1.size + arr2.size;
    arr3.A = new int[arr3.size];
    int i = 0, j = 0, k = 0;
    while(i < arr1.length && j < arr2.length){
        if(arr1.A[i] < arr2.A[j])
            i++;
        else if(arr2.A[j] < arr1.A[i])
            j++;
        else{
            arr3.A[k++] = arr1.A[i++];
            j++;
        }
    }
    arr3.length = k;
    return arr3;
}

struct Array Difference(struct Array arr1, struct Array arr2){
    struct Array arr3;
    arr3.size = arr1.size + arr2.size;
    arr3.A = new int[arr3.size];
    int i = 0, j = 0, k = 0;
    while(i < arr1.length && j < arr2.length){
        if(arr1.A[i] < arr2.A[j])
            arr3.A[k++] = arr1.A[i++];
        else if(arr2.A[j] < arr1.A[i])
            j++;
        else{
            i++;
            j++;
        }
    }
    for(; i < arr1.length; i++)
        arr3.A[k++] = arr1.A[i];
    arr3.length = k;
    return arr3;
}

int main(){
    struct Array arr1, arr2, arr3;
    int choice, index, value;
    int n;

    cout<<"\nPlease enter size of the Array 1: ";
    cin>>arr1.size;
    arr1.A = new int[arr1.size];
    arr1.length = 0;

    cout<<"\nEnter number of numbers to be stored in Array 1: ";
    cin>>n;
    cout<<"\nEnter all elements:\n";
    for(int i=0; i<n; i++)
        cin>>arr1.A[i];
    arr1.length = n;

    cout<<"\nPlease enter size of the Array 2: ";
    cin>>arr2.size;
    arr2.A = new int[arr2.size];
    arr2.length = 0;

    cout<<"\nEnter number of numbers to be stored in Array 2: ";
    cin>>n;
    cout<<"\nEnter all elements:\n";
    for(int i=0; i<n; i++)
        cin>>arr2.A[i];
    arr2.length = n;

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
                Display(arr1);
                cout<<"\nArray 2:";
                Display(arr2);
                break;
            case 2:
                cout<<"\nEnter index: ";
                cin>>index;
                cout<<"Enter value: ";
                cin>>value;
                Insert(arr1, index, value);
                break;
            case 3:
                cout<<"\nEnter index: ";
                cin>>index;
                Delete(arr1, index);
                break;
            case 4:
                arr3 = Merge(arr1, arr2);
                cout<<"\nMerged Array:";
                Display(arr3);
                break;
            case 5:
                arr3 = Union(arr1, arr2);
                cout<<"\nUnion Array:";
                Display(arr3);
                break;
            case 6:
                arr3 = Intersection(arr1, arr2);
                cout<<"\nIntersection Array:";
                Display(arr3);
                break;
            case 7:
                arr3 = Difference(arr1, arr2);
                cout<<"\nDifference Array:";
                Display(arr3);
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