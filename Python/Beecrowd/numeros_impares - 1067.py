# Impares - 1067
# Saber quantos numeros impares existe dentro de um intervalo.

n = int(input())
p = 0
for i in range(12):
    if n % 2 != 0:
        print(n)
    n += 1