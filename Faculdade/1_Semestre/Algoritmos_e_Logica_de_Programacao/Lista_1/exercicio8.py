# Faça agora o contrário, de Fahrenheit para Celsius.

tempFahrenheit = float(input("\nInsira a temperatura em graus Fahrenheit: "))
convCelsius = (tempFahrenheit - 32) * 5 / 9
print (f"\nO valor convertido é {convCelsius:.2f}° C.\n")