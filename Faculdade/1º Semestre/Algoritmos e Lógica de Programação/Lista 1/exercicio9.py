# Escreva um programa que pergunte a quantidade de km percorridos por um carro alugado pelo usuário, assim como a quantidade de dias pelos quais o carro foi alugado. Calcule o preço a pagar, sabendo que o carro custa R$ 60,00 por dia e R$ 0,15 por km rodado.

distancia = float(input("Insira a distância percorrida em km: "))
diasUso = int(input("Insira quantos dias o carro foi usado: "))
valorKm = 0.15
valorDia = 60
valorTotal = distancia * valorKm + diasUso * valorDia
print (f"O valor total a pagar é de R$ {valorTotal:.2f}")