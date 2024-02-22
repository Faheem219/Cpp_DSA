// calculator using switch case
#include <stdio.h>
int main(){

    int a;
    printf("enter first number:");
    scanf("%d", &a);
    int b;
    printf("enter the second number:");
    scanf("%d", &b);
    char ch;
    printf("enter the opreator:");
    scanf(" %c",&ch);
    switch(ch){
    case '+':
        printf("%d", a + b);
        break;
    case '-':
        printf("%d", a - b);
        break;
    case '*':
        printf("%d", a * b);
        break;
    case '/':
        printf("%d", a / b);
        break;
    default:
    }
}