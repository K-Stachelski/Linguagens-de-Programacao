# Varias notas com Validacao - 1118

novo = 1
while 1:
    if novo == 1:
        i = 0
        media = 0
        while i < 2: # Inserir notas corretamente.
            nota = float(input())
            if nota >= 0 and nota <= 10:
                media = nota + media
                i += 1

            else: # Se houver alguma incorreta imprime e volta para add uma corretamente.
                print("nota invalida")

        media = media / 2
        print(f"media = {media:.2f}")

    print("novo calculo (1-sim 2-nao)")
    novo = int(input())
    if novo == 2:
        break