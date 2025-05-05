/*
 *Alunos:
 *      Nome: Ian Batista Fornaziero / RA: 2677210
 *      Nome: Gabriel Augusto Dupim / RA: 2651408
 */

#include "funcoes.h"

//! Lista de filas
/*
! Neste arquivo estão as funções e as
! respectivas explicações dos exercícios.
*/

//? Exercicio 1
/*
Considerando filas, implemente um método que receba como parâmetro
a referência f1 e um valor de matrícula n e divida a fila em duas, de tal
forma que a segunda fila comece no primeiro nó logo após a primeira
ocorrência de n na fila original. Esse método deve ser da seguinte
assinatura:

    int separa(Fila f1, Fila f2, matricula n)

Dentro do método separa, a segunda fila deve ser apontada pela
referência f2, enquanto f1 deve continuar apontando para o início da fila
anterior.
*/

Fila *criaFila()
{
    Fila *fi = (Fila *)malloc(sizeof(Fila));
    if (fi != NULL)
    {
        fi->final = NULL;
        fi->inicio = NULL;
        fi->qtd = 0;
    }
    return fi;
}

void liberaFila(Fila *fi)
{
    if (fi != NULL)
    {
        Elem *no;
        while (fi->inicio != NULL)
        {
            no = fi->inicio;
            fi->inicio = fi->inicio->prox;
            free(no);
        }
        free(fi);
    }
}

int insereFila(Fila *fi, struct aluno al)
{
    if (fi == NULL)
        return 0;

    Elem *no = (Elem *)malloc(sizeof(Elem));

    if (no == NULL)
        return 0;

    no->dados = al;
    no->prox = NULL;

    if (fi->final == NULL) // fila vazia
        fi->inicio = no;
    else
        fi->final->prox = no;

    fi->final = no;
    fi->qtd++;
    return 1;
}

int removeFila(Fila *fi)
{
    if (fi == NULL)
        return 0;
    if (fi->inicio == NULL) // fila vazia
        return 0;
    Elem *no = fi->inicio;
    fi->inicio = fi->inicio->prox;
    if (fi->inicio == NULL) // fila ficou vazia
        fi->final = NULL;
    free(no);
    fi->qtd--;
    return 1;
}

int consultaFila(Fila *fi, struct aluno *al)
{
    if (fi == NULL)
        return 0;
    if (fi->inicio == NULL) // fila vazia
        return 0;
    *al = fi->inicio->dados;
    return 1;
}

int filaVazia(Fila *fi)
{
    if (fi == NULL)
        return 1;
    if (fi->inicio == NULL)
        return 1;
    return 0;
}

int filaSplit(Fila *f1, Fila *f2, int n)
{
    if (f1 == NULL || f2 == NULL)
        return 0;

    Elem *atual = f1->inicio;
    Elem *anterior = NULL;

    // Percorre a fila até encontrar a matrícula n
    while (atual != NULL && atual->dados.matricula != n)
    {
        anterior = atual;
        atual = atual->prox;
    }

    // Se não encontrou a matrícula n, retorna 0
    if (atual == NULL)
        return 0;

    // Ajusta a segunda fila para começar após a primeira ocorrência de n
    if (anterior != NULL)
    {
        f2->inicio = atual->prox;
        f2->final = f1->final;
        f1->final = anterior;
        anterior->prox = NULL;
    }
    else
    {
        // Caso especial: n está no início da fila
        f2->inicio = atual->prox;
        f2->final = f1->final;
        f1->inicio = NULL;
        f1->final = NULL;
    }

    return 1;
}

/*
 * Exercício feito em sala
 */

//? Exercicio 2
/*
Implemente as seguintes combinações de estruturas de dados com fila:
a. Uma fila de filas;
b. Uma fila de pilhas;
c. Uma pilha de filas;
*/

FilaFilas *criaFilaDeFilas()
{
    FilaFilas *fila = (FilaFilas *)malloc(sizeof(FilaFilas));
    if (fila != NULL)
    {
        fila->inicio = NULL;
        fila->final = NULL;
        fila->qtd = 0;
    }
    return fila;
}

