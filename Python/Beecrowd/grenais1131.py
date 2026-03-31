# Grenais - 1131
qtt_grenais = 0
gols_inter = 0
gols_gremio = 0
vencedor_inter = 0
vencedor_gremio = 0
empate = 0
while 1:
    inter, gremio = map(int, input().split()) # Numero de gols correpondente ao inter e o gremio.

    qtt_grenais += 1 # Quantidade de grenais feito.

    gols_inter += inter
    gols_gremio += gremio

    if gols_inter > gols_gremio: # Saber quem ganhou.
        vencedor_inter += 1
    else:
        vencedor_gremio += 1

    print("Novo grenal (1-sim 2-nao)")
    dnv = int(input())
    if dnv == 2:
        break

if vencedor_inter == vencedor_gremio: # Saber se teve empate.
        empate += 1
        
print(f"{qtt_grenais} grenais")     
print(f"Inter:{vencedor_inter}")
print(f"Gremio:{vencedor_gremio}")
print(f"Empates:{empate}")

# Saber quem foi o vencedor no final.
if vencedor_inter > vencedor_gremio:
    print("Inter venceu mais")
else:
    print("Gremio venceu mais")
