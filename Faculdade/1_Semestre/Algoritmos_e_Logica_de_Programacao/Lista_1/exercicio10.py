# Escreva um programa para calcular a redução do tempo de vida de um fumante. Pergunte a quantidade de cigarros fumados por dia e quantos anos ele já fumou. Considere que um fumante perde 1 0 minutos de vida a cada cigarro, calcule quantos dias de vida um fumante perderá. Exiba o total de dias.

qtdeCigarros = int(input("Insira quantos cigarros por dia você fuma: "))
qtdeAnos = int(input("Insira quantos anos você já fumou: "))
convAnos = qtdeAnos * 365 # dias
tempCigarro = qtdeCigarros * 10 # minutos
resultado = convAnos * tempCigarro # minutos
resultadoFinal = (resultado / 60) / 24 # dias
print (f"Você perdeu {resultadoFinal:.2f} dias de vida.")