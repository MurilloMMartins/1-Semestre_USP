#include <stdio.h>

int main()
{
    int valorEntrada;

    scanf("%i", &valorEntrada);

    if (valorEntrada % 11 == 0 && valorEntrada % 13 == 0 && valorEntrada % 19 == 0){
        printf("BaDumTssTss\n");
    }
    else if (valorEntrada % 11 == 0 && valorEntrada % 13 == 0){
        printf("BaDumDum\n");
    }
    else if (valorEntrada % 13 == 0 && valorEntrada % 19 == 0)
    {
        printf("DumDumTss\n");
    }
    else if (valorEntrada % 11 == 0 && valorEntrada % 19 == 0){
        printf("BaDumTss");
    }
    else if (valorEntrada % 11 == 0){
        printf("BaBa\n");
    }
    else if (valorEntrada % 13 == 0){
        printf("BaDum\n");
    }
    else if (valorEntrada % 19 == 0){
        printf("BaTss\n");
    }
    else {
        printf("%d\n", valorEntrada);
    }
    
    return 0;
}