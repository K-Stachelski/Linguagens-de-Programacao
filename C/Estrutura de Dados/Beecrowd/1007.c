#include <stdio.h>
 
int main() {
    int n1, n2, n3, n4, dif;
    scanf("%d", &n1);
    scanf("%d", &n2);
    scanf("%d", &n3);
    scanf("%d", &n4);
    
    dif = n1 * n2 - n3 * n4;
    printf("DIFERENCA = %d\n", dif);
    return 0;
}