int insereFilaNaFila(FilaFilas *fila, Fila *fi)
{
    if (fila == NULL || fi == NULL)
        return 0;

    ElemFila *no = (ElemFila *)malloc(sizeof(ElemFila));
    if (no == NULL)
        return 0;

    no->dados = fi;
    no->prox = NULL;

    if (fila->final == NULL)
    {
        fila->inicio = no;
    }
    else
    {
        fila->final->prox = no;
    }
    fila->final = no;
    fila->qtd++;
    return 1;
}

void liberaFilaFila(FilaFilas *fi)
{
    if (fi != NULL)
    {
        ElemFila *no;
        while (fi->inicio != NULL)
        {
            no = fi->inicio;
            fi->inicio = fi->inicio->prox;
            free(no);
        }
        free(fi);
    }
}

/*
 * Para o A do exercicio eu crio novas structs para definir o No das filas e uma para definir a fila de filas
 * E então, as próximas funções são iguais a de uma fila comum, só que utilizando filas invés disso
 */

FilaPilhas *criaFilaDePilhas()
{
    FilaPilhas *fila = (FilaPilhas *)malloc(sizeof(FilaPilhas));
    if (fila != NULL)
    {
        fila->inicio = NULL;
        fila->final = NULL;
        fila->qtd = 0;
    }
    return fila;
}

int inserePilhaNaFila(FilaPilhas *fila, Pilha *pi)
{
    if (fila == NULL || pi == NULL)
        return 0;

    ElemFP *no = (ElemFP *)malloc(sizeof(ElemFP));
    if (no == NULL)
        return 0;

    no->dados = pi;
    no->prox = NULL;

    if (fila->final == NULL)
    {
        fila->inicio = no;
    }
    else
    {
        fila->final->prox = no;
    }
    fila->final = no;
    fila->qtd++;
    return 1;
}

void liberaFilaPilha(FilaPilhas *fi)
{
    if (fi != NULL)
    {
        ElemFP *no;
        while (fi->inicio != NULL)
        {
            no = fi->inicio;
            fi->inicio = fi->inicio->prox;
            free(no);
        }
        free(fi);
    }
}

PilhaFilas *criaPilhaDeFilas()
{
    PilhaFilas *pilha = (PilhaFilas *)malloc(sizeof(PilhaFilas));
    if (pilha != NULL)
    {
        pilha->topo = NULL;
    }
    return pilha;
}

int pushFilas(PilhaFilas *pilha, Fila *fi)
{
    if (pilha == NULL || fi == NULL)
        return 0;

    ElemPF *no = (ElemPF *)malloc(sizeof(ElemPF));
    if (no == NULL)
        return 0;

    no->dados = fi;
    no->prox = pilha->topo;
    pilha->topo = no;
    return 1;
}

/*
 * A final de deixar o código mais limpo e menor
 * não estarei colocando no main o B e C, tendo em vista que são a mesma lógica do A
 * apenas foi adicionado duas novas structs, mudado o nome das funções e das variaveis utilizadas
 */

//? Exercicio 3
/*
Considere uma pilha P vazia e uma fila fi não vazia. Utilizando apenas
os testes de fila e pilha vazias, as operações Enfileira, Desenfileira,
Empilha, Desempilha, e uma variável aux inteira, escreva um programa
que inverte a ordem dos elementos da fila.
*/

int enfileira(Fila *fi, int x)
{
    if (fi == NULL)
        return 0;

    Elem *no = (Elem *)malloc(sizeof(Elem));
    if (no == NULL)
        return 0;

    no->num = x;
    no->prox = NULL;

    if (fi->final == NULL)
    {
        fi->inicio = no;
    }
    else
    {
        fi->final->prox = no;
    }
    fi->final = no;
    fi->qtd++;
    return 1;
}

