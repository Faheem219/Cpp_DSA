#include <iostream>
using namespace std;

// Anqagram: Two strings are anagrams if they contain the same characters but in different order.
// Checking for anagram (Using hashing):
void anagram(char str[],char str2[]){
    int H[26]={0};
    for(int i=0;str[i]!='\0';i++){
        H[str[i]-97]++;
    }
    for(int i=0;str2[i]!='\0';i++){
        H[str2[i]-97]--;
        if(H[str2[i]-97]<0){
            cout<<"\nNot an anagram"<<endl;
            return;
        }
    }
    for(int i=0;i<26;i++){
        if(H[i]!=0){
            cout<<"\nNot an anagram"<<endl;
            return;
        }
    }
    cout<<"\nAnagram"<<endl;
}
// If there are no duplicate characters, we can use bitwise operations to check for anagrams.

// Permutations of a string: All possible arrangements of the characters of a string.
// Time complexity: O(n*n!)
void Perm(char str[],int k){
    static int A[10]={0};
    static char res[10];
    if(str[k]=='\0'){
        res[k]='\0';
        cout<<res<<endl;
    }
    else{
        for(int i=0;str[i]!='\0';i++){
            if(A[i]==0){
                res[k]=str[i];
                A[i]=1;
                Perm(str,k+1);
                A[i]=0;
            }
        }
    }
}

// Permutations using swaping (no need of separate array)(Time complexity: O(n!)):
void swap(char *x,char *y){
    char temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
void Perm2(char str[],int l,int h){
    int i;
    if(l==h){
        cout<<str<<endl;
    }
    else{
        for(i=l;i<=h;i++){
            swap(&str[l],&str[i]);
            Perm2(str,l+1,h);
            swap(&str[l],&str[i]);
        }
    }
}
 
int main(){
    char str[100],str2[100];
    cout<<"\nEnter a string:";
    scanf("%[^\n]s",str);
    cout<<"\nEnter another string:";
    scanf(" %[^\n]s",str2);

    anagram(str,str2);
    Perm(str,0);
    return 0;
}