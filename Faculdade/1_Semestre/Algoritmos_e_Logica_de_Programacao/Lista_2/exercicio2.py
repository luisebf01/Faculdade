# Determine se um ano é bissexto. Verifique no Google como fazer isso...

from calendar import isleap
y = int(input("\nInsira um ano: "))
if isleap(y):
    print(f"\nO ano é bissexto.\n")
else:
    print(f"\nO ano não é bissexto.\n")