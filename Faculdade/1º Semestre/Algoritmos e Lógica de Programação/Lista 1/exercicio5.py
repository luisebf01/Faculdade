preco = float(input("Insira o preço da mercadoria: "))
porcentagem = float(input("Insira a porcentagem do desconto: ")) / 100
desconto = preco * porcentagem
novoPreco = preco - desconto
print(f"O desconto será de R$ {desconto:.2f} e o novo preço será de R$ {novoPreco:.2f}.")