int desenfileira(Fila *fi, int *x)
{
    if (fi == NULL || fi->inicio == NULL)
        return 0;

    Elem *no = fi->inicio;
    *x = no->num;
    fi->inicio = no->prox;
    if (fi->inicio == NULL)
        fi->final = NULL;
    free(no);
    fi->qtd--;
    return 1;
}

Pilha *criaPilha()
{
    Pilha *P = (Pilha *)malloc(sizeof(Pilha));
    if (P != NULL)
        *P = NULL;
    return P;
}

int empilha(Pilha *P, int x)
{
    if (P == NULL)
        return 0;

    Elem *no = (Elem *)malloc(sizeof(Elem));
    if (no == NULL)
        return 0;

    no->num = x;
    no->prox = *P;
    *P = no;
    return 1;
}

int desempilha(Pilha *P, int *x)
{
    if (P == NULL || *P == NULL)
        return 0;

    Elem *no = *P;
    *x = no->num;
    *P = no->prox;
    free(no);
    return 1;
}

int pilhaVazia(Pilha *P)
{
    return (P == NULL || *P == NULL);
}

void inverteFila(Fila *fi)
{
    if (fi == NULL || filaVazia(fi))
        return;

    Pilha *P = criaPilha();
    int aux;

    // fila para a pilha
    while (!filaVazia(fi))
    {
        desenfileira(fi, &aux);
        empilha(P, aux);
    }

    // pilha para a fila
    while (!pilhaVazia(P))
    {
        desempilha(P, &aux);
        enfileira(fi, aux);
    }

    free(P);
}

/*
 * Foi-se feito funções para criar a fila, a pilha e as funções para as manipular, sendo a enfileira,
 * desenfileira, empilha e desempilha, além de uma função para verificar se a pilha está vazia.
 * Depois, foi-se feito a função para inverter a fila, onde primeiro se desenfileira a fila para
 * empilhar a pilha e depois desempilhar a pilha para enfileirar na fila novamente.
 */

//? Exercicio 4
/*
Considere a implementação de filas usando a característica de filas
“circulares”, pesquise sobre o assunto. Escreva uma função
FuraFila(Fila* f, float x) que insere um item na primeira posição da fila. O
detalhe é que seu procedimento deve ser O(1), ou seja, não pode
movimentar os outros itens da fila. (observe que este neste caso,
estaremos desrespeitando o conceito de FILA – primeiro a entrar é o
primeiro a sair). Altere também a função de percorrer a Fila para que ela
se aproveite da característica da fila circular.
*/

int furaFila(Fila *fi, struct aluno al)
{
    if (fi == NULL)
        return 0;

    Elem *no = (Elem *)malloc(sizeof(Elem));

    if (no == NULL)
        return 0;

    no->dados = al;
    no->prox = fi->inicio;
    fi->inicio = no;

    if (fi->final == NULL)
    {
        fi->final = no;
    }
    fi->qtd++;
    return 1;
}

/*
 * A função vai receber a fila a ser furada e o elemento a furar, no caso como a fila é de alunos, vai ser um aluno
 * na função então, ele vai definir um no, então vai definir que o proximo do no vai ser o antigo primeiro
 * para então, colocar o novo elemento no inicio e caso a fila esteja vazia ele também será o último da fila.
 */

//? Exercicio 5
/*
Escreva um programa que simule o controle de uma pista de decolagem
de aviões em um aeroporto. Neste programa, o usuário deve ser capaz
de realizar as seguintes tarefas:
a) Listar o número de aviões aguardando na fila de decolagem;
b) Autorizar a decolagem do primeiro avião da fila;
c) Adicionar um avião à fila de espera;
d) Listar todos os aviões na fila de espera;
e) Listar as características do primeiro avião da fila.
*/

FilaAviao *criaFilaAviao()
{
    FilaAviao *fi = (FilaAviao *)malloc(sizeof(FilaAviao));
    if (fi != NULL)
    {
        fi->inicio = NULL;
        fi->final = NULL;
        fi->qtd = 0;
    }
    return fi;
}

int filaVaziaAviao(FilaAviao *fi)
{
    if (fi == NULL)
        return 1;
    if (fi->inicio == NULL)
        return 1;
    return 0;
}

