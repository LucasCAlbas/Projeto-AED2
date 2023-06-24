#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "raylib.h"

typedef struct no
{
    int id, quantidade;
    char *descricao;
    char *nome;
    struct no *ant;
    struct no *prox;
} No;

typedef struct
{
    No *inicio;
    No *fim;
    int tam;
} Lista;

void cria(Lista *l);
int insere(Lista *l, int id, int quantidade, const char *descricao, const char *nome);
int retira(Lista *l, int id);
int estaVazia(Lista l);

void moveBola(Vector2 *ballPosition);
void janelaPrincipal(Vector2 ballPosition);
void janelaMenu(int *seleciona, Lista l);
