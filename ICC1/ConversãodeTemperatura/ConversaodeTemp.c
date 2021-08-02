#include <stdio.h>

int main()
{
    float tempC;
    float tempF;

    scanf("%f", &tempF);
    tempC = (tempF-32.0)/1.8;
    printf("%.2f\n", tempC);

    return 0;
}