int enfileiraAviao(FilaAviao *fi, int id, char *modelo, char *companhia)
{
    if (fi == NULL)
        return 0;

    Aviao *no = (Aviao *)malloc(sizeof(Aviao));
    if (no == NULL)
        return 0;

    no->id = id;
    strcpy(no->modelo, modelo);
    strcpy(no->companhia, companhia);
    no->prox = NULL;

    if (fi->final == NULL)
    {
        fi->inicio = no;
    }
    else
    {
        fi->final->prox = no;
    }
    fi->final = no;
    fi->qtd++;
    return 1;
}

int desenfileiraAviao(FilaAviao *fi)
{
    if (fi == NULL || fi->inicio == NULL)
        return 0;

    Aviao *no = fi->inicio;
    fi->inicio = no->prox;
    if (fi->inicio == NULL)
        fi->final = NULL;
    free(no);
    fi->qtd--;
    return 1;
}

int liberaFilaAviao(FilaAviao *fi)
{
    if (fi != NULL)
    {
        Aviao *no;
        while (fi->inicio != NULL)
        {
            no = fi->inicio;
            fi->inicio = fi->inicio->prox;
            free(no);
        }
        free(fi);
    }
    return 1;
}

void listarAvioes(FilaAviao *fi)
{
    if (fi == NULL || fi->inicio == NULL)
    {
        printf("\nNenhum aviao na fila de espera.\n");
        return;
    }

    Aviao *no = fi->inicio;
    printf("\nAvioes na fila de espera:\n");
    while (no != NULL)
    {
        printf("\nID: %d, \nModelo: %s, \nCompanhia: %s\n", no->id, no->modelo, no->companhia);
        no = no->prox;
    }
}

void listarPrimeiroAviao(FilaAviao *fi)
{
    if (fi == NULL || fi->inicio == NULL)
    {
        printf("\nNenhum aviao na fila de espera.\n");
        return;
    }

    Aviao *no = fi->inicio;
    printf("\nPrimeiro aviao na fila:\n");
    printf("\nID: %d, \nModelo: %s, \nCompanhia: %s\n", no->id, no->modelo, no->companhia);
}

/*
 * Foi feito dois structs, um para definir um avião qualquer e suas características e outro para definir
 * uma fila de aviões.
 * Depois, foram feitas as funções para criar a fila, enfileirar, desenfileirar e listar os aviões e
 * listar o primeiro avião. Com uma checagem para verificar se há um avião na lista de espera de decolagem e,
 * caso sim, lista as características do avião na lista de espera ou o primeiro avião.
 */

//? Exercicio 6
/*
Implemente um método que receba três filas, duas já preenchidas em
ordem crescente e preencha a última com os valores das duas primeiras
em ordem crescente.
*/

void bubbleSortFila(Fila *fi)
{
    if (fi == NULL || fi->inicio == NULL)
        return;

    int troca;
    Elem *ptr1;
    Elem *ptr2 = NULL;

    do
    {
        troca = 0;
        ptr1 = fi->inicio;

        while (ptr1->prox != ptr2)
        {
            if (ptr1->dados.matricula > ptr1->prox->dados.matricula)
            {
                struct aluno temp = ptr1->dados;
                ptr1->dados = ptr1->prox->dados;
                ptr1->prox->dados = temp;

                troca = 1;
            }
            ptr1 = ptr1->prox;
        }
        ptr2 = ptr1;
    } while (troca);
}

void filaCrescente(Fila *f1, Fila *f2, Fila *f3)
{
    if (f1 == NULL || f2 == NULL || f3 == NULL)
        return;

    Elem *no = f1->inicio;
    struct aluno al;

    while (no != NULL)
    {
        al = no->dados;
        insereFila(f3, al);
        no = no->prox;
    }

    no = f2->inicio;

    while (no != NULL)
    {
        al = no->dados;
        insereFila(f3, al);
        no = no->prox;
    }

    bubbleSortFila(f3);
}

