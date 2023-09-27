#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char titulo[50];
    char autor[50];
    int edicao;
    int codigo;
    int comprimento;

} Livro;

typedef struct node
{
    Livro *livros;
    int espacoOcupado;
    int qtdLivros;
    struct node *proxPrateleira;
} Prateleira;

typedef struct estante
{
    Prateleira *inicioPrateleiras;
    struct estante *proxEstante;
} Estante;

typedef struct
{
    Estante *inicio;
} Inicio;

int criarEstante(Inicio *estante)
{
    estante->inicio = NULL;
    return 1;
}

Estante *adicionarEstante(Estante *estante)
{
    if (estante == NULL)
    {
        Estante *novaEstante = malloc(sizeof(Estante));
        novaEstante->inicioPrateleiras = malloc(sizeof(Prateleira));
        novaEstante->inicioPrateleiras->espacoOcupado = 0;
        novaEstante->inicioPrateleiras->qtdLivros = 0;
        novaEstante->inicioPrateleiras->proxPrateleira = NULL;
        novaEstante->inicioPrateleiras->livros = NULL;
        novaEstante->proxEstante = NULL;
        return novaEstante;
    }
    estante->proxEstante = adicionarEstante(estante->proxEstante);
    return estante;
}
int ehVazia(Estante estante)
{
    return (estante.inicioPrateleiras == NULL);
}

int inserirLivro(Estante *estante, Livro livro)
{
}

int main()
{
    Inicio estantes;
    criarEstante(&estantes);
    estantes.inicio = adicionarEstante(estantes.inicio);
}
