# Sequencia IJ 1 - 1095
def sequenciaIJ1():
    J = 60
    I = 1

    while J >= 0:
        print(f"I={I} J={J}")
        J -= 5
        I += 3

# Sequencia IJ 2 - 1096
def sequenciaIJ2():
    I = 1
    J = 7
    contI = 0
    contJ = 0
    while I <= 9:
        contI += 1 # Saber qual o valor de I.
        print(f"I={I} J={J}")
        if contI == 3: # Reiniciar o cont para que o I imprima apenas 3x o valor.
            I += 2
            contI = 0
        contJ += 1
        J -= 1
        if contJ == 3:
            J = 7
            contJ = 0

# Sequencia IJ 3 - 1097
def sequenciaIJ3():
    I = 1
    J = 7
    contI = 0
    contJ = 0
    while I <= 9:
        contI += 1
        print(f"I={I} J={J}")
        if contI == 3: # Reiniciar o cont para que o I imprima apenas 3x o valor.
                I += 2
                contI = 0

        contJ += 1
        J -= 1
        if contJ == 3:
            J = J + 5
            contJ = 0

sequenciaIJ1()
sequenciaIJ2()
sequenciaIJ3()

