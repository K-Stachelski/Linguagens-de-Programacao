# Somando inteiros consecutivos - 1149
# Objetivo: Fazer a soma de uma sequencia de inteiros positivos.

a, n = map(int, input().split())

while n <= 0:
    n = int(input())
    
soma = 0
for i in range(n):
    soma += (a + i)

print(soma)
