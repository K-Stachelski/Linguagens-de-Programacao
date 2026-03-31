#include <stdio.h>
 
int main() {
    char nome[10];
    double salario, total, novo_salario;
    scanf("%s", &nome);
    scanf("%lf", &salario);
    scanf("%lf", &total);
    
    novo_salario = salario + (total * 15/100);
    
    printf("TOTAL = R$ %.2lf\n", novo_salario);
    
    return 0;
}
