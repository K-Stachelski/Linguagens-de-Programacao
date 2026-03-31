# Sequencia Crescente - 1116

while 1:
    entrada = int(input())
    for i in range(entrada):
        
        if i+1 == entrada:
            print(i+1)
        else:
            print(i+1, end=' ')
        
    if entrada == 0:
        break
