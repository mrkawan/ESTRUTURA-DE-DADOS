#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *proximo;
}No;

//Estrutura Fila
typedef struct fila {
    No *inicio;
    No *fim;
}Fila;

Fila *criarFila(){

    Fila * fila = (Fila*)malloc(sizeof(Fila));
    if (fila == NULL)
    {
        printf("Erro ao alocar \n");
        return NULL;
    }

    fila->inicio = NULL;
    fila->fim = NULL;
    return fila;
}

void enfileirar(Fila *fila, int numero){

    No *novo_no = (No*)malloc(sizeof(No));

    if (novo_no == NULL)
    {
        printf("ERRO NA ALOCACAO \n");
        return;
    }
    
    novo_no->valor = numero;
    novo_no->proximo = NULL;

    if (fila->fim == NULL)
    {
        //Se a fila estiver vazia, o novo nó será o primeiro.
        fila->inicio = novo_no;
        fila->fim = novo_no;

    }else{
        //Se a fila não estiver vazia, adiciono o novo nó no final
        fila->fim->proximo = novo_no; //Faz o próximo do ultimo nó apontar para o novo nó!
        fila->fim = novo_no; //Atualiza o fim da fila para o novo nó!
    }
}

int desenfileirar(Fila *fila){

    if (fila->inicio == NULL)
    {
        printf("FILA VAZIA!! \n");
        return -1;
    }

    No *no_removido = fila->inicio;
    int valor = no_removido->valor;
    fila->inicio = fila->inicio->proximo;
    
    if (fila->inicio == NULL)
    {
        //Se a fila ficar vazia, atualizo o fim, para parar quando a lista esvaziar, 
        fila->fim = NULL;
    }

    free(no_removido);
    return valor;
}

void imprimirFila(Fila *fila){

    No *atual = fila->inicio;
    printf("\n ---- FILA ------\n");
    while (atual != NULL)
    {
        printf("%d -> ", atual->valor);
        atual = atual->proximo;
    }
    printf("NULL \n");
}

int filaVazia(Fila *fila){
    return fila->inicio == NULL;
}

void liberarFila(Fila *fila){

    while (!filaVazia(pilha))
    {
        desenfileirar(fila);
    } 

    free(fila);
}


int main(){

    Fila *fila = criarPilha();
    if (fila == NULL)
    {
        return 1;
    }

    int opcao, numero;

    do
    {
        printf("\n----- MENU -----\n");
        printf("1 - Enfileirar Elemento\n");
        printf("2 - Desenfileirar\n");
        printf("3 - Verificar se a fila esta vazia\n");
        printf("4 - Imprimir fila\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite o numero a ser empilhado: ");
            scanf("%d", &numero);
            empilhar(fila, numero);
            break;

        case 2:
            desenfileirar(fila);
            break;
            
        case 3:
            filaVazia(fila) ? printf("FILA VAZIA!\n") : printf("FILA COM ELEMENTOS!\n");
            break;

        case 4:
            imprimirFila(fila);
            break;

        case 0:
            printf("SAINDO DO PROGRAMA");
            break;
                    
        default:
            break;
        }


    } while (opcao != 0);
    
    
    return 0;
}