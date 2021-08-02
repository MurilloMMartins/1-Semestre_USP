#include <stdio.h>

int main(){
    int n, m, p;
    scanf("%d %d %d", &n, &m, &p);

    int rodadas = 1;

    if(m != p){
    for(int contador = 1; contador < n; contador++){
        for(int i = 1; i <= contador; i++){
            if(rodadas > n){
                break;
            }
            else{
                if(contador == 1){
                    if(rodadas % m == p)
                        printf("1 pinguim\n");
                    rodadas++;
                }
                else{
                    if(rodadas % m == p)
                        printf("%d pinguins\n", contador);
                    rodadas++;
                }
            }
            
        }
        for(int i = 1; i <= contador; i++){
            if(rodadas > n){
                break;
            }
            else{
                if(rodadas % m == p)
                    printf("no gelo\n");
                rodadas++;
            }
        }
        for(int i = 1; i <= contador; i++){
            if(rodadas > n){
                break;
            }
            else{
                if(rodadas % m == p)
                    printf("uhuu!\n");
                rodadas++;
            }
        }
    }
    }
    else{
    for(int contador = 1; contador < n; contador++){
        for(int i = 1; i <= contador; i++){
            if(rodadas > n){
                break;
            }
            else{
                if(contador == 1){
                    if(rodadas % m == 0)
                        printf("1 pinguim\n");
                    rodadas++;
                }
                else{
                    if(rodadas % m == 0)
                        printf("%d pinguins\n", contador);
                    rodadas++;
                }
            }
            
        }
        for(int i = 1; i <= contador; i++){
            if(rodadas > n){
                break;
            }
            else{
                if(rodadas % m == 0)
                    printf("no gelo\n");
                rodadas++;
            }
        }
        for(int i = 1; i <= contador; i++){
            if(rodadas > n){
                break;
            }
            else{
                if(rodadas % m == 0)
                    printf("uhuu!\n");
                rodadas++;
            }
        }
    }
    }

    return 0;
}