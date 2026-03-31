#include <stdio.h>
#include <math.h>
 
int main() {
    // Formula de Bhaskara
    float a, b, c, delta, r1, r2, raiz;
    scanf("%f %f %f", &a, &b, &c);

    // Primeiro Passo - Calculo do Delta
    delta = (b * b) - (4 * a * c);
    // Segundo Passo - Calcular a formula de bhaskara
    raiz = sqrt(delta);

    if((a == 0) || (delta < 0)){
        printf("Impossivel calcular\n");
    }else{
        r1 = ((-1) * b + raiz)/(2 * a);
        r2 = ((-1) * b - raiz)/(2 * a);
        printf("R1 = %.5f\n", r1);
        printf("R2 = %.5f\n", r2);
    }
    return 0;
}