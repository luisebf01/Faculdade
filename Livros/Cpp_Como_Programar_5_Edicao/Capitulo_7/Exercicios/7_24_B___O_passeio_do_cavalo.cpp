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

b) Agora vamos desenvolver um programa que moverá o cavalo por um tabuleiro. O tabuleiro é 
representado por um array bidimensional 8 por 8 chamado board. Cada um dos quadrados é 
inicializado como zero. Descrevemos cada um dos oito possíveis movimentos em termos de seus 
componentes verticais e horizontais. Por exemplo, um movimento do tipo 0 como mostrado na 
Figura 7.34 consiste em mover dois quadrados horizontalmente para direita e um quadrado 
verticalmente para cima. O movimento 2 consiste em mover um quadrado horizontalmente 
para a esquerda e dois quadrados verticalmente para cima. Movimentos horizontais para a 
esquerda e movimentos verticais para cima são indicados com números negativos. 
Os oitos movimentos podem ser descritos por dois arrays unidimensionais, horizontal e 
vertical, como segue:

    horizontal[ 0 ] = 2
    horizontal[ 1 ] = 1
    horizontal[ 2 ] = -1
    horizontal[ 3 ] = -2
    horizontal[ 4 ] = -2
    horizontal[ 5 ] = -1
    horizontal[ 6 ] = 1
    horizontal[ 7 ] = 2
    vertical[ 0 ] = -1
    vertical[ 1 ] = -2
    vertical[ 2 ] = -2
    vertical[ 3 ] = -1
    vertical[ 4 ] = 1
    vertical[ 5 ] = 2
    vertical[ 6 ] = 2
    vertical[ 7 ] = 1

Faça com que as variáveis currentRow e currentColumn indiquem a linha e a coluna da posição
atual do cavalo. Para fazer um movimento do tipo moveNumber, onde moveNumber está entre 
0 e 7, seu programa utiliza as instruções 

    currentRow += vertical[ moveNumber ];
    currentColumn += horizontal[ moveNumber ];
    
Mantenha um contador que varia de 1 para 64. Registre a última contagem em cada quadrado 
para o qual o cavalo se move. Lembrese de testar cada potencial movimento para ver se o 
cavalo já visitou esse quadrado e, naturalmente, teste cada potencial movimento para 
certificar-se de que o cavalo não caia fora do tabuleiro. Agora escreva um programa para 
mover o cavalo pelo tabuleiro. Execute o programa. Quantos movimentos o cavalo fez?
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
    int board[sideOfChessBoard][sideOfChessBoard] = { 0 }; // tabuleiro

    const int emptyBoardSquare = 0; 
    const int arrayLowerBoundIndex = 0;
    const int arrayUpperBoundIndex = 7;
    
    const int horizontal[sideOfChessBoard] = { 2, 1, -1, -2, -2, -1, 1, 2 }; // movimentos possiveis em x
    const int vertical[sideOfChessBoard] = { -1, -2, -2, -1, 1, 2, 2, 1 }; // movimentos possiveis em y
    const int initialMoveNumber = 0;
    int moveNumber = 0; // essa variavel combina os 2 arrays acima para movimentar o cavalo
    const int maximumMovesNumber = 8; //
        
    /*
    os maiores movimentos possiveis achados por mim (55 no total) começam com:
    currentColumn = 6; currentRow = 0;
    currentColumn = 1; currentRow = 1;
    currentColumn = 2; currentRow = 2;
    */
    int currentColumn = 6; // está para horizontal[sideOfChessBoard]
    int currentRow = 0; // está para vertical[sideOfChessBoard]
    int tempColumn = currentColumn; // coluna temporaria para teste
    int tempRow = currentRow;  // linha temporaria para teste
    
    int numberOfCurrentMovement = 0; // contador do loop de alterações
    const int numberOfPossibleMovements = 64;
    
    int changeCounter = 0; // marcador de alterações máximas
    
    bool alteration = true; // se alterar o tabuleiro = true
    
    while(numberOfCurrentMovement < numberOfPossibleMovements && alteration == true) // faz o loop, se houver alterações
    {
        alteration = false;
        moveNumber = initialMoveNumber;
        while(moveNumber < maximumMovesNumber && alteration == false) // faz o loop, se não houver alterações
        {
            if((currentRow + vertical[moveNumber]) >= arrayLowerBoundIndex &&
                (currentRow + vertical[moveNumber]) <= arrayUpperBoundIndex &&
                (currentColumn + horizontal[moveNumber]) >= arrayLowerBoundIndex &&
                (currentColumn + horizontal[moveNumber]) <= arrayUpperBoundIndex)
            {
                tempRow += vertical[moveNumber];
                tempColumn += horizontal[moveNumber];
                if(board[tempRow][tempColumn] == emptyBoardSquare)
                {
                    currentRow = tempRow;
                    currentColumn = tempColumn;      
                    board[currentRow][currentColumn] = numberOfCurrentMovement + 1;
                    alteration = true;
                }
                else
                {
                    tempRow = currentRow;
                    tempColumn = currentColumn;
                }
            }
            moveNumber++;
            changeCounter = numberOfCurrentMovement;
        }
        numberOfCurrentMovement++;
    }
    for(int line = 0; line < sideOfChessBoard; line++, cout << endl)
        for(int column = 0; column < sideOfChessBoard; column++)
            cout << setw(4) << board[line][column];
    cout << "\nchangeCounter = " << changeCounter << endl;
    return 0;
}