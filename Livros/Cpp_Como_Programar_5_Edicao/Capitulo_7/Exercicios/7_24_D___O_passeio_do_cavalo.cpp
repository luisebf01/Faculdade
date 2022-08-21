/*
(O Passeio do Cavalo) Um dos quebra-cabeças mais interessantes dos entusiastas do xadrez é 
o problema do Passeio do Cavalo. Esta é a pergunta: a peça de xadrez chamada cavalo pode-se 
em um tabuleiro vazio e tocar cada um dos 64 quadrados uma vez e unicamente uma vez? 
Estudamos esse problema intrigante profundamente nesse exercício. O cavalo move-se em um 
caminho em forma de L (duas posições em uma direção e então uma em uma direção perpendicular). 
Portanto, a partir de um quadrado no meio de um tabuleiro vazio, o cavalo pode fazer oito 
movimentos diferentes (numerados de 0 a 7) como mostra a Figura 7.34

d) Escreva uma versão do programa Passeio do Cavalo que, diante de um impasse entre dois ou mais 
quadrados, decide qual quadrado escolher olhando para a frente aqueles quadrados alcançáveis 
a partir dos quadrados geradores do impasse. Seu programa deve moverse para o quadrado por meio
do qual seu próximo movimento chegaria ao quadrado com o número de acessibilidade mais baixo.
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
    int columnTemp = currentColumn; // coluna temporaria para teste
    int rowTemp = currentRow;  // linha temporaria para teste
    
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
                rowTemp += vertical[tempMoveNumber];
                columnTemp += horizontal[tempMoveNumber];
                if(acessibility[rowTemp][columnTemp] != emptyBoardSquare && 
                    acessibility[rowTemp][columnTemp] < smallerAcessibility)
                {
                    smallerAcessibility = acessibility[rowTemp][columnTemp];
                    moveNumber = tempMoveNumber;                    
                    alteration = true;
                }
                rowTemp = currentRow;
                columnTemp = currentColumn;
            }
            tempMoveNumber++;
        }        
        if (alteration == true)
        {
            currentRow += vertical[moveNumber];
            currentColumn += horizontal[moveNumber];
            rowTemp = currentRow;
            columnTemp = currentColumn;
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