/*
 *Alunos:
 *      Nome: Ian Batista Fornaziero / RA: 2677210
 *      Nome: Gabriel Augusto Dupim / RA: 2651408
 */

#ifndef FUNCOES_H
#define FUNCOES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//! Lista de filas
/*
! Esse é um arquivo header, apenas funções e structs.
! Se deseja a explicação dos exercícios, se direcione ao
! arquivo "funcoes.c".
*/
//? Exercicio 1

struct aluno
{
    int matricula;
    char nome[30];
    float n1;
};

struct elemento
{
    int num;
    struct aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elem;

struct fila
{
    struct elemento *inicio;
    struct elemento *final;
    int qtd;
};

typedef struct fila Fila;

Fila *criarFila();

typedef Elem *Pilha;

typedef struct fila Fila;

void liberaFila(Fila *fi); // libera a memória das filas

int insereFila(Fila *fi, struct aluno al); // enfileira um aluno

int consultaFila(Fila *fi, struct aluno *al); // consulta a fila de aluno

int filaVazia(Fila *fi); // um check se a fila está vazia

int filaSplit(Fila *f1, Fila *f2, int mat); // separa a fila de acordo com a matrícula

//? Exercicio 2

typedef struct ElemFila
{
    Fila *dados;
    struct ElemFila *prox;
} ElemFila;

typedef struct
{
    ElemFila *inicio;
    ElemFila *final;
    int qtd;
} FilaFilas;

FilaFilas *criaFilaDeFilas();

int insereFilaNaFila(FilaFilas *fila, Fila *fi); // enfileira uma fila

void liberaFilaFila(FilaFilas *fi); // libera a memória

typedef struct ElemFP
{
    Pilha *dados;
    struct ElemFP *prox;
} ElemFP;

typedef struct
{
    ElemFP *inicio;
    ElemFP *final;
    int qtd;
} FilaPilhas;

FilaPilhas *criaFilaDePilhas();

int inserePilhaNaFila(FilaPilhas *fila, Pilha *pi); // enfileira uma pilha

void liberaFilaPilha(FilaPilhas *fi); // libera a memória

typedef struct ElemPF
{
    Fila *dados;
    struct ElemPF *prox;
} ElemPF;

typedef struct
{
    ElemPF *topo;
} PilhaFilas;

PilhaFilas *criaPilhaDeFilas();

int pushFilas(PilhaFilas *pilha, Fila *fi); // empilha uma fila

//? Exercicio 3

Fila *criaFila();

int enfileira(Fila *F, int x);

int desenfileira(Fila *F, int *x);

Pilha *criaPilha();

int empilha(Pilha *P, int x);

int desempilha(Pilha *P, int *x);

int pilhaVazia(Pilha *P);

void inverteFila(Fila *F);

//? Exercicio 4

int furaFila(Fila *fi, struct aluno al); // fura a fila de acordo com o aluno

//? Exercicio 5

typedef struct aviao
{
    int id;
    char modelo[50];
    char companhia[50];
    struct aviao *prox;
} Aviao;

typedef struct
{
    Aviao *inicio;
    Aviao *final;
    int qtd;
} FilaAviao;

FilaAviao *criaFilaAviao();

int filaVaziaAviao(FilaAviao *fi);

int enfileiraAviao(FilaAviao *F, int id, char *modelo, char *companhia);

int desenfileiraAviao(FilaAviao *F);

int liberaFilaAviao(FilaAviao *fi);

void listarAvioes(FilaAviao *F); // checa se há um avião na lista de espera e retorna todos os dados de todos os aviões na fila

void listarPrimeiroAviao(FilaAviao *F); // checa o primeiro avião na espera e retorna os dados dele

//? Exercicio 6

void bubbleSortFila(); // ordena a fila de acordo com a matrícula do aluno

void filaCrescente(Fila *f1, Fila *f2, Fila *f3); // ordena a fila de acordo com a matrícula do aluno

//? Exercicio 7

void reverso(Fila *F); // inverte a fila

//? Exercicio 8

void comparaFila(Fila *f1, Fila *f2); // compara duas filas e coloca na terceira fila

void menu(Fila *f1, Fila *f2); // menu de opções para o usuário

//? Menu Principal
void menuPrincipal(); // menu principal

#endif