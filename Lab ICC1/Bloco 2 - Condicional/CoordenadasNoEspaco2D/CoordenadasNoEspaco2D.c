#include <stdio.h>

int main(){

    char inputs[6];
    int x = 0, y = 0;

    for(int i = 0; i < 6; i++){
        scanf(" %c", &inputs[i]);
        switch(inputs[i]){
            case 'W':
                y++;
                break;
            case 'S':
                y--;
                break;
            case 'A':
                x--;
                break;
            case 'D':
                x++;
                break;
        }
    }

    printf("%d %d\n", x, y);

    return 0;
}