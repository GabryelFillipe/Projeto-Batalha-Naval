#include <stdio.h>

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

    printf("Escolha em que linha o seu navio horizontal comeca (0 a 9): \n");
    int linhaNavilHorizontal;
    scanf("%d", &linhaNavilHorizontal);
    printf("Escolha em qual coluna o seu navio horizontal comeca (0 a 9:)\n");
    int colunaNavilHorizontal;
    scanf("%d", &colunaNavilHorizontal);

    int navilHorizontal[2] = {linhaNavilHorizontal, colunaNavilHorizontal};

    printf("Escolha em que linha o seu navio vartical comeca (0 a 9): \n");
    int linhaNavilVertical;
    scanf("%d", &linhaNavilVertical);
    printf("Escolha em qual coluna o seu navio Vertical comeca (0 a 9:)\n");
    int colunaNavilVertical;
    scanf("%d", &colunaNavilVertical);

    int navilVertical[] = {linhaNavilVertical, colunaNavilVertical};

    if (navilHorizontal[1] + 2 < 10)
    {
        for (int i = 0; i < 3; i++)
        {
            tabuleiro[navilHorizontal[0]][navilHorizontal[1] + i] = 3;
        }
    }
    else
    {
        printf("o navio horizontal nao pode comecar na %d. Pois nao tera espaco para ele ficar no tabuleiro.\n", colunaNavilHorizontal);
    }
    if (navilVertical[0] + 2 < 10)
    {

        for (int i = 0; i < 3; i++)
        {

            tabuleiro[navilVertical[0] + i][navilVertical[1]] = 3;
        }
    }
    else
    {
        printf("o navio vertical nao pode comecar na %d. Pois nao tera espaco para ele ficar no tabuleiro.", linhaNavilVertical);
    }

    printf("--- Tabuleiro Batalha Naval ---\n");

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
            printf("%d ", tabuleiro[linha][coluna]);
        }

        printf("\n");
    }

    return 0;
}