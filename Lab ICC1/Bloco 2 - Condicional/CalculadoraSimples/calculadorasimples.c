#include <stdio.h>

int main(){
    float a, b;
    char op;

    scanf("%f %c %f", &a, &op, &b);
    switch(op){
        case '+':
            printf("%.6f", a+b);
            break;
        case '-':
            printf("%.6f", a-b);
            break;
        case '*':
            printf("%.6f", a*b);
            break;
        case '/':
            printf("%.6f", a/b);
            break;
        case '%':
            printf("%.6f", (a/b)*100);
            break;
    }
}