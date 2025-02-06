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