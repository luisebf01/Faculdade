qtdeCigarros = int(input("Insira quantos cigarros por dia você fuma: "))
qtdeAnos = int(input("Insira quantos anos você já fumou: "))
convAnos = qtdeAnos * 365 # dias
tempCigarro = qtdeCigarros * 10 # minutos
resultado = convAnos * tempCigarro # minutos
resultadoFinal = (resultado / 60) / 24 # dias
print (f"Você perdeu {resultadoFinal:.2f} dias de vida.")