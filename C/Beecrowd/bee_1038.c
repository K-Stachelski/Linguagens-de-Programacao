#include <stdio.h>
 
int main() {
    // Lanche
    int item, qtt; 
    float valor;
    scanf("%d %d", &item, &qtt);
    if(item == 1){
        valor = 4 * qtt;
    }
    if(item == 2){
        valor = 4.5 * qtt;
    }
    if(item == 3){
        valor = 5 * qtt;
    }
    if(item == 4){
        valor = 2 * qtt;
    }
    if(item == 5){
        valor = 1.5 * qtt;
    }
    printf("Total: R$ %.2f\n", valor);
    return 0;
}