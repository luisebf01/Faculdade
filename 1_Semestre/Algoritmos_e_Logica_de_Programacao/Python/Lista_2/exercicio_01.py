# Faça um Programa que peça os três lados de um triângulo. O programa deverá informar se os valores 
# podem ser um triângulo. Indique, caso os lados formem um triângulo, se o mesmo é: equilátero, 
# isósceles ou escaleno.

print(f"\nInsira 3 valores abaixo separados por vírgula.")
l1, l2, l3 = eval(input('Lado 1, Lado 2, Lado 3: '))
if (l1 + l2) > l3 and (l1 + l3) > l2 and (l2 + l3) > l1:
    if (l1 == l2 and l1 == l3):
        print(f"\nOs 3 lados formam um triângulo EQUILÁTERO.\n")
    elif (l1 == l2 or l1 == l3 or l2 == l3):
        print(f"\nOs 3 lados formam um triângulo ISÓSCELES.\n")
    else:
        print(f"\nOs 3 lados formam um triângulo ESCALENO.\n")
else:
    print(f"\nOs 3 lados não formam um triângulo.\n")