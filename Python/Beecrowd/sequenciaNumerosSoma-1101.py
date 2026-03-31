# Sequencia de Numeros e Soma - 1101
# Objetivo: Fazer a soma entre o intervalo de dois numeros, incluindo eles mesmos.

while 1:
    m, n = map(int, input().split()) # Maior e Menor.
    lista = []
    aux = 0

    if n > m: # Caso um numero seja maior q o outro.
        aux = m
        m = n
        n = aux

    if (m <= 0) or (n <= 0):
        break
    for i in range(n,m+1): # Gerar os numeros dentro desse intervalo.
        lista.append(i)

    print(" ".join(map(str, lista)), f"Sum={sum(lista)}")
