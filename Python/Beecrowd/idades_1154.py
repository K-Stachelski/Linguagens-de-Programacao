# Idades - 1154
# Objetivo: Saber a media das idades.

qtt_colocadas = 0
soma = 0
while 1:
    idade = int(input())
    if idade < 0:
        break
    qtt_colocadas += 1
    soma = soma + idade

print(f"{(soma/qtt_colocadas):.2f}")
