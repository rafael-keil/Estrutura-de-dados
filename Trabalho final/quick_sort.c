#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100000
#define RAND_NUMBER 1000000

// Algoritmo que utiliza a estratégia do quicksort para ordenar o vetor.
void quickSort(int *array, int left, int right)
{
    // Inicia variaveis
    int newLeft, newRight, pivot, temp;

    // Define a posição inicial como base e o pivô
    newLeft = left;
    newRight = right;
    pivot = array[(left + right) / 2];

    // Executa até que newLeft e newRigth se encontrem
    while (newLeft <= newRight)
    {
        // Procura o primeiro valor da esquerda pra direita que é menor que o valor do pivô
        while (array[newLeft] < pivot && newLeft < right)
        {
            newLeft++;
        }

        // Procura o primeiro valor da direita pra esquerda que é maior que o valor do pivô
        while (array[newRight] > pivot && newRight > left)
        {
            newRight--;
        }

        // Se o valor do newLeft for menor que o newRight, significando que estão na ordem incorreta
        if (newLeft <= newRight)
        {
            // Troca os valores das posições newLeft e newRight de lugar
            temp = array[newLeft];
            array[newLeft] = array[newRight];
            array[newRight] = temp;

            // Pula ambos pro próximo index do array
            newLeft++;
            newRight--;
        }
    }

    // Verifica se o ultimo valor do newRight continua depois do "início" da execução atual e chama uma nova, passando ela como o novo "fim"
    if (newRight > left)
    {
        quickSort(array, left, newRight);
    }

    // Verifica se o ultimo valor do newRight continua antes do "fim" da execução atual e chama uma nova, passando ela como o novo "início"
    if (newLeft < right)
    {
        quickSort(array, newLeft, right);
    }
}

// Função que cria os valores de modo aleatório para o vetor que deseja-se ordenar
void buildArray(int array[])
{
    int i;
    srand(time(NULL));

    for (i = 0; i < SIZE; i++)
    {
        array[i] = rand() % (RAND_NUMBER + 1);
    }
}

// Função que imprime os valores do vetor
void printArray(int array[], char *msg)
{
    int i;
    printf("*********** %s ***********\n", msg);

    for (i = 0; i < SIZE; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n");
}

int main()
{
    // Iniciando variaveis
    clock_t start, finish;
    double diferenca;

    // Construindo vetor
    int array[SIZE];
    buildArray(array);

    // Para imprimir o vetor desorganizado descomente a seguinte linha
    // printArray(array, "Vetor desorganizado")

    // Chamando função de organizar o vetor, guardando o tempo inicial e final
    start = clock();
    quickSort(array, 0, SIZE - 1);
    finish = clock();

    // Imprimindo o tempo de execução
    diferenca = finish - start;
    printf("Tempo em ms: %10.4f", diferenca / (CLOCKS_PER_SEC / 1000));

    // Para imprimir o vetor organizado descomente a seguinte linha
    // printArray(array, "Vetor organizado")
}