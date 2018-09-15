#include <stdio.h>
#include <stdlib.h>

typedef struct Ficha{
    int info;
    struct Ficha *prox;
}No;

No *inicio, *fim, *aux, *novo;

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
        novo->prox=NULL;
    }else{
        novo->prox=inicio;
        inicio=novo;
    }
}

void RemoveInicio(){
    if(inicio!=NULL){
        if(inicio == fim){
            printf("Eliminando=%d\n",inicio -> info);
            free(inicio);
            inicio = fim = NULL;
        }
        else{
            aux = inicio;
            inicio = aux -> prox;
            printf("Eliminando=%d\n",aux -> info);
            free (aux);
        }
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

int main() {
    criar();
    int op;
    printf("\n------------------------------------------");
    printf("\n- 1 inserir                    -");
    printf("\n- 2 inserir fim                -");
    printf("\n- 3 imprimir                   -");
    printf("\n- 4 remover inicio             -");
    printf("\n- 5 remover fim                -");
    printf("\n- 6 inserir meio               -");
    printf("\n- 7 remover meio               -");
    printf("\n- 8 sair                       -");
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
                inserefim();
                break;
            case 3 :
                imprime();
                break;
            case 4 :
                RemoveInicio();
                break;
            case 5 :
                RemoveFim();
                break;
            case 6 :
                inserirMeio();
                break;
            case 7 :
                removeMeio();
                break;
            case 8 :
                system("EXIT");
                break;
            default :
                printf("inserção invalida");
        }
    }
    return 0;
}