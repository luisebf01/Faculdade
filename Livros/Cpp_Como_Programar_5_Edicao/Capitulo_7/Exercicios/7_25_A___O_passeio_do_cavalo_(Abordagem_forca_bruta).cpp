/*
(Passeio do Cavalo: abordagens de força bruta) No Exercício 7.24 desenvolvemos uma solução para o problema
do Passeio do Cavalo. A abordagem utilizada, chamada de ‘acessibilidade heurística’, gera muitas soluções
e executa eficientemente. À medida que os computadores continuam aumentando em potência, seremos capazes
de resolver cada vez mais problemas com a pura capacidade do computador e algoritmos relativamente simples.
Essa é a abordagem de ‘força bruta’ para resolução de problemas.

a) Utilize geração de números aleatórios para permitir que o cavalo ande pelo tabuleiro de xadrez (em seus
movimentos válidos em forma de L, naturalmente) de maneira aleatória. Seu programa deve executar um passeio
e imprimir o tabuleiro de xadrez final. Até onde o cavalo chegou?
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

    int acessibility[sideOfChessBoard][sideOfChessBoard] = { {2,3,4,4,4,4,3,2},
                                                             {3,4,6,6,6,6,4,3},
                                                             {4,6,8,8,8,8,6,4},
                                                             {4,6,8,8,8,8,6,4},
                                                             {4,6,8,8,8,8,6,4},
                                                             {4,6,8,8,8,8,6,4},
                                                             {3,4,6,6,6,6,4,3},
                                                             {2,3,4,4,4,4,3,2} };
                                     
    int board[sideOfChessBoard][sideOfChessBoard] = { {2,3,4,4,4,4,3,2},
                                                      {3,4,6,6,6,6,4,3},
                                                      {4,6,8,8,8,8,6,4},
                                                      {4,6,8,8,8,8,6,4},
                                                      {4,6,8,8,8,8,6,4},
                                                      {4,6,8,8,8,8,6,4},
                                                      {3,4,6,6,6,6,4,3},
                                                      {2,3,4,4,4,4,3,2} };    
                              
    int test[sideOfChessBoard][sideOfChessBoard] = { 0 };

    const int emptyBoardSquare = 0; 
    const int arrayLowerBoundIndex = 0;
    const int arrayUpperBoundIndex = 7;
    
    const int horizontal[sideOfChessBoard] = { 2, 1, -1, -2, -2, -1, 1, 2 }; // movimentos possiveis em x
    const int vertical[sideOfChessBoard] = { -1, -2, -2, -1, 1, 2, 2, 1 }; // movimentos possiveis em y

    const int initialMoveNumber = 0;
    int moveNumber = 0; // essa variavel combina os 2 arrays acima para movimentar o cavalo
    int tempMoveNumber = 0;    
    const int maximumMovesNumber = 8;  
    
    const int smallestAcessibility = 9;
    int smallerAcessibility = smallestAcessibility;
    int smallAcessibility = smallestAcessibility;
    
    vector<int> listRow;
    vector<int> listColumn;    
    vector<int> listOfMoveNumbers;

    int decision = 0;
    
    int row_FirstMove = 0;
    int column_FirstMove = 0;
    int tempRow_FirstMove = 0;
    int tempColumn_FirstMove = 0;
    
    int row_SecondMove = 0;
    int column_SecondMove = 0;
    int tempRow_SecondMove = 0;
    int tempColumn_SecondMove = 0;
    
    const int initialMovement = 0;
    int numberOfCurrentMovement = initialMovement;
    const int numberOfPossibleMovements = 64;
    
    bool alteration = false;
    
    int currentRow = 0;
    int currentColumn = 0;
    
    while(currentRow < ranks) // enquanto a linha atual for menor que o total de linhas do tabuleiro
    {
        currentColumn = initialMovement; // reseta a coluna, para todas as linhas
        while(currentColumn < files) // enquanto a coluna atual for menor que o total de colunas do tabuleiro
        {
            int column_FirstMove = currentColumn; // configura a coluna inicial
            int row_FirstMove = currentRow; // configura a linha inicial
            int tempColumn_FirstMove = column_FirstMove; // reseta a coluna temporária
            int tempRow_FirstMove = row_FirstMove; // reseta a linha temporária
            numberOfCurrentMovement = initialMovement; // reseta o numero de movimentos a serem testados
            while(numberOfCurrentMovement < numberOfPossibleMovements) // loop que testa todas as 64(8x8) casas do tabuleiro começando das (linhas x colunas) atuais
            {
                alteration = false;
                smallAcessibility = smallestAcessibility; // reseta a acessibilidade temporária
                tempMoveNumber = initialMoveNumber;
                moveNumber = initialMoveNumber;
                while(moveNumber < maximumMovesNumber) // loop que testa todos os 8 movimentos do cavalo
                {
                    if((row_FirstMove + vertical[moveNumber]) >= arrayLowerBoundIndex &&
                        (row_FirstMove + vertical[moveNumber]) <= arrayUpperBoundIndex &&
                        (column_FirstMove + horizontal[moveNumber]) >= arrayLowerBoundIndex &&
                        (column_FirstMove + horizontal[moveNumber]) <= arrayUpperBoundIndex) // se o movimento não extrapola os limites do tabuleiro
                    {
                        tempRow_FirstMove += vertical[moveNumber];
                        tempColumn_FirstMove += horizontal[moveNumber];
                        if(acessibility[tempRow_FirstMove][tempColumn_FirstMove] != emptyBoardSquare && 
                            acessibility[tempRow_FirstMove][tempColumn_FirstMove] < smallAcessibility) // se o movimento é aceitável e tem a menor acessibilidade
                        {
                            smallAcessibility = acessibility[tempRow_FirstMove][tempColumn_FirstMove]; // salva a acessibilidade do movimento
                            tempMoveNumber = moveNumber; // salva o índice do movimento em uma váriavel temporária
                            alteration = true; // salva como verdadeiro, que vai haver alterações no tabuleiro
                            listOfMoveNumbers.clear(); // limpa a lista de movimentos possíveis
                            listOfMoveNumbers.push_back(moveNumber); // salva o índice do movimento, como o primeiro da fila na lista de movimentos possíveis
                        }
                        else if (acessibility[tempRow_FirstMove][tempColumn_FirstMove] == smallAcessibility) // se é um movimento com a mesma acessibilidade do anterior
                        {
                            listOfMoveNumbers.push_back(moveNumber); // salva o índice do impasse, como o último da fila na lista de movimentos possíveis
                            row_SecondMove = tempRow_FirstMove; // a linha inicial do segundo movimento, começa a partir da linha temporária do primeiro movimento
                            column_SecondMove = tempRow_FirstMove; // a coluna inicial do segundo movimento, começa a partir da coluna temporária do primeiro movimento 
                            tempRow_SecondMove = tempRow_FirstMove; // a linha temporária do segundo movimento, começa a partir da linha inicial do segundo movimento
                            tempColumn_SecondMove = tempColumn_FirstMove; // a coluna temporária do segundo movimento, começa a partir da coluna inicial do segundo movimento
                        }
                        tempRow_FirstMove = row_FirstMove; // reseta a linha temporária, para a linha atual
                        tempColumn_FirstMove = column_FirstMove; // reseta a coluna temporária, para a coluna atual
                    }
                    moveNumber++; // pula para o próximo movimento do cavalo
                }
                if(listOfMoveNumbers.size() > 1) // se existe mais de 1 movimento possível com a mesma acessibilidade
                {
                    srand(time(NULL));
                    decision = rand() % listOfMoveNumbers.size(); // decide pelo indice aleatório
                    tempMoveNumber = listOfMoveNumbers[decision];
                }
                if(alteration == false) // se não houve uma alteração
                    break;
                row_FirstMove += vertical[tempMoveNumber]; // 'faz' o movimento vertical do cavalo
                column_FirstMove += horizontal[tempMoveNumber]; // 'faz' o movimento horizontal do cavalo
                tempRow_FirstMove = row_FirstMove; // reseta a linha temporária, para a linha atual
                tempColumn_FirstMove = column_FirstMove; // reseta a coluna temporária, para a coluna atual
                acessibility[row_FirstMove][column_FirstMove] = emptyBoardSquare; // marca no tabuleiro 'acessibility' o movimento do cavalo, para inutilizar essa casa futuramente
                test[row_FirstMove][column_FirstMove] = ++numberOfCurrentMovement; // salva no tabuleiro 'test' o número do movimento que deu certo, a fim de rastreio dos movimentos
            } 
            if(numberOfCurrentMovement == numberOfPossibleMovements) // significa que completei um tabuleiro
            {
                listRow.push_back(currentRow); // salva a linha inicial do passeio na lista 'listRow'
                listColumn.push_back(currentColumn); // salva a coluna inicial do passeio na lista 'listColumn'
                cout << "Sequencia = " << listRow.size() 
                    << "\tl = " << currentRow << "\tc = " << currentColumn << endl; // printa o 'cabeçalho' do tabuleiro
                for(int line = 0; line < ranks; line++, cout << endl)
                    for(int column = 0; column < files; column++)
                        cout << setw(4) << test[line][column]; // printa o tabuleiro 'test', que está com todos os movimentos feitos
                cout << endl << endl;
                for(int line = 0; line < ranks; line++)
                    for(int column = 0; column < files; column++)
                        test[line][column] = board[line][column]; // reseta o tabuleiro 'test'
            }
            for(int line = 0; line < ranks; line++)
                for(int column = 0; column < files; column++)
                    acessibility[line][column] = board[line][column]; // reseta o tabuleiro 'acessibility'
            currentColumn++; // pula pra próxima coluna
        }
        currentRow++; // pula pra próxima linha
    }
    cout << "\t\tSize = " << listRow.size() << endl; // printa quantos tabuleiros foram feitos
    cout << "\n      Row =   ";
    for(int line = 0; line < listRow.size(); line++)
        cout << listRow[line] << "   ";  // printa as linhas iniciais que deram certo
    cout << endl;
    cout << "   Column =   ";
    for(int column = 0; column < listRow.size(); column++)
        cout << listColumn[column] << "   "; // printa as colunas iniciais que deram certo
    return 0;
}