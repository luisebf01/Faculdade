# Solicite o preço de uma mercador ia e o percentual de desconto. Exiba o valor do desconto e 
# o preço a pagar.

preco = float(input("\nInsira o preço da mercadoria: "))
porcentagem = float(input("Insira a porcentagem do desconto: ")) / 100
desconto = preco * porcentagem
novoPreco = preco - desconto
print(f"\nO desconto será de R$ {desconto:.2f} e o novo preço será de R$ {novoPreco:.2f}.\n")