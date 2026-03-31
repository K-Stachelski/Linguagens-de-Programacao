#include <stdio.h>
#include <stdlib.h>
 
int main() {
    int n1, n2, n3, maiorAB, maior;
    scanf("%d%d%d", &n1, &n2, &n3);
    
    maiorAB = (n1 + n2 + abs(n1-n2))/2;
    maior = (maiorAB + n3 + abs(maiorAB - n3))/2;
    
    printf("%d eh o maior\n", maior);
    
    return 0;
}
