#include <stdio.h>
#include <math.h>

int main(){
    float a = 0, b = 0, c= 0;
    scanf("%f %f", &a, &b);
    c = pow(a, b);
    printf("%.4f", c);
}