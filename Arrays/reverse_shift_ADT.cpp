#include <iostream>
using namespace std;

struct Array{
    int *A;
    int size;
    int length;
};

void Display(struct Array arr){
    int i;
    cout<<"\nElements are\n";
    for(i=0;i<arr.length;i++) cout<<arr.A[i]<<" ";
}

void swap(int *x, int *y){
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

// Reversing an array (using auxiliary array):
void Reverse_AA(struct Array *arr){
    int *B;
    B=new int[arr->length];
    for(int i=arr->length-1,j=0;i>=0;i--,j++) B[j]=arr->A[i];
    for(int i=0;i<arr->length;i++) arr->A[i]=B[i];
}

// Reversing an array (without auxialiary array):
void Reverse(struct Array *arr){
    for(int i=0,j=arr->length-1;i<j;i++,j--){
        swap(&arr->A[i],&arr->A[j]);
    }
}

// Left Shift (the first element is removed):
void LShift(struct Array *arr){
    for(int i=0;i<arr->length-1;i++) swap(&arr->A[i],&arr->A[i+1]);
    arr->A[arr->length-1]=0;
}

// Left Roatate (the first element becomes last element):
void LRotate(struct Array *arr){
    int x;
    x=arr->A[0];
    for(int i=0;i<arr->length-1;i++) swap(&arr->A[i],&arr->A[i+1]);
    arr->A[arr->length-1]=x;
}

// Right Shift (the last element is removed):
void RShift(struct Array *arr){
    for(int i=arr->length-1;i>0;i--) swap(&arr->A[i],&arr->A[i-1]);
    arr->A[0]=0;
}

// Right Rotate (the last element becomes first element):
void RRotate(struct Array *arr){
    int x;
    x=arr->A[arr->length-1];
    for(int i=arr->length-1;i>0;i--) swap(&arr->A[i],&arr->A[i-1]);
    arr->A[0]=x;
}

int main(){
    struct Array arr;
    int n,index,x;
    cout<<"\nPlease enter size of the array: ";
    cin>>arr.size;
    arr.A=new int[arr.size];
    arr.length=0;

    cout<<"\nEnter number of numbers to be stored in array: ";
    cin>>n;
    cout<<"\nEnter all elements:\n";
    for(int i=0;i<n;i++) scanf("%d",&arr.A[i]);
    arr.length=n;

    Reverse_AA(&arr);
    Display(arr);
    Reverse(&arr);
    Display(arr);
    LShift(&arr);
    Display(arr);
    LRotate(&arr);
    Display(arr);
    RShift(&arr);
    Display(arr);
    RRotate(&arr);
    Display(arr);

    return 0;
}