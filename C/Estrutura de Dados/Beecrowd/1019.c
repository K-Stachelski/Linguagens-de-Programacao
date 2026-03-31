#include <stdio.h>
 
int main() {
    int duracao, hr, min, seg;
    scanf("%d", &duracao);
    
    hr = duracao/3600;
    min = (duracao - (3600 * hr))/60;
    seg = (duracao - (3600 * hr) - (min * 60));
    
    printf("%d:%d:%d\n", hr, min, seg);
    
    return 0;
}
