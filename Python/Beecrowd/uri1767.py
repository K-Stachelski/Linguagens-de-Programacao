# Beecrowd - Problema 1767 - Objetivo: Pegar o maximo de brinquedos possiveis com limite de peso, que no caso é 50.
# Criacao de uma tabela usada na programacao dinamica. Baseado na quantidade de pacotes e no limite do peso.
def cria_tabela_zerada(pac, limite):
    vet = []
    for i in range(len(pac)+1):
        linha = []
        for j in range(limite+1):
            linha.append(0)
        vet.append(linha)
    return vet

def preenche_tabela(pac, peso, limite): 
    tabela = cria_tabela_zerada(pac, limite)
    
    # Acesso das listas Pac e Peso, i-1 por conta do i iniciar em 1.
    for i in range(1, len(pac)+1): 
        for j in range(limite+1): 
            if peso[i-1] > j: 
                tabela[i][j] = tabela[i-1][j] # Ignora pacote. Motivo: ultrapassa peso limite.
            else: 
                tabela[i][j] = max(tabela[i-1][j], pac[i-1] + tabela[i-1][j - peso[i-1]]) # Pega o maximo de pacotes baseado no quanto sobra para que outros pacotes sejam pegos.
    return tabela

def info(tabela, pac, peso, limite):
    i = len(pac)
    lim = limite
    pacotes_escolhidos = []
    peso_total = 0

    # Saber quais pacotes foram escolhidos e fazer a soma de seus respectivos pesos.
    while i > 0 and lim >= 0:
        if tabela[i][lim] != tabela[i-1][lim]:
            pacotes_escolhidos.append(i-1)
            peso_total += peso[i-1]
            lim -= peso[i-1]
        i -= 1

    # Quantidade de brinquedos.
    qb = tabela[len(pac)][limite]
    # Fazer a conta de quantos pacotes sobraram.
    sobra = len(pac) - len(pacotes_escolhidos)

    return peso_total, sobra, qb

# Quantas viagens vai fazer, quantos pacotes tem e seus pesos.
n_viagens = int(input())
for i in range(n_viagens):
    qtt_pac = int(input())
    lista_pac = []
    lista_peso = []
    for j in range(qtt_pac):
        pac, peso = list(map(int, input().split()))
        lista_pac.append(pac)
        lista_peso.append(peso)

    limite = 50
    saco = preenche_tabela(lista_pac, lista_peso, limite)
    peso_usado, pac_sobra, qtt_brinq = info(saco, lista_pac, lista_peso, limite)

    print(f"{qtt_brinq} brinquedos")
    print(f"Peso: {peso_usado} kg")
    print(f"sobra(m) {pac_sobra} pacote(s)\n")