#include <iostream>
using namespace std;

struct Array{
    int *A;
    int size;
    int length;
};

void Display(struct Array arr1){
    int i;
    cout<<"\nElements are\n";
    for(i=0;i<arr1.length;i++) cout<<arr1.A[i]<<" ";
}

void swap(int *x, int *y){
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

// Inserting an element in the sorted position:
void InsertSort(struct Array *arr1, int x){
    int i=arr1->length-1;
    if(arr1->length==arr1->size) return;
    while(i>=0 && arr1->A[i]>x){
        arr1->A[i+1]=arr1->A[i];
        i--;
    }
    arr1->A[i+1]=x;
    arr1->length++;
}

// Checking whether Array is sorted or not:
bool isSorted(struct Array arr1){
    for(int i=0;i<arr1.length-1;i++){
        if(arr1.A[i]>arr1.A[i+1]) return false;
    }
    return true;
}

// Rearr1anging +ve on right side and -ve on left side:
void Rearr1ange(struct Array *arr1){
    int i=0,j=arr1->length-1;
    while(i<j){
        while(arr1->A[i]<0) i++;
        while(arr1->A[j]>=0) j--;
        if(i<j) swap(&arr1->A[i],&arr1->A[j]);
    }
}

// Merging of Sorted Arrays (It takes O(m+n) time, therefore wherever time complexity 
// is in the terms of 2 variables, it means merging operation is performed):
struct Array* Merge(struct Array *arr1, struct Array *arr2){
    int i,j,k;
    i=j=k=0;
    struct Array *arr3 = new Array; // allocate memory for arr3
    arr3->A = new int[arr1->size + arr2->size]; // allocate memory for arr3->A
    while (i<arr1->length && j<arr2->length){
        if(arr1->A[i]<arr2->A[j]) arr3->A[k++]=arr1->A[i++];
        else arr3->A[k++]=arr2->A[j++];
    }
    for(;i<arr1->length;i++) arr3->A[k++]=arr1->A[i];
    for(;j<arr2->length;j++) arr3->A[k++]=arr2->A[j];
    arr3->length=arr1->length+arr2->length;
    arr3->size=arr1->size+arr2->size;
    return arr3;
}

int main(){
    struct Array arr1,arr2,*arr3;
    int n,index,x;
    cout<<"\nPlease enter size of the Array: ";
    cin>>arr1.size;
    arr1.A=new int[arr1.size];
    arr1.length=0;

    cout<<"\nEnter number of numbers to be stored in Array: ";
    cin>>n;
    cout<<"\nEnter all elements:\n";
    for(int i=0;i<n;i++) scanf("%d",&arr1.A[i]);
    arr1.length=n;

    cout<<"\nPlease enter size of the Array 2: ";
    cin>>arr2.size;
    arr2.A=new int[arr2.size];
    arr2.length=0;

    cout<<"\nEnter number of numbers to be stored in Array 2: ";
    cin>>n;
    cout<<"\nEnter all elements:\n";
    for(int i=0;i<n;i++) scanf("%d",&arr2.A[i]);
    arr2.length=n;

/*
    cout<<"\n"<<isSorted(arr1)<<endl;
    InsertSort(&arr1,2);
    Display(arr1);
    Rearr1ange(&arr1);
    Display(arr1);
*/
    arr3=Merge(&arr1,&arr2);
    Display(*arr3);

    return 0;
}
