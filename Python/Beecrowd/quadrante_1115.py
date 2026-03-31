# Quadrante - 1115
# Saber em que quadrante se encontra as coordenadas.

while 1:
    x, y = map(int, input().split())
    if x == 0 or y == 0:
        break

    if x < 0 and y > 0:
        print("segundo")
    if x > 0 and y > 0:
        print("primeiro")
    if x < 0 and y < 0:
        print("terceiro")
    if x > 0 and y < 0:
        print("quarto")