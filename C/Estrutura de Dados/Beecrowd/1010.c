#include <stdio.h>
 
int main() {
    int cod1, nr_pec1, cod2, nr_pec2;
    double valor1, valor2, total;
    scanf("%d%d%lf", &cod1, &nr_pec1, &valor1);
    scanf("%d%d%lf", &cod2, &nr_pec2, &valor2);
    
    total = nr_pec1 * valor1 + nr_pec2 * valor2;
    
    printf("VALOR A PAGAR: R$ %.2lf\n", total);
    
    return 0;
}
