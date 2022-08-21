/*
(O Passeio do Cavalo) Um dos quebra-cabeças mais interessantes dos entusiastas do xadrez é 
o problema do Passeio do Cavalo. Esta é a pergunta: a peça de xadrez chamada cavalo pode-se 
mover em um tabuleiro vazio e tocar cada um dos 64 quadrados uma vez e unicamente uma vez? 
Estudamos esse problema intrigante profundamente nesse exercício. O cavalo move-se em um 
caminho em forma de L (duas posições em uma direção e então uma em uma direção perpendicular). 
Portanto, a partir de um quadrado no meio de um tabuleiro vazio, o cavalo pode fazer oito 
movimentos diferentes (numerados de 0 a 7) como mostra a Figura 7.34.

    *  *  *  *  *  *  *  * 
    *  *  *  2  *  1  *  * 
    *  *  3  *  *  *  0  *
    *  *  *  *  K  *  *  *
    *  *  4  *  *  *  7  *
    *  *  *  5  *  6  *  *
    *  *  *  *  *  *  *  * 
    *  *  *  *  *  *  *  * 
    
    Figura 7.34 - Os oito possíveis movimentos do cavalo.

c) Depois de tentar escrever e executar um programa para o Passeio do Cavalo, provavelmente 
alguns insights valiosos foram desenvolvidos. Utilizaremos esses insights para desenvolver 
uma heurística (ou estratégia) para mover o cavalo. A heurística não garante sucesso, mas 
uma heurística cuidadosamente desenvolvida aprimora significativamente a chance de sucesso. 
Você pode ter observado que os quadrados externos são mais incômodos que os quadrados próximos 
do centro do tabuleiro. De fato, os quadrados mais problemáticos, ou inacessíveis, são os quatro cantos.

A intuição pode sugerir que você deve tentar mover o cavalo para os quadrados mais problemáticos 
primeiro e deixar abertos aqueles que são fáceis de alcançar de modo que, quando o tabuleiro 
ficar congestionado próximo do fim do passeio, haja maior chance de sucesso.

Podemos desenvolver uma ‘heurística de acessibilidade’ classificando cada quadrado de acordo 
com seu grau de acessibilidade e então sempre mover o cavaleiro para o quadrado (dentro do 
movimento em forma de L do cavalo, naturalmente) que seja mais inacessível.
Rotulamos um array bidimensional accessibility com números indicando a partir de quantos quadrados
cada quadrado particular é acessível. Em um tabuleiro vazio, os 16 quadrados centrais são avaliados
como 8, cada canto é avaliado como 2 e os outros quadrados têm números de acessibilidade 3, 4 ou 6:

    2  3  4  4  4  4  3  2
    3  4  6  6  6  6  4  3
    4  6  8  8  8  8  6  4
    4  6  8  8  8  8  6  4
    4  6  8  8  8  8  6  4
    4  6  8  8  8  8  6  4
    3  4  6  6  6  6  4  3
    2  3  4  4  4  4  3  2

Agora escreva uma versão do programa do Passeio do Cavalo utilizando a heurística de acessibilidade. 
Em qualquer dado momento, o cavaleiro deve mover-se para o quadrado com o número mais baixo de 
acessibilidade. Em caso de um impasse, o cavalo pode mover-se para qualquer quadrado já visitado. 
Portanto, o passeio pode iniciar em qualquer um dos quatro cantos. [Nota: À medida que o cavalo 
se move pelo tabuleiro de xadrez, seu programa deve reduzir os números de acessibilidade porque 
cada vez mais quadrados se tornam ocupados. Dessa maneira, em qualquer dado tempo durante o passeio, 
o número de acessibilidade de cada quadrado disponível permanecerá precisamente igual ao número 
de quadrados a partir dos quais esse quadrado pode ser alcançado.] Execute essa versão de seu programa. 
Você obteve um passeio completo? Agora modifique o programa para executar 64 passeios, um iniciando
a partir de cada quadrado do tabuleiro de xadrez. Quantos passeios completos você obteve?
*/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <iomanip>
using std::setw;

