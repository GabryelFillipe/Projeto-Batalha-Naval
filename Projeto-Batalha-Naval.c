#include <stdio.h>
#include <stdlib.h>

int main()
{

    int tabuleiro[10][10];
    int linha, coluna;

    for (linha = 0; linha < 10; linha++)
    {
        for (coluna = 0; coluna < 10; coluna++)
        {
            tabuleiro[linha][coluna] = 0;
        }
    }

    printf("--- Navio 1: Horizontal (Tamanho 3) ---\n");
    printf("Escolha a LINHA (0-9): \n");
    int linhaNavilHorizontal;
    scanf("%d", &linhaNavilHorizontal);
    printf("Escolha a COLUNA (0-9): \n");
    int colunaNavilHorizontal;
    scanf("%d", &colunaNavilHorizontal);
    int navilHorizontal[2] = {linhaNavilHorizontal, colunaNavilHorizontal};

    printf("--- Navio 2: Vertical (Tamanho 3) ---\n");
    printf("Escolha a LINHA (0-9): \n");
    int linhaNavilVertical;
    scanf("%d", &linhaNavilVertical);
    printf("Escolha a COLUNA (0-9): \n");
    int colunaNavilVertical;
    scanf("%d", &colunaNavilVertical);
    int navilVertical[2] = {linhaNavilVertical, colunaNavilVertical};

    printf("--- Navio 3: Diagonal (Tamanho 3) ---\n");
    printf("Escolha a LINHA (0-9): \n");
    int linhaNavilDiagonal1;
    scanf("%d", &linhaNavilDiagonal1);
    printf("Escolha a COLUNA (0-9): \n");
    int colunaNavilDiagonal1;
    scanf("%d", &colunaNavilDiagonal1);
    int navilDiagonal1[2] = {linhaNavilDiagonal1, colunaNavilDiagonal1};

    printf("--- Navio 4: Diagonal (Tamanho 3) ---\n");
    printf("Escolha a LINHA (0-9): \n");
    int linhaNavilDiagonal2;
    scanf("%d", &linhaNavilDiagonal2);
    printf("Escolha a COLUNA (0-9): \n");
    int colunaNavilDiagonal2;
    scanf("%d", &colunaNavilDiagonal2);
    int navilDiagonal2[2] = {linhaNavilDiagonal2, colunaNavilDiagonal2};

    int podeColocar;

    if (navilHorizontal[1] + 2 < 10)
    {
        podeColocar = 1;
        for (int i = 0; i < 3; i++)
        {
            if (tabuleiro[navilHorizontal[0]][navilHorizontal[1] + i] != 0)
            {
                podeColocar = 0;
            }
        }

        if (podeColocar == 1)
        {
            for (int i = 0; i < 3; i++)
            {
                tabuleiro[navilHorizontal[0]][navilHorizontal[1] + i] = 3;
            }
        }
        else
        {
            printf("Erro: Sobreposicao no navio horizontal.\n");
        }
    }
    else
    {
        printf("Erro: Navio horizontal fora dos limites.\n");
    }

    if (navilVertical[0] + 2 < 10)
    {
        podeColocar = 1;
        for (int i = 0; i < 3; i++)
        {
            if (tabuleiro[navilVertical[0] + i][navilVertical[1]] != 0)
            {
                podeColocar = 0;
            }
        }

        if (podeColocar == 1)
        {
            for (int i = 0; i < 3; i++)
            {
                tabuleiro[navilVertical[0] + i][navilVertical[1]] = 3;
            }
        }
        else
        {
            printf("Erro: Sobreposicao no navio vertical.\n");
        }
    }
    else
    {
        printf("Erro: Navio vertical fora dos limites.\n");
    }

    if (navilDiagonal1[0] + 2 < 10 && navilDiagonal1[1] + 2 < 10)
    {
        podeColocar = 1;
        for (int i = 0; i < 3; i++)
        {
            if (tabuleiro[navilDiagonal1[0] + i][navilDiagonal1[1] + i] != 0)
            {
                podeColocar = 0;
            }
        }

        if (podeColocar == 1)
        {
            for (int i = 0; i < 3; i++)
            {
                tabuleiro[navilDiagonal1[0] + i][navilDiagonal1[1] + i] = 3;
            }
        }
        else
        {
            printf("Erro: Sobreposicao no navio diagonal 1.\n");
        }
    }
    else
    {
        printf("Erro: Navio diagonal 1 fora dos limites.\n");
    }

    if (navilDiagonal2[0] + 2 < 10 && navilDiagonal2[1] + 2 < 10)
    {
        podeColocar = 1;
        for (int i = 0; i < 3; i++)
        {
            if (tabuleiro[navilDiagonal2[0] + i][navilDiagonal2[1] + i] != 0)
            {
                podeColocar = 0;
            }
        }

        if (podeColocar == 1)
        {
            for (int i = 0; i < 3; i++)
            {
                tabuleiro[navilDiagonal2[0] + i][navilDiagonal2[1] + i] = 3;
            }
        }
        else
        {
            printf("Erro: Sobreposicao no navio diagonal 2.\n");
        }
    }
    else
    {
        printf("Erro: Navio diagonal 2 fora dos limites.\n");
    }

    int matrizCruz[5][5];
    int matrizCone[5][5];
    int matrizOctaedro[5][5];
    int offset = 2;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i == offset || j == offset)
            {
                matrizCruz[i][j] = 1;
            }
            else
            {
                matrizCruz[i][j] = 0;
            }

            if (j >= offset - i && j <= offset + i)
            {
                matrizCone[i][j] = 1;
            }
            else
            {
                matrizCone[i][j] = 0;
            }

            if (abs(i - offset) + abs(j - offset) <= offset)
            {
                matrizOctaedro[i][j] = 1;
            }
            else
            {
                matrizOctaedro[i][j] = 0;
            }
        }
    }

    printf("\n--- Habilidades Especiais ---\n");
    printf("Escolha a habilidade (1=Cruz, 2=Cone, 3=Octaedro): \n");
    int escolhaHabilidade;
    scanf("%d", &escolhaHabilidade);

    printf("Escolha a LINHA de origem da habilidade (0-9): \n");
    int linhaHabilidade;
    scanf("%d", &linhaHabilidade);
    printf("Escolha a COLUNA de origem da habilidade (0-9): \n");
    int colunaHabilidade;
    scanf("%d", &colunaHabilidade);

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            int linhaReal = linhaHabilidade + i - offset;
            int colunaReal = colunaHabilidade + j - offset;

            if (linhaReal >= 0 && linhaReal < 10 && colunaReal >= 0 && colunaReal < 10)
            {
                if (escolhaHabilidade == 1 && matrizCruz[i][j] == 1)
                {
                    tabuleiro[linhaReal][colunaReal] = 5;
                }
                else if (escolhaHabilidade == 2 && matrizCone[i][j] == 1)
                {
                    tabuleiro[linhaReal][colunaReal] = 5;
                }
                else if (escolhaHabilidade == 3 && matrizOctaedro[i][j] == 1)
                {
                    tabuleiro[linhaReal][colunaReal] = 5;
                }
            }
        }
    }

    printf("\n--- Tabuleiro Batalha Naval Final ---\n");
    printf("   ");
    for (coluna = 0; coluna < 10; coluna++)
    {
        printf("%c ", 'A' + coluna);
    }
    printf("\n");

    for (linha = 0; linha < 10; linha++)
    {
        printf("%2d ", linha);
        for (coluna = 0; coluna < 10; coluna++)
        {
            if (tabuleiro[linha][coluna] == 5)
            {
                printf("5 ");
            }
            else if (tabuleiro[linha][coluna] == 3)
            {
                printf("3 ");
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }

    return 0;
}