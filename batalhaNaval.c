🏅 Nível Novato

#include <stdio.h>

#define TAMANHO_NAVIO 3 // Tamanho fixo dos navios

    int
    main()
{
    // Definição das coordenadas iniciais
    int x_vertical = 2, y_vertical = 3;     // Posição inicial do navio vertical
    int x_horizontal = 5, y_horizontal = 1; // Posição inicial do navio horizontal

    // Exibição das coordenadas do navio vertical
    printf("Navio Vertical:\n");
    for (int i = 0; i < TAMANHO_NAVIO; i++)
    {
        printf("(%d, %d)\n", x_vertical, y_vertical + i);
    }

    // Exibição das coordenadas do navio horizontal
    printf("\nNavio Horizontal:\n");
    for (int i = 0; i < TAMANHO_NAVIO; i++)
    {
        printf("(%d, %d)\n", x_horizontal + i, y_horizontal);
    }

    return 0;
}

🏅 Nível Aventureiro

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
#define SHIP 3
#define EMPTY 0
#define NUM_SHIPS 4

    int board[SIZE][SIZE];

void initializeBoard()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            board[i][j] = EMPTY;
        }
    }
}

int canPlaceShip(int row, int col, int size, int isDiagonal)
{
    for (int i = 0; i < size; i++)
    {
        int r = isDiagonal ? row + i : row;
        int c = isDiagonal ? col + i : col;
        if (r >= SIZE || c >= SIZE || board[r][c] == SHIP)
        {
            return 0;
        }
    }
    return 1;
}

void placeShip(int size, int isDiagonal)
{
    int placed = 0;
    while (!placed)
    {
        int row = rand() % SIZE;
        int col = rand() % SIZE;
        if (canPlaceShip(row, col, size, isDiagonal))
        {
            for (int i = 0; i < size; i++)
            {
                int r = isDiagonal ? row + i : row;
                int c = isDiagonal ? col + i : col;
                board[r][c] = SHIP;
            }
            placed = 1;
        }
    }
}

void printBoard()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    srand(time(NULL));
    initializeBoard();

    placeShip(3, 0);
    placeShip(3, 0);
    placeShip(3, 1);
    placeShip(3, 1);

    printBoard();
    return 0;
}

🏅 Nível Mestre

#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 10

    int tabuleiro[TAMANHO][TAMANHO];

// Inicializa o tabuleiro com zeros
void inicializarTabuleiro()
{
    for (int i = 0; i < TAMANHO; i++)
    {
        for (int j = 0; j < TAMANHO; j++)
        {
            tabuleiro[i][j] = 0;
        }
    }
}

// Exibe o tabuleiro no console
void exibirTabuleiro()
{
    for (int i = 0; i < TAMANHO; i++)
    {
        for (int j = 0; j < TAMANHO; j++)
        {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Aplica a habilidade Cone (triangular descendente)
void aplicarCone(int x, int y)
{
    for (int i = 0; i < 3; i++)
    { // Altura do cone
        for (int j = -i; j <= i; j++)
        { // Largura do cone
            if (x + i < TAMANHO && y + j >= 0 && y + j < TAMANHO)
            {
                tabuleiro[x + i][y + j] = 1;
            }
        }
    }
}

// Aplica a habilidade Cruz
void aplicarCruz(int x, int y)
{
    for (int i = 0; i < TAMANHO; i++)
    {
        tabuleiro[x][i] = 1; // Linha horizontal
        tabuleiro[i][y] = 1; // Linha vertical
    }
}

// Aplica a habilidade Octaedro (losango)
void aplicarOctaedro(int x, int y)
{
    for (int i = -2; i <= 2; i++)
    {
        for (int j = -2; j <= 2; j++)
        {
            if (abs(i) + abs(j) <= 2)
            { // Condição para formar o losango
                if (x + i >= 0 && x + i < TAMANHO && y + j >= 0 && y + j < TAMANHO)
                {
                    tabuleiro[x + i][y + j] = 1;
                }
            }
        }
    }
}

int main()
{
    inicializarTabuleiro();

    // Testando as habilidades
    aplicarCone(2, 5);
    aplicarCruz(5, 5);
    aplicarOctaedro(7, 5);

    // Exibir tabuleiro final
    exibirTabuleiro();

    return 0;
}