# Experiencia Laboratorio
# Objetivo: Saber quantidade de cobais, quais foram os tipos usados e a porcentagem utilizado de cada um.

# Quantidade de teste realizado.
qtt_teste = int(input())

lista_rato = [] # Rato
lista_sapo = [] # Sapo
lista_coelho = [] # Coelho

# Quantidade de cobaias e quais foram.
for i in range(qtt_teste):
    qtt_cobaia, qtt_tipo = map(str,input().split(" "))
    if qtt_tipo == "R" or qtt_tipo == "r":
        lista_rato.append(int(qtt_cobaia))

    if qtt_tipo == "S" or qtt_tipo == "s":
        lista_sapo.append(int(qtt_cobaia))

    if qtt_tipo == "C" or qtt_tipo == "c":
        lista_coelho.append(int(qtt_cobaia))

# Quantidade total de cobaias.
total = sum(lista_coelho) + sum(lista_rato) + sum(lista_sapo)
print(f"Total: {total} cobaias")

# Total de cada tipo de cobaia.
print(f"Total de coelhos: {sum(lista_coelho)}")
print(f"Total de ratos: {sum(lista_rato)}")
print(f"Total de sapos: {sum(lista_sapo)}")

# Percentual.
sapo = (sum(lista_sapo)*100)/total
rato = (sum(lista_rato)*100)/total
coelho = (sum(lista_coelho)*100)/total

print(f"Percentual de coelhos: {coelho:.2f} %")
print(f"Percentual de ratos: {rato:.2f} %")
print(f"Percentual de sapos: {sapo:.2f} %")
