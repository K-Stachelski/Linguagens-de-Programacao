#include <stdio.h>
 
int main() {
    int n;
    int nota_100, nota_50, nota_20, nota_10, nota_05, nota_02, troco;
    int moeda_1, moeda_50, moeda_25, moeda_10, moeda_05, moeda_01;
    scanf("%d", &n);
    
    troco = n;
    nota_100 = troco/100;
    troco = troco - (nota_100 * 100);
    
    nota_50 = troco/50;
    troco = troco - (nota_50 * 50);
    
    nota_20 = troco/20;
    troco = troco - (nota_20 * 20);
    
    nota_10 = troco/10;
    troco = troco - (nota_10 * 10);
    
    nota_05 = troco/5;
    troco = troco - (nota_05 * 5);
    
    nota_02 = troco/2;
    troco = troco - (nota_02 * 2);
    
    moeda_1 = troco/1;
    troco = troco - (moeda_1 * 1);
    
    moeda_50 = troco % 50;
    troco = troco - (moeda_50 * 0.50);
    
    moeda_25 = troco % 25;    
    troco = troco - (moeda_25 * 0.25);
    
    moeda_10 = troco % 10;
    troco = troco - (moeda_10 * 0.10);
    
    moeda_05 = troco % 5;
    troco = troco - (moeda_05 * 0.05);
    
    moeda_01 = troco % 1;
    troco = troco - (moeda_01 * 0.01);
    
    printf("NOTAS: \n");
    printf("%d nota(s) de R$ 100,00\n", nota_100);
    printf("%d nota(s) de R$ 50,00\n", nota_50);
    printf("%d nota(s) de R$ 20,00\n", nota_20);
    printf("%d nota(s) de R$ 10,00\n", nota_10);
    printf("%d nota(s) de R$ 5,00\n", nota_05);
    printf("%d nota(s) de R$ 2,00\n", nota_02);
    
    printf("MOEDAS: \n");
    printf("%d moeda(s) de R$ 1,00\n", moeda_1);
    printf("%d moeda(s) de R$ 0.50\n", moeda_50);
    printf("%d moeda(s) de R$ 0.25\n", moeda_25);
    printf("%d moeda(s) de R$ 0.10\n", moeda_10);
    printf("%d moeda(s) de R$ 0.05\n", moeda_05);
    printf("%d moeda(s) de R$ 0.01\n", moeda_01);
    return 0;
}
