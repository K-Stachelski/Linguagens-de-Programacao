# Maior e Posicao - 1080
# Achar o maior numero dentro de uma lista de 100 numeros e sua posicao.
lista = []
for i in range(3):
    n = int(input())
    lista.append(n)

mx = max(lista)
print(mx)

for i in range(len(lista)):
    if mx == lista[i]:
        print(i+1) 
