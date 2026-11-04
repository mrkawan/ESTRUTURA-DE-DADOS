#include <stdio.h>
#include <stdlib.h>


typedef struct No {
    int valor;
    struct No *proximo;
}No;

//Estrutura Pilha
typedef struct Pilha{
    No *topo;
}Pilha;

Pilha *criarPilha(){
    Pilha *pilha = (Pilha *)malloc(sizeof(Pilha));
    if (pilha == NULL)
    {
        printf("Erro ao alocar pilha");
        return NULL;
    }
    
    pilha->topo = NULL;
    return pilha;

}

//funcao empilhar
void empilhar (Pilha *pilha, int numero){
    No *novo_no = (No *)malloc(sizeof(No));

    if (novo_no == NULL)
    {
        printf("Erro ao alocar pilha");
        return;
    }
    
    novo_no->valor = numero; 
    novo_no->proximo = pilha->topo; //Faz o proximo do novo nó apontar para o nó que estava no topo
    pilha->topo = novo_no; //Atualiza o topo da pilha para o novo nó
}

//Funcao Imprimir
void imprimirPilha(Pilha *pilha){

    No *atual = pilha->topo;
    printf("\n ---- PILHA ------\n");
    while (atual != NULL)
    {
        printf("%d -> ", atual->valor);
        atual = atual->proximo;
    }
    printf("NULL \n");
}

void desempilhar(Pilha *pilha){

    if (pilha->topo == NULL)
    {
        printf("Pilha vazia!\n");
        return;
    }
    
    No *no_removido = pilha->topo;
    pilha->topo = pilha->topo->proximo;
    free(no_removido);
}


int pilhaVazia(Pilha *pilha) {
    return pilha->topo == NULL;
}

//Liberar pilha
void liberarPilha(Pilha *pilha){

    while (!pilhaVazia(pilha))
    {
        desempilhar(pilha);
    } 

    free(pilha);
}

int main(){

    Pilha *pilha = criarPilha();
    if (pilha == NULL)
    {
        return 1;
    }

    int opcao, numero;

    do
    {
        printf("\n----- MENU -----\n");
        printf("1 - Empilhar Elemento\n");
        printf("2 - Desempilhar\n");
        printf("3 - Verificar se a pilha esta vazia\n");
        printf("4- Imprimir pilha\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite o numero a ser empilhado: ");
            scanf("%d", &numero);
            empilhar(pilha, numero);
            break;

        case 2:
            desempilhar(pilha);
            break;

        case 3:
            pilhaVazia(pilha) ? printf("PILHA VAZIA!\n") : printf("PILHA COM ELEMENTOS!\n");
            break;

        case 4:
            imprimirPilha(pilha);
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