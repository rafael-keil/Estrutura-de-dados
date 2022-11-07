#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

int palindrome(char array[], int start, int finish)
{
    if (sizeof(array) <= 1)
    {
        return 1;
    }
    else if (tolower(array[start]) == tolower(array[finish]))
    {
        if (start >= finish)
        {
            return 1;
        }
        else
        {
            palindrome(array, start + 1, finish - 1);
        }
    }
    else
    {
        return 0;
    }
}

int main()
{
    setlocale(LC_ALL, "");
    int length;

    printf("\nDigite o tamanho da palavra: ");
    scanf("%d", &length);

    char word[length];

    printf("\nDigite uma palavra: ");
    scanf("%s", &word);

    if (palindrome(word, 0, length - 1) == 1)
    {
        printf("e palindromo!");
    }
    else
    {
        printf("nao e palindromo!");
    }
}