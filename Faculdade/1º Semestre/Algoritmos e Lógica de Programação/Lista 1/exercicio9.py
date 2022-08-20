distancia = float(input("Insira a distância percorrida em km: "))
diasUso = int(input("Insira quantos dias o carro foi usado: "))
valorKm = 0.15
valorDia = 60
valorTotal = distancia * valorKm + diasUso * valorDia
print (f"O valor total a pagar é de R$ {valorTotal:.2f}")