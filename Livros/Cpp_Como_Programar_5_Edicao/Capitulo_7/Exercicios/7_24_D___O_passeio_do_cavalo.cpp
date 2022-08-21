/*
(O Passeio do Cavalo) Um dos quebra-cabeças mais interessantes dos entusiastas do xadrez é 
o problema do Passeio do Cavalo. Esta é a pergunta: a peça de xadrez chamada cavalo pode-se 
em um tabuleiro vazio e tocar cada um dos 64 quadrados uma vez e unicamente uma vez? 
Estudamos esse problema intrigante profundamente nesse exercício. O cavalo move-se em um 
caminho em forma de L (duas posições em uma direção e então uma em uma direção perpendicular). 
Portanto, a partir de um quadrado no meio de um tabuleiro vazio, o cavalo pode fazer oito 
movimentos diferentes (numerados de 0 a 7) como mostra a Figura 7.34

d) Escreva uma versão do programa Passeio do Cavalo que, diante de um impasse entre dois ou mais quadrados,
decide qual quadrado escolher olhando para a frente aqueles quadrados alcançáveis a partir dos quadrados
geradores do impasse. Seu programa deve moverse para o quadrado por meio do qual seu próximo movimento 
chegaria ao quadrado com o número de acessibilidade mais baixo.
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
    const int side = 8;
    int acessibility[side][side] = { {2,3,4,4,4,4,3,2},
                                     {3,4,6,6,6,6,4,3},
                                     {4,6,8,8,8,8,6,4},
                                     {4,6,8,8,8,8,6,4},
                                     {4,6,8,8,8,8,6,4},
                                     {4,6,8,8,8,8,6,4},
                                     {3,4,6,6,6,6,4,3},
                                     {2,3,4,4,4,4,3,2} };
                                     
    int board[side][side] = { {2,3,4,4,4,4,3,2},
                              {3,4,6,6,6,6,4,3},
                              {4,6,8,8,8,8,6,4},
                              {4,6,8,8,8,8,6,4},
                              {4,6,8,8,8,8,6,4},
                              {4,6,8,8,8,8,6,4},
                              {3,4,6,6,6,6,4,3},
                              {2,3,4,4,4,4,3,2} };
                              
    int test[side][side] = { {2,3,4,4,4,4,3,2},
                             {3,4,6,6,6,6,4,3},
                             {4,6,8,8,8,8,6,4},
                             {4,6,8,8,8,8,6,4},
                             {4,6,8,8,8,8,6,4},
                             {4,6,8,8,8,8,6,4},
                             {3,4,6,6,6,6,4,3},
                             {2,3,4,4,4,4,3,2} };
    
    const int moveX[side] = { 2, 1, -1, -2, -2, -1, 1, 2 }; // movimentos possiveis em x
    const int moveY[side] = { -1, -2, -2, -1, 1, 2, 2, 1 }; // movimentos possiveis em y
    int mN = 0; // moveNumber --- 0 até 7 == 8 movimentos possiveis do cavalo
    // a variavel acima combina os 2 arrays acima para movimentar o cavalo
    
    int tempMN = 0; // tempMoveNumber
    int smallAcess = 9;
    
    vector<int> iX;
    vector<int> iY;
    
    vector<int> indiceMN;
    int sub = 100;
    int decision = 0;
    
    int currentRow = 0; // está para moveV[side]
    int currentColumn = 0; // está para moveH[side]
    int rTemp = 0;  // linha temporaria para teste
    int cTemp = 0; // coluna temporaria para teste
    
    int currentRow2 = 0; // está para moveV[side]
    int currentColumn2 = 0; // está para moveH[side]
    int rTemp2 = 0;  // linha temporaria para teste
    int cTemp2 = 0; // coluna temporaria para teste
    
    int i = 0; // contador do loop de alterações
    int z = 0;
    
    bool alteration = false; // se alterar o tabuleiro = true
    
    int cR = 0;
    int cC = 0;
    
    while(cR < 8)
    {
        cC = 0;
        while(cC < 8)
        {
            int currentColumn = cC; // está para moveH[side]
            int currentRow = cR; // está para moveV[side]
            int cTemp = currentColumn; // coluna temporaria para teste
            int rTemp = currentRow;  // linha temporaria para teste
            i = 0;
            while(i < 64) // board
            {
                alteration = false;
                smallAcess = 9;
                tempMN = 0;
                mN = 0;
                while(mN < 8) // moveNumber
                {
                    if((currentRow + moveY[mN]) >= 0 &&
                        (currentRow + moveY[mN]) <= 7 &&
                        (currentColumn + moveX[mN]) >= 0 &&
                        (currentColumn + moveX[mN]) <= 7)
                    {
                        rTemp += moveY[mN];
                        cTemp += moveX[mN];
                        if(acessibility[rTemp][cTemp] > 0 && 
                            acessibility[rTemp][cTemp] < smallAcess)
                        {
                            smallAcess = acessibility[rTemp][cTemp]; // menor acessibilidade
                            tempMN = mN; // indice do movimento do cavalo
                            alteration = true;
                            indiceMN.clear();
                            indiceMN.push_back(mN);
                        }
                        else if (acessibility[rTemp][cTemp] == smallAcess)
                        {
                            indiceMN.push_back(mN); // salvando os indices do impasse
                            currentRow2 = rTemp; // salvando a posição do impasse
                            currentColumn2 = rTemp;
                            rTemp2 = rTemp;
                            cTemp2 = cTemp;
                        }
                        rTemp = currentRow;
                        cTemp = currentColumn;
                    }
                    mN++;
                }
                if(indiceMN.size() > 1)
                {
                    sub = 100;
                    decision = 0;
                    z = 0;
                    while(z < indiceMN.size())
                    {
                        smallAcess = 9;
                        tempMN = 0;
                        mN = 0;
                        while(mN < 8)
                        {
                            if((currentRow2 + moveY[mN]) >= 0 &&
                                (currentRow2 + moveY[mN]) <= 7 &&
                                (currentColumn2 + moveX[mN]) >= 0 &&
                                (currentColumn2 + moveX[mN]) <= 7)
                            {
                                rTemp2 += moveY[mN];
                                cTemp2 += moveX[mN];
                                if(acessibility[rTemp2][cTemp2] > 0 && 
                                    acessibility[rTemp2][cTemp2] < smallAcess)
                                {
                                    smallAcess = acessibility[rTemp2][cTemp2];
                                }
                                rTemp2 = currentRow2;
                                cTemp2 = currentColumn2;
                            }
                            mN++;
                        }
                        if(smallAcess < sub)
                        {
                            sub = smallAcess; // abaixa o nivel
                            decision = z; // decide pelo indice atual
                        }
                        z++;
                    }
                    tempMN = indiceMN[decision];
                }
                if(alteration == false)
                    break;
                currentRow += moveY[tempMN];
                currentColumn += moveX[tempMN];
                rTemp = currentRow;
                cTemp = currentColumn;
                acessibility[currentRow][currentColumn] = 0;
                test[currentRow][currentColumn] = i + 1; //dddddd
                i++;
            } 
            if(i == 64)
            {
                iX.push_back(cR);
                iY.push_back(cC);
                cout << "Sequencia = " << iX.size() 
                    << "\tl = " << cR << "\tc = " << cC << endl;
                for(int c = 0; c < 8; c++, cout << endl)
                    for(int d = 0; d < 8; d++)
                        cout << setw(4) << test[c][d];
                cout << endl << endl;
                for(int m = 0; m < 8; m++)
                    for(int n = 0; n < 8; n++)
                        test[m][n] = board[m][n];
            }
            for(int a = 0; a < 8; a++)
                for(int b = 0; b < 8; b++)
                    acessibility[a][b] = board[a][b];
            cC++;
        }
        cR++;
    }
    cout << "\t\tSize = " << iX.size() << endl;
    cout << "\n      Row =   ";
    for(int r = 0; r < iX.size(); r++)
        cout << iX[r] << "   ";
    cout << endl;
    cout << "   Column =   ";
    for(int s = 0; s < iX.size(); s++)
        cout << iY[s] << "   ";
    return 0;
}