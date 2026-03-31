# Medias Ponderadas - 1079

qtt_teste = int(input())
lista = []
for i in range(qtt_teste):
    peso2, peso3, peso5 = map(float, input().split())
    media = (peso2*0.2) + (peso3*0.3) + (peso5*0.5)
    lista.append(round(media, 2))

for i in range(len(lista)):
    print(f"{lista[i]:.1f}")