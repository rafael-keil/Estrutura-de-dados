// 1 - B
//
// 2 -
//  2686680
//  12
//  13
//  2686676
//  144
//
// 3 -
#include <stdio.h>
#define TAM 4
main()
{
    int matriz[TAM][TAM] = {
        {5, 6, 10, 2},
        {1, 4, 3, 0},
        {0, 0, 6, 4},
        {2, 3, 4, 8},
    };
    int *p, i;
    int soma = 0;
    p = &matriz[0][0];

    for (i = 0; i < TAM * TAM; i++)
    {
        soma = soma + (*(p + i));
    }

    printf("A soma dos valores de toda a matriz é igual a %d.", soma);
    getchar();
}

// 4-
// 1 - 3 - 8 - 10 - 40 - 80

// 5 -
// ele imprime a lista de trás pra frente, até o paux for != null, impimindo:
// 1.5   1.2   1.0   1.3   1.8