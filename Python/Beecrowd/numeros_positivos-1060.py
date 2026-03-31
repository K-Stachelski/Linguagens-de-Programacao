# Numeros Positivos - 1060
# Saber quantidade de numeros positivos colocado pelo o usuario, desconsiderar valores nulos.
plim = 0
for i in range(6):
    numeros = float(input())
    if numeros > 0:
        plim += 1

print(f"{plim} valores positivos")
