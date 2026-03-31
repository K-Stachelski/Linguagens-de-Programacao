# Imposto de Renda - 1051
# Objetivo: Saber quanto uma pessoa vai ter que pagar de imposto baseado na sua renda.

salario = float(input())
if salario < 2000.00: # Isento
    print("Isento")

elif salario > 2000.01 and salario < 3000.00: 
    per_imposto_renda = (salario - 2000)*0.08
    print(f"R$ {per_imposto_renda:.2f}")
    
elif salario > 3000.01 and salario < 4500.00: 
    per = ((1000*0.08) + ((salario - 3000)*0.18))
    print(f"R$ {per:.2f}")

else:
    per = (1000 * 0.08 + 1500 * 0.18 + (salario - 4500) * 0.28)
    print(f"R$ {per:.2f}")
