#include <iostream>
using namespace std;

// Comparing two strings (Case sensitive):
void compareStrings(char str[],char str2[]){
    int i,j;
    for(i=0,j=0;str[i]!='\0' && str2[j]!='\0';i++,j++){
        if(str[i]!=str2[j]){
            break;
        }
    }
    if(str[i]==str2[j]){
        cout<<"\nStrings are equal"<<endl;
    }
    else if(str[i]>str2[j]){
        cout<<"\nString 1 is greater"<<endl;
    }
    else{
        cout<<"\nString 2 is greater"<<endl;
    }
}

// Comparing two strings (Case insensitive):
void compareStringsCI(char str[],char str2[]){
    int i,j;
    for(i=0,j=0;str[i]!='\0' && str2[j]!='\0';i++,j++){
        if(str[i]!=str2[j] && str[i]!=str2[j]+32 && str[i]!=str2[j]-32){
            break;
        }
    }
    if(str[i]==str2[j]){
        cout<<"\nStrings are equal"<<endl;
    }
    else if(str[i]>str2[j]){
        cout<<"\nString 1 is greater"<<endl;
    }
    else{
        cout<<"\nString 2 is greater"<<endl;
    }
}

// Checking for palindrome (In the same string):
void palindrome(char str[]){
    int i,j;
    for(i=0;str[i]!='\0';i++){}
    i--;
    for(j=0;j<i;j++,i--){
        if(str[i]!=str[j]){
            cout<<"\nNot a palindrome"<<endl;
            return;
        }
    }
    cout<<"\nPalindrome"<<endl;
}

int main(){
    char str[10],str2[10];
    cout<<"\nEnter a string:";
    cin.getline(str,10);
    cout<<"\nEnter another string:";
    cin.getline(str2,10);

    compareStrings(str,str2);
    compareStringsCI(str,str2);
    palindrome(str);
    return 0;
}