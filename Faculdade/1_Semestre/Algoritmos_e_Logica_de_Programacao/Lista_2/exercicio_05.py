# Faça um Programa que leia três números e mostre o maior e o menor deles.

print(f"\nInsira 3 valores abaixo separados por vírgula.")
n1, n2, n3 = eval(input('Número 1, Número 2, Número 3: '))
maior = n1
menor = n1
if n2 < menor:
    menor = n2
if n3 < menor:
    menor = n3
if n2 > maior:
    maior = n2
if n3 > maior:
    maior = n3
print (f"\nO menor dos números é {menor} e o maior dos números é {maior}.\n")