int main()
{
    const int sideOfChessBoard = 8;
    int acessibility[sideOfChessBoard][sideOfChessBoard] = { {2,3,4,4,4,4,3,2},
                                                             {3,4,6,6,6,6,4,3},
                                                             {4,6,8,8,8,8,6,4},
                                                             {4,6,8,8,8,8,6,4},
                                                             {4,6,8,8,8,8,6,4},
                                                             {4,6,8,8,8,8,6,4},
                                                             {3,4,6,6,6,6,4,3},
                                                             {2,3,4,4,4,4,3,2} };

    int board[sideOfChessBoard][sideOfChessBoard] = { 0 };

    const int emptyBoardSquare = 0; 
    const int arrayLowerBoundIndex = 0;
    const int arrayUpperBoundIndex = 7;
    
    const int horizontal[sideOfChessBoard] = { 2, 1, -1, -2, -2, -1, 1, 2 }; // movimentos possiveis em x
    const int vertical[sideOfChessBoard] = { -1, -2, -2, -1, 1, 2, 2, 1 }; // movimentos possiveis em y
    
    const int initialMoveNumber = 0;
    int moveNumber = 0; // essa variavel combina os 2 arrays acima para movimentar o cavalo
    int tempMoveNumber = 0;
    const int maximumMovesNumber = 8; //    
    
    const int smallestAcessibility = 9; // a menor de todas
    int smallerAcessibility = smallestAcessibility; // a menor do momento
    
    int currentColumn = 0; // está para horizontal[sideOfChessBoard]
    int currentRow = 0; // está para vertical[sideOfChessBoard]
    int tempColumn = currentColumn; // coluna temporaria para teste
    int tempRow = currentRow;  // linha temporaria para teste
    
    int numberOfCurrentMovement = 0; // contador do loop de alterações
    const int numberOfPossibleMovements = 64;
    
    int changeCounter = 0; // marcador de alterações máximas
    
    bool alteration = true; // se alterar o tabuleiro = true
    
    while(numberOfCurrentMovement < numberOfPossibleMovements && alteration == true) // fica no loop, se houve alterações
    {        
        alteration = false;
        smallerAcessibility = smallestAcessibility;        
        moveNumber = initialMoveNumber;
        tempMoveNumber = initialMoveNumber;
        while(tempMoveNumber < maximumMovesNumber) // verifica os 8 movimentos possiveis, e salva o que tem a menor acessibilidade
        {
            if((currentRow + vertical[tempMoveNumber]) >= arrayLowerBoundIndex &&
                (currentRow + vertical[tempMoveNumber]) <= arrayUpperBoundIndex &&
                (currentColumn + horizontal[tempMoveNumber]) >= arrayLowerBoundIndex &&
                (currentColumn + horizontal[tempMoveNumber]) <= arrayUpperBoundIndex)
            {
                tempRow += vertical[tempMoveNumber];
                tempColumn += horizontal[tempMoveNumber];
                if(acessibility[tempRow][tempColumn] != emptyBoardSquare && 
                    acessibility[tempRow][tempColumn] < smallerAcessibility)
                {
                    smallerAcessibility = acessibility[tempRow][tempColumn];
                    moveNumber = tempMoveNumber;                    
                    alteration = true;
                }
                tempRow = currentRow;
                tempColumn = currentColumn;
            }
            tempMoveNumber++;
        }        
        if (alteration == true)
        {
            currentRow += vertical[moveNumber];
            currentColumn += horizontal[moveNumber];
            tempRow = currentRow;
            tempColumn = currentColumn;
            acessibility[currentRow][currentColumn] = emptyBoardSquare;
            board[currentRow][currentColumn] = ++numberOfCurrentMovement;
            changeCounter = numberOfCurrentMovement;
        }
    }
    for(int line = 0; line < sideOfChessBoard; line++, cout << endl)
        for(int column = 0; column < sideOfChessBoard; column++)
            cout << setw(4) << board[line][column];
    cout << "\nchangeCounter = " << changeCounter << endl;
    return 0;
}