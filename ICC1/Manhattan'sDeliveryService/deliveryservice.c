#include <stdio.h>
#include <math.h>

double distEuclides(int x1, int y1, int x2, int y2){
    double distancia = sqrt(pow((x2-x1), 2) + pow((y2-y1), 2));
    return distancia;
}

double distHermann(int x1, int y1, int x2, int y2){
    double distancia = fabs(x2-x1) + fabs(y2-y1);
    return distancia;
}


int main(){
    int xcasa, ycasa, x1, x2, y1, y2, identificador;
    int numeroPontos;
    int terrenoResidencial = 0, terrenoBaldio = 0, terrenoParque = 0;
    double diferenca = 0;

    scanf("%d", &numeroPontos);

    if(numeroPontos > 0){
        scanf(" %d %d", &xcasa, &ycasa);
        x1 = xcasa;
        y1 = ycasa;

        for(int i = 0; i < (numeroPontos - 1); i++){
            scanf(" %d %d %d", &identificador, &x2, &y2);
            switch(identificador){
                case -1:
                    terrenoBaldio++;
                    break;
                case 0:
                    terrenoResidencial++;
                    break;
                case 1:
                    diferenca += distHermann(x1, y1, x2, y2) - distEuclides(x1, y1, x2, y2);
                    terrenoParque++;
                    break;
                default:
                    printf("Falha no processamento dos dados.\n");
                    return 0;
                    break;
            }
            x1 = x2;
            y1 = y2;
        }

        scanf(" %d", &identificador);
        switch(identificador){
            case -1:
                terrenoBaldio++;
                break;
            case 0:
                terrenoResidencial++;
                break;
            case 1:
                diferenca += distHermann(x1, y1, xcasa, ycasa) - distEuclides(x1, y1, xcasa, ycasa);
                terrenoParque++;
                break;
            default:
                printf("Falha no processamento dos dados.\n");
                return 0;
                break;
        }

        printf("Ao todo, foi passado por %d terrenos baldios, %d terrenos residenciais e %d parques.\n", terrenoBaldio, terrenoResidencial, terrenoParque);
        printf("A diferenca total de distancia percorrida foi de %.2lf metros.", diferenca);

    }
    else{
        printf("Falha no processamento dos dados.\n");
    }
    

    return 0;
}