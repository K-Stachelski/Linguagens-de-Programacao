#include <stdio.h>
 
int main() {
    double a, b, c;
    double triang, circ, trap, quad, retang;
    scanf("%lf%lf%lf", &a, &b, &c);
    
    triang = a*c/2;
    circ = 3.14159 * (c*c);
    trap = (a + b) * c/2;
    quad = b * b;
    retang = a * b;
    
    printf("TRIANGULO: %.3lf\n", triang);
    printf("CIRCULO: %.3lf\n", circ);
    printf("TRAPEZIO: %.3lf\n", trap);
    printf("QUADRADO: %.3lf\n", quad);
    printf("RETANGULO: %.3lf\n", retang);
    
    return 0;
}
