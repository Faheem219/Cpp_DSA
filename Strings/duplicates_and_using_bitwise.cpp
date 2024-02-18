#include <iostream>
using namespace std;

// Finding duplicates in a string (Time complexity: O(n^2)):
void duplicates(char str[]){
    for(int i=0;str[i]!='\0';i++){
        int count=1;
        if(str[i]!='*'){
            for(int j=i+1;str[j]!='\0';j++){
                if(str[i]==str[j]){
                    count++;
                    str[j]='*';
                }
            }
            if(count>1){
                cout<<"\nCharacter:"<<str[i]<<"\tCount:"<<count<<endl;
            }
        }
    }
}

// Finding duplicates (using hashing) (Time complexity: O(n)) (Lower case only):
void duplicatesHashing(char str[]){
    int H[26]={0};
    for(int i=0;str[i]!='\0';i++){
        H[str[i]-97]++;
    }
    for(int i=0;i<26;i++){
        if(H[i]>1){
            cout<<"\nCharacter:"<<char(i+97)<<"\tCount:"<<H[i]<<endl;
        }
    }
}

// Finding duplicates (using bitwise operations) (Time complexity: O(n)) (Lower case only):
void duplicatesBitwise(char str[]){
    int H=0,x=0; // H is the hash variable and x is the variable for shifting.
    // 1 in x is shifted to the left by the difference between the character and 'a'.
    // Since int is 4 bytes, 32 bits are available. So, we can use 26 bits to store the characters.
    for(int i=0;str[i]!='\0';i++){
        x=1;
        x=x<<(str[i]-97);
        if((x&H)>0){
            cout<<"\nCharacter:"<<str[i]<<" is duplicated."<<endl;
        }
        else{
            H=x|H;
        }
    }
}

int main(){
    char str[100],str2[100];
    cout<<"\nEnter a string:";
    scanf("%[^\n]s",str);
    // duplicates(str);
    duplicatesHashing(str);
    duplicatesBitwise(str);
    return 0;
}