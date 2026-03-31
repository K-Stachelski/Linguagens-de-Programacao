#include <stdio.h>
 
int main() {
    int n;
    int nota_100, nota_50, nota_20, nota_10, nota_05, nota_02, nota_01, troco;
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
    
    nota_01 = troco/1;
    troco = troco - (nota_01 * 1);
    
    printf("%d\n", n);
    printf("%d nota(s) de R$ 100,00\n", nota_100);
    printf("%d nota(s) de R$ 50,00\n", nota_50);
    printf("%d nota(s) de R$ 20,00\n", nota_20);
    printf("%d nota(s) de R$ 10,00\n", nota_10);
    printf("%d nota(s) de R$ 5,00\n", nota_05);
    printf("%d nota(s) de R$ 2,00\n", nota_02);
    printf("%d nota(s) de R$ 1,00\n", nota_01);
    
    return 0;
}
