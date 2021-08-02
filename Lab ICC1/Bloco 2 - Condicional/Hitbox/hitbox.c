#include <stdio.h>

int main(){
    double x1, y1, lar1, alt1, x2, y2, lar2, alt2;
    scanf("%lf %lf %lf %lf", &x1, &y1, &lar1, &alt1);
    scanf("%lf %lf %lf %lf", &x2, &y2, &lar2, &alt2);
    
    double x, y, lar, alt;
    if(x1 > x2){
        x = x1;
        if(lar2 != 0 && lar1 != 0){
            if(lar1 > (x2+lar2) - x1){
               lar = (x2+lar2) - x1; 
            }
            else{
                lar = lar1;
            }
            
        }
        else{
            lar = 0;
        }
    }
    else if(x1 < x2){
        x = x2;
        if(lar2 != 0 && lar1 != 0){
            if(lar2 > (x1+lar1) - x2){
               lar = (x1+lar1) - x2; 
            }
            else{
                lar = lar2;
            }
            
        }
        else{
            lar = 0;
        }
    }
    else if(x1 == x2){
        x = x1;
        lar = 0;
    }

    if(y1 > y2){
        y = y1;
        if(alt2 != 0 && alt1 != 0){
            if(alt1 > (y2+alt2) - y1){
               alt = (y2+alt2) - y1;
            }
            else{
                alt = alt1;
            }
            
        }
        else{
            alt = 0;
        }
        
    }
    else if(y1 < y2){
        y = y2;
        if(alt2 != 0 && alt1 != 0){
            if(alt2 > (y1+alt1) - y2){
                alt = (y1+alt1) - y2;
            }
            else{
                alt = alt2;
            }
            
        }
        else{
            alt = 0;
        }
    }
    else{
        y = y1;
        alt = 0;
    }

    if(lar < 0 || alt < 0){
        printf("MISS");
    }
    else{
        printf("HIT: %.0lf %.0lf %.0lf %.0lf", x, y, lar, alt);
    }
    

    return 0;
}