/*
(O Passeio do Cavalo) Um dos quebra-cabeças mais interessantes dos entusiastas do xadrez é 
o problema do Passeio do Cavalo. Esta é a pergunta: a peça de xadrez chamada cavalo pode-se 
em um tabuleiro vazio e tocar cada um dos 64 quadrados uma vez e unicamente uma vez? 
Estudamos esse problema intrigante profundamente nesse exercício. O cavalo move-se em um 
caminho em forma de L (duas posições em uma direção e então uma em uma direção perpendicular). 
Portanto, a partir de um quadrado no meio de um tabuleiro vazio, o cavalo pode fazer oito 
movimentos diferentes (numerados de 0 a 7) como mostra a Figura 7.34

d) currentRoweva uma versão do programa Passeio do Cavalo que, diante de um impasse entre dois ou mais quadrados,
decide qual quadrado escolher olhando para a frente aqueles quadrados alcançáveis a partir dos quadrados
geradores do impasse. Seu programa deve mover-se para o quadrado por meio do qual seu próximo movimento 
chegaria ao quadrado com o número de acessibilidade mais balistRowo.
*/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <iomanip>
using std::setw;

#include <vector>
using std::vector;

int main()
{
    const int sideOfChessBoard = 8;
    const int ranks = sideOfChessBoard; // rows of a chessboard
    const int files = sideOfChessBoard; // columns of a chessboard    
                                     
    const int board[sideOfChessBoard][sideOfChessBoard] = { {2,3,4,4,4,4,3,2},
                                                            {3,4,6,6,6,6,4,3},
                                                            {4,6,8,8,8,8,6,4},
                                                            {4,6,8,8,8,8,6,4},
                                                            {4,6,8,8,8,8,6,4},
                                                            {4,6,8,8,8,8,6,4},
                                                            {3,4,6,6,6,6,4,3},
                                                            {2,3,4,4,4,4,3,2} };

    int acessibility[sideOfChessBoard][sideOfChessBoard] = { {2,3,4,4,4,4,3,2},
                                                             {3,4,6,6,6,6,4,3},
                                                             {4,6,8,8,8,8,6,4},
                                                             {4,6,8,8,8,8,6,4},
                                                             {4,6,8,8,8,8,6,4},
                                                             {4,6,8,8,8,8,6,4},
                                                             {3,4,6,6,6,6,4,3},
                                                             {2,3,4,4,4,4,3,2} };
                              
    int test[sideOfChessBoard][sideOfChessBoard] = { {2,3,4,4,4,4,3,2},
                                                     {3,4,6,6,6,6,4,3},
                                                     {4,6,8,8,8,8,6,4},
                                                     {4,6,8,8,8,8,6,4},
                                                     {4,6,8,8,8,8,6,4},
                                                     {4,6,8,8,8,8,6,4},
                                                     {3,4,6,6,6,6,4,3},
                                                     {2,3,4,4,4,4,3,2} };

    const int emptyBoardSquare = 0; 
    const int arrayLowerBoundIndex = 0;
    const int arrayUpperBoundIndex = 7;

    const int horizontal[sideOfChessBoard] = { 2, 1, -1, -2, -2, -1, 1, 2 }; // movimentos possiveis em x
    const int vertical[sideOfChessBoard] = { -1, -2, -2, -1, 1, 2, 2, 1 }; // movimentos possiveis em y

    const int initialMoveNumber = 0;
    int moveNumber = 0; // essa variavel combina os 2 arrays acima para movimentar o cavalo
    int tempMoveNumber = 0;    
    int decisiveMoveNumber = 0;
    const int maximumMovesNumber = 8;  

    const int smallestAcessibility = 9;
    int smallerAcessibility = smallestAcessibility;
    
    vector<int> listRow;
    vector<int> listColumn;    
    vector<int> listOfMoveNumbers;
    
    int sub = 100;
    int decision = 0;
    
    int row_FirstMove = 0; // está para moveV[sideOfChessBoard]
    int column_FirstMove = 0; // está para moveH[sideOfChessBoard]
    int tempRow_FirstMove = 0;  // linha temporaria para teste
    int tempColumn_FirstMove = 0; // coluna temporaria para teste
    
    int row_SecondMove = 0; // está para moveV[sideOfChessBoard]
    int column_SecondMove = 0; // está para moveH[sideOfChessBoard]
    int tempRow_SecondMove = 0;  // linha temporaria para teste
    int tempColumn_SecondMove = 0; // coluna temporaria para teste
        
    int numberOfCurrentMovement = 0; // contador do loop de alterações
    const int numberOfPossibleMovements = 64;
    
    bool alteration = false; // se alterar o tabuleiro = true
    
    int currentRow = 0;
    int currentColumn = 0;
    
    while(currentRow < ranks)
    {
        currentColumn = 0;
        while(currentColumn < files)
        {
            column_FirstMove = currentColumn; // está para moveH[sideOfChessBoard]
            row_FirstMove = currentRow; // está para moveV[sideOfChessBoard]
            tempColumn_FirstMove = column_FirstMove; // coluna temporaria para teste
            tempRow_FirstMove = row_FirstMove;  // linha temporaria para teste
            numberOfCurrentMovement = 0;
            while(numberOfCurrentMovement < numberOfPossibleMovements) // board
            {
                alteration = false;
                smallerAcessibility = smallestAcessibility;
                tempMoveNumber = initialMoveNumber;
                moveNumber = initialMoveNumber;
                while(moveNumber < 8) // moveNumber
                {
                    if((row_FirstMove + vertical[moveNumber]) >= arrayLowerBoundIndex &&
                        (row_FirstMove + vertical[moveNumber]) <= arrayUpperBoundIndex &&
                        (column_FirstMove + horizontal[moveNumber]) >= arrayLowerBoundIndex &&
                        (column_FirstMove + horizontal[moveNumber]) <= arrayUpperBoundIndex)
                    {
                        tempRow_FirstMove += vertical[moveNumber];
                        tempColumn_FirstMove += horizontal[moveNumber];
                        if(acessibility[tempRow_FirstMove][tempColumn_FirstMove] != emptyBoardSquare && 
                            acessibility[tempRow_FirstMove][tempColumn_FirstMove] < smallerAcessibility)
                        {
                            smallerAcessibility = acessibility[tempRow_FirstMove][tempColumn_FirstMove]; // menor acessibilidade
                            tempMoveNumber = moveNumber; // indice do movimento do cavalo
                            alteration = true;
                            listOfMoveNumbers.clear();
                            listOfMoveNumbers.push_back(moveNumber);
                        }
                        else if (acessibility[tempRow_FirstMove][tempColumn_FirstMove] == smallerAcessibility)
                        {
                            listOfMoveNumbers.push_back(moveNumber); // salvando os indices do impasse
                            row_SecondMove = tempRow_FirstMove; // salvando a posição do impasse
                            tempRow_SecondMove = tempRow_FirstMove;
                            column_SecondMove = tempColumn_FirstMove;                            
                            tempColumn_SecondMove = tempColumn_FirstMove;
                        }
                        tempRow_FirstMove = row_FirstMove;
                        tempColumn_FirstMove = column_FirstMove;
                    }
                    moveNumber++;
                }
                if(listOfMoveNumbers.size() > 1)
                {
                    sub = 100;
                    decision = 0;
                    decisiveMoveNumber = 0;
                    while(decisiveMoveNumber < listOfMoveNumbers.size())
                    {
                        smallerAcessibility = smallestAcessibility;
                        tempMoveNumber = initialMoveNumber;
                        moveNumber = initialMoveNumber;
                        while(moveNumber < 8)
                        {
                            if((row_SecondMove + vertical[moveNumber]) >= arrayLowerBoundIndex &&
                                (row_SecondMove + vertical[moveNumber]) <= arrayUpperBoundIndex &&
                                (column_SecondMove + horizontal[moveNumber]) >= arrayLowerBoundIndex &&
                                (column_SecondMove + horizontal[moveNumber]) <= arrayUpperBoundIndex)
                            {
                                tempRow_SecondMove += vertical[moveNumber];
                                tempColumn_SecondMove += horizontal[moveNumber];
                                if(acessibility[tempRow_SecondMove][tempColumn_SecondMove] != emptyBoardSquare && 
                                    acessibility[tempRow_SecondMove][tempColumn_SecondMove] < smallerAcessibility)
                                {
                                    smallerAcessibility = acessibility[tempRow_SecondMove][tempColumn_SecondMove];
                                }
                                tempRow_SecondMove = row_SecondMove;
                                tempColumn_SecondMove = column_SecondMove;
                            }
                            moveNumber++;
                        }
                        if(smallerAcessibility < sub)
                        {
                            sub = smallerAcessibility; // abalistRowa o nivel
                            decision = decisiveMoveNumber; // decide pelo indice atual
                        }
                        decisiveMoveNumber++;
                    }
                    tempMoveNumber = listOfMoveNumbers[decision];
                }
                if(alteration == false)
                    break;
                row_FirstMove += vertical[tempMoveNumber];
                column_FirstMove += horizontal[tempMoveNumber];
                tempRow_FirstMove = row_FirstMove;
                tempColumn_FirstMove = column_FirstMove;
                acessibility[row_FirstMove][column_FirstMove] = 0;
                test[row_FirstMove][column_FirstMove] = numberOfCurrentMovement + 1;
                numberOfCurrentMovement++;
            } 
            if(numberOfCurrentMovement == numberOfPossibleMovements)
            {
                listRow.push_back(currentRow);
                listColumn.push_back(currentColumn);
                cout << "Sequencia = " << listRow.size() 
                    << "\tl = " << currentRow << "\tc = " << currentColumn << endl;
                for(int line = 0; line < ranks; line++, cout << endl)
                    for(int column = 0; column < files; column++)
                        cout << setw(4) << test[line][column];
                cout << endl << endl;
                for(int m = 0; m < ranks; m++)
                    for(int n = 0; n < files; n++)
                        test[m][n] = board[m][n];
            }
            for(int a = 0; a < ranks; a++)
                for(int b = 0; b < files; b++)
                    acessibility[a][b] = board[a][b];
            currentColumn++;
        }
        currentRow++;
    }
    cout << "\t\tSize = " << listRow.size() << endl;
    cout << "\n      Row =   ";
    for(int r = 0; r < listRow.size(); r++)
        cout << listRow[r] << "   ";
    cout << endl;
    cout << "   Column =   ";
    for(int s = 0; s < listRow.size(); s++)
        cout << listColumn[s] << "   ";
    return 0;
}