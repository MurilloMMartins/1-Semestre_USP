#include <stdio.h>

int Maior(int numeros[]){
    int maior = numeros[0];

    for(int i = 0; i < 10; i++){
        if(numeros[i] > maior){
            maior = numeros[i];
        }
    }

    return maior;
}

int Menor(int numeros[]){
    int menor = numeros[0];

    for(int i = 0; i < 10; i++){
        if(numeros[i] < menor){
            menor = numeros[i];
        }
    }

    return menor;
}

double Media(int numeros[]){
    double media = 0;

    for(int i = 0; i < 10; i++){
        media += numeros[i];
    }

    media = media/10;
    return media;
}

int Moda(int numeros[]){
    int moda = 0;
    int numero;
    int contador = 0, anterior = 0;

    for(int i = 0; i < 10; i++){
        numero = numeros[i];
        for(int j = 0; j < 10; j++){
            if(numero == numeros[j]){
                contador++;
            }
        }
        if(contador > anterior){
            moda = numeros[i];
        }
        anterior = contador;
        contador = 0;
    }

    return moda;
}

int main(){

    int numeros[10];
    for(int i = 0; i < 10; i++){
        scanf(" %d", &numeros[i]);
    }

    int maior, menor, moda;
    double media;

    maior = Maior(numeros);
    menor = Menor(numeros);
    media = Media(numeros);
    moda = Moda(numeros);

    printf("%d %d %.1lf %d", maior, menor, media, moda);

    return 0;
}