/*
 * Ele vai receber as 3 filas como pede o exercicio e vai preencher a fila 3 com os elementos
 * da fila 1 e 2, aí ele vai para a função de bubble sort e nessa função ele vai percorrer a
 * lista trocando os valores para que fique de forma crescente por matricula, saindo do
 * loop quando não realizar nenhuma troca, ou seja, ordenado corretamente.
 */

//? Exercicio 7
/*
Implemente a função reverso, que reposiciona os elementos na fila de
tal forma que o início da fila torna-se o final, e vice-versa.
*/

void reverso(Fila *fi)
{
    if (fi == NULL || filaVazia(fi))
        return;

    Elem *antes = NULL, *atual = fi->inicio, *depois = NULL;

    fi->final = fi->inicio;

    while (atual != NULL)
    {
        depois = atual->prox;
        atual->prox = antes;
        antes = atual;
        atual = depois;
    }

    fi->inicio = antes;
}

/*
 * Foi-se feito uma função que percorre a fila, trocando os ponteiros de cada
 * elemento para o anterior (bubble sort). No final, o primeiro elemento da
 * fila se torna o último e o último se torna o primeiro.
 */

//? Exercicio 8
/*
Faça um programa que apresente um menu contínuo com as seguintes
opções e execute de acordo com a escolha do usuário.
void menu()
{
printf("1-Inicializa fila.\n");
printf("2-Verifica se a fila é vazia.\n");
printf("3-Verifica se a fila é cheia.\n");
printf("4-Enfileira o elemento na fila.\n");
printf("5-Desefileira elemento da fila.\n");
printf("6-Le o número no início da fila.\n");
printf("7-Testar qual fila possui mais elementos .\n");
printf("8-Furar a fila .\n");
printf("9-Sair.\n");
}
*/

void comparaFila(Fila *f1, Fila *f2)
{
    if (f1->qtd > f2->qtd)
    {
        printf("Fila 1 e maior");
    }
    else if (f1->qtd < f2->qtd)
    {
        printf("Fila 2 e maior");
    }
    else if (f1->qtd == f2->qtd)
    {
        printf("Fila de mesmo tamanho");
    }
}

void menu(Fila *f1, Fila *f2)
{
    int continuar = 1;
    int escolha;
    struct aluno aln;
    Elem *no;
    Fila *fila;

    do
    {
        printf("[1] - Inicializa fila.\n");
        printf("[2] - Verifica estado da fila.\n");
        printf("[3] - Enfileira o elemento na fila.\n");
        printf("[4] - Desefileira elemento da fila.\n");
        printf("[5] - Le o numero no inicio da fila.\n");
        printf("[6] - Testar qual fila possui mais elementos .\n");
        printf("[7] - Furar a fila .\n");
        printf("[0] - Sair.\n");
        printf("\nEscolha o que deseja: ");
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
            fila = criaFila();
            if (fila != NULL)
            {
                printf("\nFila criada.");
            }
            break;
        case 2:
            if (filaVazia(fila) == 1)
                printf("\nFila vazia.\n");
            else
                printf("\nFila nao vazia.\n");
            break;
        case 3:
            printf("\nInsira a matricula do aluno: ");
            scanf("%d", &aln.matricula);
            getchar();
            printf("\nAgora insira o nome do aluno: ");
            scanf("%[^\n]", aln.nome);
            printf("\nAgora a nota do aluno: ");
            scanf("%f", &aln.n1);
            insereFila(fila, aln);
            break;
        case 4:
            removeFila(fila);
            break;
        case 5:
            no = fila->inicio;
            printf("\nOs dados iniciais da fila sao: \n");
            printf("\nMatricula: %d\n", no->dados.matricula);
            printf("\nNome: %s\n", no->dados.nome);
            printf("\nNota: %.2f\n", no->dados.n1);
            break;
        case 6:
            comparaFila(f1, f2);
            break;
        case 7:
            printf("\nInsira a matricula do aluno a furar fila: ");
            scanf("%d", &aln.matricula);
            getchar();
            printf("\nAgora insira o nome do aluno a furar fila: ");
            scanf("%[^\n]", aln.nome);
            printf("\nAgora a nota do aluno a furar fila: ");
            scanf("%f", &aln.n1);
            furaFila(fila, aln);
            break;
        case 0:
            printf("\nSaindo...");
            continuar = 0;
            break;
        default:
            printf("\nOpcao invalida...");
            break;
        }

    } while (continuar);
}

