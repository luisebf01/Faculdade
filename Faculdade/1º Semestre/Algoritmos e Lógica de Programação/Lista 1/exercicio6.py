# Calcule o tempo de uma viagem de carro. Pergunte a distância a percorrer e a velocidade média esperada para a viagem

distancia = float(input("Insira a distância a percorrer em km: ")) * 1000 # converte para metros
velocidadeMedia = float(input("Insira a velocidade média esperada em km/h: ")) / 3.6 # converte para m/s
tempo = (distancia / velocidadeMedia) / 60
minutos = int(tempo)
segundos = int(60 * (tempo - minutos))
print(f"O tempo médio da viagem será de {minutos} minutos e {segundos} segundos.")