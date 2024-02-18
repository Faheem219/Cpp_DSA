#include <iostream>
using namespace std;

// For finding lenth of a string:
void length(char str[]){
    int i=0;
    while(str[i]!='\0'){
        i++;
    }
    cout<<"\nLength of the string is:"<<i<<endl;
}

// For changing the case of a string:
void changeCase(char str[]){
    for(int i=0;str[i]!='\0';i++){
        if(str[i]>=65 && str[i]<=90){
            str[i]+=32;
        }
        else if(str[i]>=97 && str[i]<=122){
            str[i]-=32;
        }
    }
    cout<<"\n"<<str<<endl;
}

// For counting vowels and consonants in a string:
void countVC(char str[]){
    int vcount=0,ccount=0;
    for(int i=0;str[i]!='\0';i++){
        if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u' || str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U'){
            vcount++;
        }
        else if((str[i]>=65 && str[i]<=90) || (str[i]>=97 && str[i]<=122)){
            ccount++;
        }
    }
    cout<<"\nVowels:"<<vcount<<"\nConsonants:"<<ccount<<endl;
}

// Counting number of words (Checking for white spaces (multiple spaces) as well):
void countWords(char str[]){
    int count=0;
    for(int i=0;str[i]!='\0';i++){
        if(str[i]==' ' && str[i-1]!=' '){
            count++;
        }
    }
    cout<<"\nNumber of words:"<<count+1<<endl;
}

// Checking for valid string (No special characters):
void validString(char str[]){
    for(int i=0;str[i]!='\0';i++){
        if(!(str[i]>=65 && str[i]<=90) && !(str[i]>=97 && str[i]<=122) && !(str[i]>=48 && str[i]<=57)){
            cout<<"\nInvalid String"<<endl;
            return;
        }
    }
    cout<<"\nValid String"<<endl;
}

// Reversing a string (Using another string):
void reverseString(char str[]){
    char rev[10];
    int i=0,j=0;
    while(str[i]!='\0'){
        i++;
    }
    i--;
    while(i>=0){
        rev[j]=str[i];
        i--;
        j++;
    }
    rev[j]='\0';
    cout<<"\n"<<rev<<endl;
}

// Reversing a string (In the same string):
void reverseString1(char str[]){
    int i=0,j=0;
    while(str[j]!='\0'){
        j++;
    }
    j--;
    while(i<j){
        char temp=str[i];
        str[i]=str[j];
        str[j]=temp;
        i++;
        j--;
    }
    cout<<"\n"<<str<<endl;
}

int main(){
    char name[10]={'j','o','h','n','\0'};
    char name1[]={'j','o','h','n','\0'};
    char name2[]="john";
    char a[10];
    cout<<name<<endl; // In C, printf("%s",name);

    // For reading single word:
    // cin>>a; // In C, scanf("%s",a);

    // For reading multiple words:
    char str[10];
    cin.getline(str,10); // In C, gets(str);

    length(str);
    changeCase(str);
    countVC(str);
    countWords(str);
    validString(str);
    reverseString(str);
    reverseString1(str);
    return 0;
}