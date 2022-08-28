# Escreva um programa que leia a quantidade de dias, horas, minutos e segundos do usuário. Calcule o 
# total em segundos.

d = int(input("\nInsira a quantidade de dias: "))
h = int(input("Insira a quantidade de horas: "))
m = int(input("Insira a quantidade de minutos: "))
s = int(input("Insira a quantidade de segundos: "))
tempo = (d * 24 * 60 * 60) + (h * 60 * 60) + (m * 60) + s
print (f"\nO tempo total é de {tempo} segundos.\n")