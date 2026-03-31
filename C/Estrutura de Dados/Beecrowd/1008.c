#include <stdio.h>
 
int main() {
    int numero, qtt_trab;
    float receb_trab, salario;
    scanf("%d", &numero);
    scanf("%d", &qtt_trab);
    scanf("%f", &receb_trab);
    
    salario = qtt_trab * receb_trab;
    
    printf("NUMBER = %d\n", numero);
    printf("SALARY = U$ %.2f\n", salario);
    return 0;
}
