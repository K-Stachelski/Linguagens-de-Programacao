# Tipo de Combustivel - 1134
# Objetivo: Saber qual dos produtos os clientes tem mais preferencia.
# Esse codigo resolve o problema, porem tem que retirar "Tipos", pois foi algo que eu coloquei.
print("="*50)
print("TIPOS")
print("1- Alcool")
print("2- Gasolina")
print("3- Diesel")
print("4- Fim")
print("="*50)

qtt_alcool = 0
qtt_diesel = 0
qtt_gasolina = 0

while 1:
    escolha = int(input("Qual tipo deseja? "))

    # Caso esteja fora dos intervalos.
    if escolha < 1 or escolha > 4:
        print("Valor invalido. Por favor inserir um valido.")
        dnv = int(input("Inserir novamente: "))
        escolha = dnv

    if escolha == 1:
        qtt_alcool += 1

    if escolha == 2:
        qtt_gasolina += 1
    
    if escolha == 3:
        qtt_diesel += 1
    
    if escolha == 4:
        print()
        print("MUITO OBRIGADO")
        break
print("="*50)
print(f"Alcool: {qtt_alcool}")
print("-"*50)
print(f"Gasolina: {qtt_gasolina}")
print("-"*50)
print(f"Diesel: {qtt_diesel}")
print("="*50)
