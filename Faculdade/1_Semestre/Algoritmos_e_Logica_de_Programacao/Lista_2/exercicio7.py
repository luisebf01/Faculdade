'''
Faça um programa para uma loja de tintas. O programa deverá pedir o tamanho em metros quadrados da área a
ser pintada. Considere que a cobertura da tinta é de 1 litro para cada 3 metros quadrados e que a tinta 
é vendida em latas de 18 litros, que custam R$ 80,00. Informe ao usuário a quantidades de latas de tinta
 a serem compradas e o preço total. Obs.: somente são vendidos um número inteiro de latas.
'''

import math
area = float(input("\nInsira o tamanho da área a ser pintada em m²: "))
rendimentoTinta = area / 3
volumeLataTinta = 18
valorLataTinta = 80
calculoLatas = math.ceil(rendimentoTinta / volumeLataTinta)
answer = "1 lata" if calculoLatas == 1 else str(calculoLatas) + " latas"
print(f"\nVocê vai precisar de {answer} de tinta.\n")
