#include <stdio.h>
#include <stdlib.h>

struct descritor_lista
{
    struct nodo *inicio;
    struct nodo *fim;
    int tamanho;
};
typedef struct descritor_lista TipoDescritorLista;

struct nodo
{
    float informacao;
    struct nodo *anterior;
    struct nodo *proximo;
};
typedef struct nodo TipoNodo;

void criar(TipoDescritorLista *descritor_lista)
{
    descritor_lista->inicio = NULL;
    descritor_lista->fim = NULL;
    descritor_lista->tamanho = 0;
}

void inserir(TipoDescritorLista *descritor_lista, float info)
{
    TipoNodo *novo = (TipoNodo *)malloc(sizeof(TipoNodo));
    novo->informacao = info;
    if (!descritor_lista->inicio)
    {
        novo->proximo = NULL;
        novo->anterior = NULL;
        descritor_lista->fim = novo;
    }
    else
    {
        novo->anterior = NULL;
        novo->proximo = descritor_lista->inicio;
        descritor_lista->inicio->anterior = novo;
    }
    descritor_lista->inicio = novo;
    descritor_lista->tamanho++;
}

float somar(TipoDescritorLista *descritor_lista)
{
    float acum = 0;

    if (descritor_lista->inicio == NULL)
        acum = 0;
    else
    {
        TipoNodo *paux;
        for (paux = descritor_lista->fim; paux != NULL; paux = paux->anterior)
        {
            acum = acum + paux->informacao;
        }
    }

    return acum;
}

int avaliar_listas(TipoDescritorLista *descritor_lista, TipoDescritorLista *descritor_lista2)
{
    float soma = 0, soma2 = 0;

    soma = somar(descritor_lista);
    soma2 = somar(descritor_lista2);

    if (soma >= soma2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    TipoDescritorLista *descritor_lista;
    descritor_lista = (TipoDescritorLista *)malloc(sizeof(TipoDescritorLista));
    criar(descritor_lista);
    inserir(descritor_lista, 10);
    inserir(descritor_lista, 10);
    inserir(descritor_lista, 10);
    inserir(descritor_lista, 10);
    inserir(descritor_lista, 10);

    TipoDescritorLista *descritor_lista2;
    descritor_lista2 = (TipoDescritorLista *)malloc(sizeof(TipoDescritorLista));
    criar(descritor_lista2);
    inserir(descritor_lista2, 1);
    inserir(descritor_lista2, 1);
    inserir(descritor_lista2, 1);
    inserir(descritor_lista2, 1);
    inserir(descritor_lista2, 1);

    printf("%d\t", avaliar_listas(descritor_lista, descritor_lista2));

    return 0;
}