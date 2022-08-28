# Faça um Programa que leia três números e mostre o maior deles.

print(f"\nInsira 3 valores abaixo separados por vírgula.")
n1, n2, n3 = eval(input('Número 1, Número 2, Número 3: '))
maior = n1
if n2 > maior:
    maior = n2
if n3 > maior:
    maior = n3
print (f"\nO maior dos números é {maior}.\n")