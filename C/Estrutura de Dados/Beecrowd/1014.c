#include <stdio.h>
 
int main() {
    int distancia;
    double total, consumo;
    scanf("%d", &distancia);
    scanf("%lf", &total);
    
    consumo = distancia/total;
    
    printf("%.3lf km/l\n", consumo);
    return 0;
}