/*
 * A função vai receber as duas filas para comparação
 * e vai fazer o que cada menu diz puxando as funções respectivas.
 * OBS: Tiramos o verificar se fila é cheia, pois como é dinâmica, não tem como encher.
 */

//? Menu Principal para acessar as questões:

void menuPrincipal()
{
    int opcao = 9;

    do
    {
        printf("\n\n\tMenu dos Exercicios\n");
        printf("[1] - Exercicio 1 (Separar filas).\n");
        printf("[2] - Exercicio 2 (Fila de filas, fila de pilhas, pilha de filas).\n");
        printf("[3] - Exercicio 3 (Inverter ordem da fila usando pilha).\n");
        printf("[4] - Exercicio 4 (Filas Circulares).\n");
        printf("[5] - Exercicio 5 (Aeroporto).\n");
        printf("[6] - Exercicio 6 (Ordem crescente).\n");
        printf("[7] - Exercicio 7 (Inverter fila).\n");
        printf("[8] - Exercicio 8 (Menu de fila).\n");
        printf("[0] - Sair.\n");
        printf("\nDigite uma opcao: ");
        scanf("%d", &opcao);

        printf("\n");

        // Definindo os alunos
        struct aluno a[4] = {{2, "Andre", 9.5f},
                             {4, "Ricardo", 7.5f},
                             {1, "Bianca", 9.7f},
                             {3, "Ana", 5.7f}};

        struct aluno a2[4] = {{2, "Ian", 9.5f},
                              {5, "Gabriel", 7},
                              {9, "Caio", 10},
                              {10, "Gustavo", 4}};

        switch (opcao)
        {
        //? Exercício 1 (Separar filas)
        case 1:
        {
            Fila *f1 = criaFila();
            Fila *f2 = criaFila();

            printf("\tExercicio 1\n\n");

            // Insere os alunos na fila 1
            for (int i = 0; i < 4; i++)
            {
                insereFila(f1, a[i]);

                if (filaVazia(f1))
                    printf("Erro!!!!!!\n");
            }

            Elem *no = f1->inicio;

            // Imprime os alunos da fila 1
            printf("Fila 1:\n");
            while (no != NULL)
            {
                printf("Matricula: %d\n", no->dados.matricula);
                printf("Nome: %s\n", no->dados.nome);
                printf("Notas: %.2f\n", no->dados.n1);
                printf("-------------------------------\n");
                no = no->prox;
            }

            // Separação das filas
            filaSplit(f1, f2, 1); // separa a fila 1 e 2, sendo a matricula 3 o divisor
            printf("\nFila 1 e 2 separadas com a matricula 3:\n");

            printf("\nFila 1:\n");
            no = f1->inicio;
            while (no != NULL)
            {
                printf("Matricula: %d\n", no->dados.matricula);
                printf("Nome: %s\n", no->dados.nome);
                printf("Notas: %.2f\n", no->dados.n1);
                printf("-------------------------------\n");
                no = no->prox;
            }

            printf("\nFila 2:\n");
            no = f2->inicio;
            while (no != NULL)
            {
                printf("Matricula: %d\n", no->dados.matricula);
                printf("Nome: %s\n", no->dados.nome);
                printf("Notas: %.2f\n", no->dados.n1);
                printf("-------------------------------\n");
                no = no->prox;
            }

            // libera tudo
            liberaFila(f1);
            liberaFila(f2);
        }
        break;

        //? Exercício 2 (fila de filas)
        case 2:
        {
            printf("\n\tExercicio 2\n\n");

            Fila *f1 = criaFila();
            Fila *f2 = criaFila();

            // Insere os alunos na fila 1
            for (int i = 0; i < 4; i++)
            {
                insereFila(f1, a[i]);

                if (filaVazia(f1))
                    printf("Erro!!!!!!\n");
            }

            // Insere os alunos na fila 2
            for (int i = 0; i < 4; i++)
            {
                insereFila(f2, a2[i]);

                if (filaVazia(f2))
                    printf("Erro!!!!!!\n");
            }

            // Criar fila de filas
            FilaFilas *ff = criaFilaDeFilas();

            // Inserir as filas na fila de filas
            insereFilaNaFila(ff, f1);
            insereFilaNaFila(ff, f2);

            // Print da fila de filas
            printf("Fila de filas:\n");
            ElemFila *noFila = ff->inicio;
            while (noFila != NULL)
            {
                printf("Fila:\n");
                Elem *noElem = noFila->dados->inicio;
                while (noElem != NULL)
                {
                    printf("Matricula: %d\n", noElem->dados.matricula);
                    printf("Nome: %s\n", noElem->dados.nome);
                    printf("Notas: %.2f\n", noElem->dados.n1);
                    printf("-------------------------------\n");
                    noElem = noElem->prox;
                }
                noFila = noFila->prox;
            }

            // libera tudo
            liberaFila(f1);
            liberaFila(f2);
            liberaFilaFila(ff);
        }
        break;

        //? Exercício 3 (Inverter fila)
        case 3:
        {
            printf("\n\tExercicio 3\n\n");

            Fila *f5 = criaFila();

            // enfileira 10 elementos
            for (int i = 0; i < 10; i++)
            {
                enfileira(f5, i);

                if (filaVazia(f5))
                    printf("Erro!!!!!!\n");
            }

            printf("Fila original:\n");
            Elem *no = f5->inicio;

            while (no != NULL)
            {
                printf("Nº %d ", no->num);
                no = no->prox;
            }

            inverteFila(f5);

            printf("Fila invertida:\n");
            Elem *noInv = f5->inicio;

            while (noInv != NULL)
            {
                printf("Nº %d ", noInv->num);
                noInv = noInv->prox;
            }

            liberaFila(f5);
        }
        break;

        //? Exercício 4 (Filas Circulares)
        case 4:
        {
            printf("\n\tExercicio 4\n\n");

            Fila *f1 = criaFila();

            // Insere os alunos na fila 1
            for (int i = 0; i < 4; i++)
            {
                insereFila(f1, a[i]);

                if (filaVazia(f1))
                    printf("Erro!!!!!!\n");
            }

            Elem *no = f1->inicio;

            // Imprime os alunos da fila 1
            while (no != NULL)
            {
                printf("Matricula: %d\n", no->dados.matricula);
                printf("Nome: %s\n", no->dados.nome);
                printf("Notas: %.2f\n", no->dados.n1);
                printf("-------------------------------\n");
                no = no->prox;
            }

            struct aluno a3[1] = {{9, "Eduardo", 8}}; // aluno que vai furar a fila
            furaFila(f1, a3[0]);                      // fura a fila

            // Imprime os alunos da fila 1 após um ter furado a fila:
            while (no != NULL)
            {
                printf("Matricula: %d\n", no->dados.matricula);
                printf("Nome: %s\n", no->dados.nome);
                printf("Notas: %.2f\n", no->dados.n1);
                printf("-------------------------------\n");
                no = no->prox;
            }
        }
        break;

        //? Exercício 5 (Aeroporto)
        case 5:
        {
            printf("\n\tExercicio 5\n\n");

            FilaAviao *f6 = criaFilaAviao();
            int op, id;
            char modelo[50], companhia[50];

            do
            {
                system("cls");
                printf("\n\tTorre de controle:\n");
                printf("[1] - Listar numero de avioes aguardando na fila.\n");
                printf("[2] - Autorizar decolagem do primeiro aviao.\n");
                printf("[3] - Adicionar um aviao a fila de espera.\n");
                printf("[4] - Listar todos os avioes na fila de espera.\n");
                printf("[5] - Listar as caracteristicas do primeiro aviao.\n");
                printf("[0] - Sair.\n");
                printf("Digite uma opcao: ");
                scanf("%d", &op);

                switch (op)
                {
                case 1:
                    printf("\nNumero de avioes aguardando na fila: %d\n", f6->qtd);
                    break;

                case 2:
                    if (desenfileiraAviao(f6))
                    {
                        printf("\nDecolagem autorizada para o primeiro aviao.\n");
                    }
                    else
                    {
                        printf("\nNenhum aviao na fila para decolagem.\n");
                    }
                    break;

                case 3:
                    printf("\nDigite o ID do aviao: ");
                    scanf("%d", &id);
                    printf("\nDigite o modelo do aviao: ");
                    scanf("%s", modelo);
                    printf("\nDigite a companhia aerea: ");
                    scanf("%s", companhia);
                    if (enfileiraAviao(f6, id, modelo, companhia))
                    {
                        printf("\nAviao adicionado a fila de espera.\n");
                    }
                    else
                    {
                        printf("\nErro ao adicionar aviao...\n");
                    }
                    break;

                case 4:
                    listarAvioes(f6);
                    break;

                case 5:
                    listarPrimeiroAviao(f6);
                    break;

                case 0:
                    printf("\nSaindo...\n");
                    break;

                default:
                    printf("\nOpcao invalida...\n");
                }
            } while (op != 0);

            liberaFilaAviao(f6);
        }
        break;

        //? Exercício 6 (Ordem crescente)
        case 6:
        {
            printf("\n\tExercicio 6\n\n");

            Fila *f2 = criaFila();
            Fila *f3 = criaFila();
            Fila *f4 = criaFila();

            // Insere os alunos na fila 2
            for (int i = 0; i < 4; i++)
            {
                insereFila(f2, a[i]);

                if (filaVazia(f2))
                    printf("\nErro!!!!!!\n");
            }

            // Insere os alunos na fila 3
            for (int i = 0; i < 4; i++)
            {
                insereFila(f3, a2[i]);

                if (filaVazia(f3))
                    printf("\nErro!!!!!!\n");
            }

            filaCrescente(f3, f2, f4);

            Elem *no = f4->inicio;

            while (no != NULL)
            {
                printf("Matricula: %d\n", no->dados.matricula);
                printf("Nome: %s\n", no->dados.nome);
                printf("Notas: %.2f\n", no->dados.n1);
                no = no->prox;
            }
        }
        break;

        //? Exercício 7 (Inverter fila)
        case 7:
        {
            printf("\n\tExercicio 7\n\n");

            Fila *f7 = criaFila();
            Elem *no = f7->inicio;

            for (int i = 0; i < 10; i++)
            {
                enfileira(f7, i);

                if (filaVazia(f7))
                    printf("\nErro!!!!!!\n");
            }

            printf("\nFila original:\n");
            while (no != NULL)
            {
                printf("Nº %d ", no->num);
                printf("\n-------------------------------\n");
                no = no->prox;
            }

            reverso(f7);

            printf("\nFila invertida:\n");
            while (no != NULL)
            {
                printf("Nº %d ", no->num);
                printf("\n-------------------------------\n");
                no = no->prox;
            }

            liberaFila(f7);
        }
        break;

        //? Exercício 8 (Menu de fila)
        case 8:
        {
            printf("\n\tExercicio 8\n\n");

            Fila *f1 = criaFila();
            Fila *f2 = criaFila();

            // Insere os alunos na fila 1
            for (int i = 0; i < 4; i++)
            {
                insereFila(f1, a[i]);

                if (filaVazia(f1))
                    printf("\nErro!!!!!!\n");
            }

            // Insere os alunos na fila 2
            for (int i = 0; i < 4; i++)
            {
                insereFila(f2, a2[i]);

                if (filaVazia(f2))
                    printf("\nErro!!!!!!\n");
            }

            menu(f1, f2);
        }
        break;
        }
    } while (opcao != 0);
}