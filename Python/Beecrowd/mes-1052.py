# Mes - 1052
# Objetivo: Colocar um numero e saber qual seu mes em ingles.

mes = int(input())
lista_mes = ["January", "February", "March","April", "May", "June","July","August","September","October","November","December"]
for i in range(len(lista_mes)):
    if i+1 == mes:
        print(lista_mes[i])
