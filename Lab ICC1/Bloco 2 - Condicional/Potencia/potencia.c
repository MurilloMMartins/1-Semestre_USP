#include <stdio.h>

int main(){
    int a, b, resultado = 1;

    scanf("%d %d", &a, &b);

    for(int i = 0; i < b; i++){
        resultado = resultado * a;
    }

    printf("%d", resultado);

    return 0;
}