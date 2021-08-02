#include <stdio.h>
#include <ctype.h>

int main(){
    scanf("%*[^\r\n]s");

    int rotor1[26], rotor2[26], rotor3[26];
    for(int i = 0; i < 26; i++){
        scanf(" %d", &rotor1[i]);
    }
    for(int i = 0; i < 26; i++){
        scanf(" %d", &rotor2[i]);
    }
    for(int i = 0; i < 26; i++){
        scanf(" %d", &rotor3[i]);
    }

    scanf("%*[\r\n]s");
    scanf("%*[^\r\n]s");
    scanf("%*[\r\n]s");
    
    char mensagem, saida;
    int cont1 = 0, cont2 = 0;
    int numRotor = 0;
    while(scanf("%c", &mensagem) != EOF){
        if((mensagem >= 'a' && mensagem <= 'z') || (mensagem >= 'A' && mensagem <= 'Z')){
            if(isupper(mensagem)){
                numRotor = ((int)mensagem - 65);
                saida = (char)((rotor3[rotor2[rotor1[numRotor]]]) + 65);
                printf("%c", saida);
            }
            else{
                numRotor = ((int)mensagem - 97);
                saida = (char)((rotor3[rotor2[rotor1[numRotor]]]) + 97);
                printf("%c", saida);
            }

            cont1++;
            int rot1 = rotor1[0];
            for(int i = 0; i < 26; i++){
                rotor1[i] = rotor1[(i+1)%26];
            }
            rotor1[25] = rot1;

            if(cont1 == 26){
                cont2++;
                int rot2 = rotor2[0];
                for(int i = 0; i < 26; i++){
                    rotor2[i] = rotor2[(i+1)%26];
                }
                rotor2[25] = rot2;
                cont1 = 0;
            }

            if(cont2 == 26){
                int rot3 = rotor3[0];
                for(int i = 0; i < 26; i++){
                    rotor3[i] = rotor3[(i+1)%26];
                }
                rotor3[25] = rot3;
                cont2 = 0;
            }
            
        }
        else{
            printf("%c", mensagem);
        }
    }

    return 0;
}