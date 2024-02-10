#include <iostream>
using namespace std;

// Most efficient way to create a user defined array utilizing structure & heap:
struct Array{
    int *A;
    int size;
    int length;
};

void Display(struct Array arr);
void Append(struct Array *arr,int x);
void Insert(struct Array *arr, int index, int x);
int Delete(struct Array *arr, int index);
int LinearSearch(struct Array arr,int key);
void swap(int *x, int *y);
int TLS(struct Array *arr, int key);
int BinarySearch(struct Array arr, int key);
int RBinSearch(int a[],int l, int h, int key);
int Get(struct Array arr, int index);
void Set(struct Array *arr,int index, int x);
int Max(struct Array arr);
int Min(struct Array arr);
int Sum(struct Array arr);
float Avg(struct Array arr);

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

/*
    Append(&arr, 10);
    Insert(&arr, 5, 10);
    cout<<"\n"<<Delete(&arr,0)<<endl;
    Display(arr);
    cout<<"\n"<<LinearSearch(arr, 5)<<endl;
    cout<<"\n"<<TLS(&arr, 5)<<endl;
*/
    cout<<"\n"<<BinarySearch(arr, 5)<<endl;
    cout<<"\n"<<RBinSearch(arr.A,0,arr.length,5);
    cout<<"\n"<<Get(arr, 3)<<endl;
    Set(&arr, 3, 5);
    cout<<"\n"<<Max(arr)<<endl;
    cout<<"\n"<<Min(arr)<<endl;
    cout<<"\n"<<Sum(arr)<<endl;
    cout<<"\n"<<Avg(arr)<<endl;
    return 0;
}

// Displaying the array:
void Display(struct Array arr){
    int i;
    cout<<"\nElements are\n";
    for(i=0;i<arr.length;i++) cout<<arr.A[i]<<" ";
}

// Appending an array (inserting at last element):
void Append(struct Array *arr,int x){
    if(arr->length<arr->size)
        arr->A[arr->length++]=x;
}

// Inserting an element in the middle of an array:
void Insert(struct Array *arr, int index, int x){
    if(index>=0 && index<=arr->length){
        for(int i=arr->length;i>index;i--) arr->A[i]=arr->A[i-1];
        arr->A[index]=x;
        arr->length++;
    }

}

// Deleting element from a given index:
int Delete(struct Array *arr, int index){
    int x=0;
    if (index>=0 && index<arr->length){
        x=arr->A[index];
        for(int i=index;i<arr->length-1;i++) arr->A[i]=arr->A[i+1];
        arr->length--;
        return x; // Returning deleted element
    }
    return 0; // If index is invalid
}

// Searching for an element and returning its index using linear search:
// It has the following time complexities: Best case-O(1), Worst case-O(n), Avg case-O(n).
// Usually only the worst case is considered as avg case is hard to find and in most 
// cases it is the same as worst case.
int LinearSearch(struct Array arr,int key){
    for(int i=0;i<arr.length;i++)
    {
        if(key==arr.A[i]) return i;
    }
    return -1;
}

// We can improve linear search by swapping or transposition, so that if the same 
// element is being searched for repeatedly, the time complexity can be reduced.
void swap(int *x, int *y){
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

// Improved linear search using transposition (it will swap the searched element
// with the previous element):
int TLS(struct Array *arr, int key){
    for(int i=0;i<arr->length;i++){
        if(key==arr->A[i]){
            swap(&arr->A[i],&arr->A[i-1]); 
            return i;
        }
    }
    return -1;
}
// Another method is to move the element to the head (front) so swap statement for that
// is: swap(&arr->A[i],&arr->A[0]);

// Binary Search (For proper def, check udemy notes) (SORTED array is required): 
// It can be written recursively and using while loop.
// The recursion used will be a tail recursion so better to use while loop to reduce
// space complexity, as recursion utilizes stack, as discussed in the recursion unit.
// Time complexity for successful search: Best case-O(1), worst & avg case-O(logn base 2)
// for unsuccessful search it is always O(logn base 2).

// Using iteration:
int BinarySearch(struct Array arr, int key){
    int l,h,mid;
    l=0;
    h=arr.length-1;
    while(l<=h){
        mid=(l+h)/2;
        if(key==arr.A[mid]) return mid;
        else if(key<arr.A[mid]) h=mid-1;
        else l=mid+1;
    }
    return -1;
}

// Using Recursion:
int RBinSearch(int a[],int l, int h, int key){
    int mid;
    if(l<=h){
        mid=(l+h)/2;
        if(key==a[mid]) return mid;
        else if(key<a[mid]) return RBinSearch(a,l,mid-1,key);
        else return RBinSearch(a,mid+1,h,key);
    }
    return -1;
}

// Get function:
int Get(struct Array arr, int index){
    if(index>=0 && index<arr.length) return arr.A[index];
    return -1;
}

// Set function:
void Set(struct Array *arr,int index, int x){
    if(index>=0 && index<arr->length) arr->A[index]=x;
}

// Max function:
int Max(struct Array arr){
    int max=arr.A[0];
    for(int i=1;i<arr.length;i++){
        if(arr.A[i]>max) max=arr.A[i];
    }
    return max;
}

// Min function:
int Min(struct Array arr){
    int min=arr.A[0];
    for(int i=1;i<arr.length;i++){
        if(arr.A[i]<min) min=arr.A[i];
    }
    return min;
}

// Sum function:
int Sum(struct Array arr){
    int sum=0;
    for(int i=0;i<arr.length;i++) sum+=arr.A[i];
    return sum;
}

// Avg function:
float Avg(struct Array arr){
    return (float)Sum(arr)/arr.length;
}