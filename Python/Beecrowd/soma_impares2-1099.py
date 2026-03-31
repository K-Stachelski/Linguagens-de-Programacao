# Soma de impares consecutivos 2 - 1099
# Objetivo: fazer uma soma entre um intervalo de dois numeros, mas apenas a soma dos impares.

qtt = int(input())

for i in range(qtt):
    soma = 0
    aux = 0

    x, y = map(int, input().split())
    if x > y:
        aux = y
        y = x
        x = aux
        
    for j in range(x+1,y):
        if j % 2 != 0:
            soma += j

    print(soma)
