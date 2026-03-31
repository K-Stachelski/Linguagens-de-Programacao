# Fatorial Simples - 1153
# Saber o fatorial de um determinado numero.

n = int(input())
fatorial = 1

while n >= 1:
    fatorial = fatorial * (n)
    n -= 1
print(fatorial)
