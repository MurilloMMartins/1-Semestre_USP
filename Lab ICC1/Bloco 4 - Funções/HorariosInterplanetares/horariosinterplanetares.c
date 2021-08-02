#include <stdio.h>
#include <string.h>

void horarioTerra(unsigned long long int tempo, unsigned long long int *dias, unsigned long long int *horas, unsigned long long int *minutos, unsigned long long int *segundos){
    *dias = tempo/86400;
    tempo -= (*dias * 86400);
    *horas = tempo/3600;
    tempo -= (*horas * 3600);
    *minutos = tempo/60;
    tempo -= (*minutos * 60);
    *segundos = tempo;
}

void horarioVenus(unsigned long long int tempo, unsigned long long int *dias, unsigned long long int *horas, unsigned long long int *minutos, unsigned long long int *segundos){
    *dias = tempo/(86400*243);
    tempo -= (*dias * (86400*243));
    *horas = tempo/3600;
    tempo -= (*horas * 3600);
    *minutos = tempo/60;
    tempo -= (*minutos * 60);
    *segundos = tempo;
}

void horarioMercurio(unsigned long long int tempo, unsigned long long int *dias, unsigned long long int *horas, unsigned long long int *minutos, unsigned long long int *segundos){
    *dias = tempo/((86400*58)+(16*3600));
    tempo -= (*dias * ((86400*58)+(16*3600)));
    *horas = tempo/3600;
    tempo -= (*horas * 3600);
    *minutos = tempo/60;
    tempo -= (*minutos * 60);
    *segundos = tempo;
}

void horarioJupiter(unsigned long long int tempo, unsigned long long int *dias, unsigned long long int *horas, unsigned long long int *minutos, unsigned long long int *segundos){
    *dias = tempo/35760;
    tempo -= (*dias * 35760);
    *horas = tempo/3600;
    tempo -= (*horas * 3600);
    *minutos = tempo/60;
    tempo -= (*minutos * 60);
    *segundos = tempo;
}

int main(){
    char planeta[10] = "";
    unsigned long long int segundosPlaneta, dias, horas, minutos, segundos;

    scanf("%llu%*c", &segundosPlaneta);

    int contChar = 0;
    char caracter;
    do{
        caracter = getchar();
        planeta[contChar] = caracter;
        contChar++;
    }while(caracter != '\n' && caracter != EOF);
    planeta[contChar-1] = '\0';

    if(strcmp(planeta, "Terra") == 0){
        horarioTerra(segundosPlaneta, &dias, &horas, &minutos, &segundos);
    }
    else if(strcmp(planeta, "Venus") == 0){
        horarioVenus(segundosPlaneta, &dias, &horas, &minutos, &segundos);
    }
    else if(strcmp(planeta, "Mercurio") == 0){
        horarioMercurio(segundosPlaneta, &dias, &horas, &minutos, &segundos);
    }
    else if(strcmp(planeta, "Jupiter") == 0){
        horarioJupiter(segundosPlaneta, &dias, &horas, &minutos, &segundos);
    }

    printf("%llu segundos no planeta %s equivalem a:\n", segundosPlaneta, planeta);
    printf("%llu dias, %llu horas, %llu minutos e %llu segundos\n", dias, horas, minutos, segundos);
    

    return 0;
}