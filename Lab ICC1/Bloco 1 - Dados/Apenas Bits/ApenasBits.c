#include <stdio.h>

int main(){
    int entrada;
    scanf("%d", &entrada);
    printf("%c", (entrada >> 24) & 255);
    printf("%c", (entrada >> 16) & 255);
    printf("%c", (entrada >> 8) & 255);
    printf("%c", entrada & 255);

    return 0;
}