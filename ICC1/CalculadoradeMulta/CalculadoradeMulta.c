#include <stdio.h>

int main()
{
    float limite = 80.0;
    float velocidade;
    float multa;

    scanf("%f", &velocidade);

    if (velocidade > 80.0)
    {
        multa = 2.0*(velocidade - limite);
        printf("Limite de velocidade excedido! Multado no valor de R$%.2f!\n", multa);
    }
    else
    {
        printf("Velocidade dentro do limite permitido.\n");
    }

}