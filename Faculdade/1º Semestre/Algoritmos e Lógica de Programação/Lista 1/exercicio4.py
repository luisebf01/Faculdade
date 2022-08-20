salario = float(input("Insira o salário: "))
porcentagem = float(input("Insira a porcentagem de aumento: ")) / 100
aumento = salario * porcentagem
novoSalario = salario + aumento
print(f"O aumento será de R$ {aumento:.2f} e o novo salário será de R$ {novoSalario:.2f}.")