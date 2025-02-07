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

