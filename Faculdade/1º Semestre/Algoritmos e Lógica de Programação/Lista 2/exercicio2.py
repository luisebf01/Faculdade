# Determine se um ano é bissexto. Verifique no Google como fazer isso...

from calendar import isleap
y = int(input("Insira um ano: "))
if isleap(y):
    print(f"O ano é bissexto.")
else:
    print(f"O ano não é bissexto.")