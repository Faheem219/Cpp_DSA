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

// Helper function to check if an element is present in the array
bool isPresent(struct Array *arr, int x){
    for(int i=0;i<arr->length;i++){
        if(arr->A[i]==x)
            return true;
    }
    return false;
}

// Merging of array:
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

// Union of a sorted array (Time complexity O(n), in case of unsorted arrays
// it takes O(n^2) time):
struct Array* Union(struct Array *arr1, struct Array *arr2){
    int i,j,k;
    i=j=k=0;
    struct Array *arr3 = new Array; // allocate memory for arr3
    arr3->A = new int[arr1->size + arr2->size]; // allocate memory for arr3->A
    while (i<arr1->length && j<arr2->length){
        if(arr1->A[i]<arr2->A[j]) arr3->A[k++]=arr1->A[i++];
        else if(arr2->A[j]<arr1->A[i]) arr3->A[k++]=arr2->A[j++];
        else{
            arr3->A[k++]=arr1->A[i++];
            j++;
        }
    }
    for(;i<arr1->length;i++) arr3->A[k++]=arr1->A[i];
    for(;j<arr2->length;j++) arr3->A[k++]=arr2->A[j];
    arr3->length=k;
    arr3->size=arr1->size+arr2->size;
    return arr3;
}

// Intersection of a sorted array (Time complexity O(n), in case of unsorted arrays
// it takes O(n^2) time):
struct Array* Intersection(struct Array *arr1, struct Array *arr2){
    int i,j,k;
    i=j=k=0;
    struct Array *arr3 = new Array; // allocate memory for arr3
    arr3->A = new int[arr1->size + arr2->size]; // allocate memory for arr3->A
    while (i<arr1->length && j<arr2->length){
        if(arr1->A[i]<arr2->A[j]) i++;
        else if(arr2->A[j]<arr1->A[i]) j++;
        else{
            arr3->A[k++]=arr1->A[i++];
            j++;
        }
    }
    arr3->length=k;
    arr3->size=arr1->size+arr2->size;
    return arr3;
}

// Difference of a sorted array (Time complexity O(n), in case of unsorted arrays
// it takes O(n^2) time):
struct Array* Difference(struct Array *arr1, struct Array *arr2){
    int i,j,k;
    i=j=k=0;
    struct Array *arr3 = new Array; // allocate memory for arr3
    arr3->A = new int[arr1->size + arr2->size]; // allocate memory for arr3->A
    while (i<arr1->length && j<arr2->length){
        if(arr1->A[i]<arr2->A[j]) arr3->A[k++]=arr1->A[i++];
        else if(arr2->A[j]<arr1->A[i]) j++;
        else{
            i++;
            j++;
        }
    }
    for(;i<arr1->length;i++) arr3->A[k++]=arr1->A[i];
    arr3->length=k;
    arr3->size=arr1->size+arr2->size;
    return arr3;
}

// Union of an unsorted array:
struct Array* Union_US(struct Array *arr1, struct Array *arr2){
    int i,j,k;
    i=j=k=0;
    struct Array *arr3= new Array;
    arr3->A = new int[arr1->size+arr2->size];
    for(;i<arr1->length;i++) arr3->A[k++]=arr1->A[i];
    for(j=0;j<arr2->length;j++){
        if(!isPresent(arr1, arr2->A[j]))
            arr3->A[k++]=arr2->A[j];
    }
    arr3->length=k;
    arr3->size=arr1->size+arr2->size;
    return arr3;
}
    
// Intersection of an unsorted array:
struct Array* Intersection_US(struct Array *arr1,struct Array *arr2){
    int i,j,k;
    i=j=k=0;
    struct Array *arr3= new Array;
    arr3->A = new int[arr1->size+arr2->size];
    for(;i<arr1->length;i++){
        if(isPresent(arr2,arr1->A[i])) arr3->A[k++]=arr1->A[i];
    }
    arr3->length=k;
    arr3->size=arr1->size+arr2->size;
    return arr3;
}

// Difference of an unsorted array:
struct Array* Difference_US(struct Array *arr1,struct Array *arr2){
    int i,j,k;
    i=j=k=0;
    struct Array *arr3= new Array;
    arr3->A = new int[arr1->size+arr2->size];
    for(;i<arr1->length;i++){
        if(!isPresent(arr2,arr1->A[i])) arr3->A[k++]=arr1->A[i];
    }
    arr3->length=k;
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

    arr3=Union(&arr1,&arr2);
    Display(*arr3);
    arr3=Intersection(&arr1,&arr2);
    Display(*arr3);
    arr3=Difference(&arr1,&arr2);
    Display(*arr3);
    arr3=Union_US(&arr1,&arr2);
    Display(*arr3);
    arr3=Intersection_US(&arr1,&arr2);
    Display(*arr3);
    arr3=Difference_US(&arr1,&arr2);
    Display(*arr3);

    free(arr1.A);
    free(arr2.A);
    free(arr3->A);

    return 0;
}