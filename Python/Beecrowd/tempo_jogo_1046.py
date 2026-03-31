# Tempo de Jogo - 1046
# Objetivo: Saber quanto tempo durou um jogo.

h_inicio, h_final = map(int, input().split()) # Hora de inicio e o horario que acabou o jogo.

if h_inicio > h_final:
    print(f"O JOGO DUROU {(24 - h_inicio) + h_final} HORA(S)")

elif h_final > h_inicio:
    print(f"O JOGO DUROU {h_final - h_inicio} HORA(S)")

elif h_inicio == h_final:
    print(f"O JOGO DUROU 24 HORA(S)")
