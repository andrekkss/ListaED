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