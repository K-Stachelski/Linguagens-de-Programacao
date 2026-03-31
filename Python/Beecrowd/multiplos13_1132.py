# Multiplos de 13 - 1132
# Objetivo: Fazer a soma dentro de um intervalo de numeros, mas apenas os que NAO sao multiplos de 13.

x = int(input())
y = int(input())
aux = 0
lista = []

if x > y: # Ficar em ordem crescente.
    aux = y
    y = x
    x = aux
for i in range(x,y+1):
    if (i % 13) != 0: # Saber se NAO é multiplo de 13.
        lista.append(i)

print(sum(lista))
