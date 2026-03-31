# Fibonacci Fácil - 1151
# Soma dos dois numeros anteriores é o proximo numero.

lista = [0,1]
aux = 0
for i in range(2, 46):
    aux = lista[i-1] + lista[i-2]
    lista.append(aux)

numero = int(input())

for i in range(numero):
    if i+1 == numero:
        print(lista[i])
    else:    
        print(lista[i], end=" ")
