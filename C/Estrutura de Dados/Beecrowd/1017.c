#include <stdio.h>
 
int main() {
    float gasto, velocidade;
    double litros;
    scanf("%f", &gasto);
    scanf("%f", &velocidade);
    
    litros = (gasto * velocidade)/12;
    
    printf("%.3lf\n", litros);
    return 0;
}
