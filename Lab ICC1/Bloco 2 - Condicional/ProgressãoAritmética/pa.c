#include <stdio.h>

int main(){
    double a1 = 0, r = 0, n = 0, an = 0, soma = 0;
    scanf("%lf %lf %lf", &a1, &r, &n);

    an = a1+((n-1)*r);
    soma = ((a1 + an)*n)/2;

    printf("%.0lf\n%.0lf\n", an, soma);

    return 0;
}