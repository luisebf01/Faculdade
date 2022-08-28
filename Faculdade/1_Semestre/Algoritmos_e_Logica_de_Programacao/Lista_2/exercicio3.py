# João Papo-de-Pescador, homem de bem, comprou um microcomputador para controlar o rendimento diário 
# de seu trabalho. Toda vez que ele traz um peso de peixes maior que o estabelecido pelo regulamento 
# de pesca do estado de São Paulo (50 quilos) deve pagar uma multa de R$ 4,00 por quilo excedente. 
# João precisa que você faça um programa que leia a variável peso (peso de peixes) e verifique se há 
# excesso. Se houver, gravar na variável excesso e na variável multa o valor da multa que João deverá 
# pagar. Caso contrário mostrar tais variáveis com o conteúdo ZERO.

limite = 50
multa = 0
excesso = 0
peso = int(input("\nInsira o peso dos peixes: "))
if peso > limite:
    excesso = peso - limite
    multa = 4 * excesso
print(f"\nHouve um excesso de {excesso} kilos e a multa será de R$ {multa}.\n")
