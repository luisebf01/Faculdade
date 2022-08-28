# Sabendo que str( ) converte valores numéricos para string, calcule quantos dígitos há em 
# 2 elevado a um milhão.

x = 2 ** 1000000
y = len(str(x))
print (f"\nO número 2 ^ 1.000.000 contém {y} dígitos.\n")