''' 
Faça um Programa que pergunte quanto você ganha por hora e o número de horas trabalhadas no mês. 
Calcule e mostre o total do seu salário no referido mês, sabendo-se que são descontados 11% para 
o Imposto de Renda, 8% para o INSS e 5% para o sindicato, faça um programa que nos dê o salário bruto,
quanto pagou ao INSS, quanto pagou ao sindicato e o salário líquido. Observe que 
Salário Bruto - Descontos = Salário Líquido. Calcule os descontos e o salário líquido, conforme a 
tabela abaixo:

   a. + Salário Bruto : R$
   b. - IR (11%) : R$
   c. - INSS (8%) : R$
   d. - Sindicato ( 5%) : R$
   e. = Salário Liquido : R$
'''

imposto = 0.11
inss = 0.08
sindicato = 0.05
salarioHora = float(input("\nInsira quanto você ganha por hora: "))
horasTrabalhadas = float(input("Insira quantas horas você trabalhou no mês: "))
totalBruto = salarioHora * horasTrabalhadas
totalImposto = totalBruto * imposto
totaInss = totalBruto * inss
totalSindicato = totalBruto * sindicato
totalLiquido = totalBruto - totalImposto - totaInss - totalSindicato
print(f"\n+ Salário Bruto: R$ {totalBruto:.2f}")
print(f"- I.R.: R$ {totalImposto:.2f}")
print(f"- INSS: R$ {totaInss:.2f}")
print(f"- Sindicato: R$ {totalSindicato:.2f}")
print(f"= Salário Líquido: R$ {totalLiquido:.2f}\n")