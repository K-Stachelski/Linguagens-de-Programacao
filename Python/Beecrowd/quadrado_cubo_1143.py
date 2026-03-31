# Quadrado e ao cubo - 1143

n = int(input())
linhas = 0
a = 1
while linhas != n:
    b = 1
    for i in range(2):
        print(a**b, end=" ")
        b+=1
        if i == 1: # Imprimir sem um espaço a mais.
            print(a**b)
    a += 1
    linhas += 1
