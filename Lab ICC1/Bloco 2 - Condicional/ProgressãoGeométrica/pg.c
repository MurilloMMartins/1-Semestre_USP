#include <stdio.h>

int main(){
    float a1, q, n, an = 0, soma = 0, qn = 1;
    scanf("%f %f %f", &a1, &q, &n);

    for(int i = 1; i < n; i++){
        qn = qn*q;
    }
    an = a1*qn;
    soma = (a1*((qn*q) - 1))/(q-1);
    printf("%.2f\n%.2f\n", an, soma);
}