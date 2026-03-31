# PUM - 1142
# Imprimir 3x uma sequencia e imprimir PUM e continuar a sequencia da onde parou anteriormente.

qtt = int(input()) # Quantidade de vezes que a linha vai ser imprimida.
linhas = 0
i = 0
cont = 0
while 1:
    i+= 1
    print(i, end=" ") # Imprimir os numeros.
    cont += 1
    if cont == 3:
        print("PUM\n", end="") # Imprimir 'PUM' dps que se repetir 3x.
        i += 1
        cont = 0
        linhas += 1

    if linhas == qtt:
        break
