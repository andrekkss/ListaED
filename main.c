#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct Ficha{
    int info;
    struct Ficha *prox;
}No;

No *inicio, *fim, *aux, *aux2, *novo;

void criar(){
    inicio=fim=NULL;
}

void insereinicio(){
    int valor;
    printf("Digite o valor: ");
    scanf("%d",&valor);

    novo = (No*)malloc(sizeof(No));
    novo -> info=valor;
    if(inicio==NULL){
        inicio=fim=novo;
        fim > inicio;
        novo->prox=NULL;
    }else{
        novo->prox=inicio;
        inicio=novo;
        fim=inicio;
    }
}

void RemoveInicio(){
    if(inicio!=NULL){
            aux = inicio;
            aux2 = fim;
            inicio = aux -> prox;
            fim = aux2 -> prox;
            printf("Eliminando inicio=%d\n",aux -> info);
            printf("Eliminando fim=%d\n",aux2 -> info);
            free(aux);
            free(aux2);
    }
    else{
        printf("lista vazia\n");
    }
}


void inserirMeio(){
    int valor, ref,flag = 0;

    printf("Digite a referência:   ");
    scanf("%d",&ref);

    aux = inicio;

    while (aux->info!=ref && aux!=NULL){
        aux = aux->prox;
    }
    if(aux->info==ref){
        flag = 1;

        if(flag == 1){
            printf("Digite um valor:");
            scanf("%d",&valor);
            novo = (No*)malloc(sizeof(No));
            novo->info=valor;

            novo->prox = aux->prox;
            aux->prox = novo;

            int aux1;

            printf("Deseja inserir depois ou antes da referência : %d ?\n\n 1- Antes   2- Depois",&ref);
            scanf("%d",&aux1);
            do{
                if(aux1 == 1){

                    int controle;
                    controle=aux->info;
                    aux->info=novo->info ;
                    novo->info = controle;
                    printf("Ficha inserida!\n\n");
                    getch();
                }else if(aux1 == 2){
                    printf("Ficha inserida!\n\n");
                    getch();
                }
            }while(ref != 1 && ref != 2);
        }else{
            printf("Elemento não encontrado");
        }
    }
}

void removeMeio(){
    int ref,flag = 0;
    No *aux2;
    printf("Digite o valor a ser eliminado");
    scanf("%d",&ref);
    aux = inicio;
    while(aux->info !=ref && aux!=fim)
        aux = aux->prox;
    if(aux->info==ref)
        flag=1;
    if(flag==1){
        aux2=aux->prox;
        printf("Eliminando = %d",aux->info);
        aux->info = aux2->info;
        printf("passei 1");
        aux->prox = aux2->prox;
        printf("passei 2");
        free(aux2);
        printf("passei free");
    }else
        printf("Valor não encontrado!");
}

void imprime(){
    aux = inicio;
    aux2 = fim;
    while(aux != NULL){
        printf("inicio: %d\n",aux -> info);
        aux = aux -> prox;
    }
    while(aux2 != NULL){
        printf("fim: %d\n",aux2 -> info);
        aux2 = aux2 -> prox;
    }
    getch();
}

int main() {
    criar();
    int op;
    printf("\n--------------------------------");
    printf("\n- 1 inserir                    -");
    printf("\n- 2 imprimir                   -");
    printf("\n- 3 remover                    -");
    printf("\n- 4 inserir meio               -");
    printf("\n- 5 remover meio               -");
    printf("\n- 6 sair                       -");
    printf("\n--------------------------------");

    while(op!=4){
        printf("\n\nDigite o valor do menu: ");
        scanf("%d",&op);

        printf("\n");

        switch(op){
            case 1 :
                insereinicio();
                break;
            case 2 :
                imprime();
                break;
            case 3 :
                RemoveInicio();
                break;
            case 4 :
                inserirMeio();
                break;
            case 5 :
                removeMeio();
                break;
            case 6 :
                system("EXIT");
                break;
            default :
                printf("inserção invalida");
        }
    }
    return 0;
}