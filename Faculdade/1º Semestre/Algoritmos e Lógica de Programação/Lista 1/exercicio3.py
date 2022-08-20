d = int(input("Insira a quantidade de dias: "))
h = int(input("Insira a quantidade de horas: "))
m = int(input("Insira a quantidade de minutos: "))
s = int(input("Insira a quantidade de segundos: "))
tempo = (d * 24 * 60 * 60) + (h * 60 * 60) + (m * 60) + s
print (f"O tempo total é de {tempo} segundos.")