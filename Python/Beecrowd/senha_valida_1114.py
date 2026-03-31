# Senha Fixa - 1114
# Escrever um algoritmo que informe se a senha esta correta ou nao.

senha = 2002

while 1:
    entrada = int(input())
    if entrada != senha:
        print("Senha Invalida")
    else:
        print("Acesso Permitido")
        break
