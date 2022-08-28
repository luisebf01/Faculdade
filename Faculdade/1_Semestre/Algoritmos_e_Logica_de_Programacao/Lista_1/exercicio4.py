# Faça um programa que calcule o aumento de um salário. Ele deve solicitar o valor do salário e a 
# porcentagem do aumento. Exiba o valor do aumento e do novo salário.

salario = float(input("\nInsira o salário: "))
porcentagem = float(input("Insira a porcentagem de aumento: ")) / 100
aumento = salario * porcentagem
novoSalario = salario + aumento
print(f"\nO aumento será de R$ {aumento:.2f} e o novo salário será de R$ {novoSalario:.2f}.\n")