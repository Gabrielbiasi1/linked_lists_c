//
// CRIADOR E MANIPULADOR DE LISTAS EM C;
//



#include <stdio.h>2
#include <stdlib.h>


typedef struct {
    void *prox;
    int dados;
}Node;

Node *head = NULL;

//adiciona uma node a lista

Node *adNode(int dados){
    //Node de referencia, utilizada para reduzir run time e evitar erros;
    Node *novo = NULL;
    //2 casos:

    //lista vazia;
    if(head == NULL){
        Node *novo = malloc(sizeof (Node));
        if( novo == NULL)
            return NULL;
        novo->dados= dados;
        head = novo;
        novo->prox = NULL;
    } else {
        novo = malloc(sizeof (Node));
        if(novo == NULL)
            return NULL;
        novo->dados = dados;
        novo->prox = head;
        head = novo;
    }
    return novo;
}

//remove uma node da lista

int Rlista(int dados){
    Node *atual = head;
    Node *antes = head;
    while (atual != NULL){
        if (atual->dados == dados){
            if (atual == head)
            {
                head = atual->prox;
            } else {
                antes->prox = atual->prox;
            }
            return 1;
        }
    antes = atual;
    atual = atual->prox;
    }
return 0;
}

//insere node na lista
Node *InsNode (int dados, int posicao){
    Node *atual = head;
    while (atual != NULL && posicao != 0) posicao--;
    if(posicao != 0){ printf("Xiii, ta muito longe; \n"); return NULL;}

    Node *novo = malloc(sizeof (Node));
    if (novo == NULL) return NULL;

    novo->dados = dados;
    novo->prox = atual->prox;
    atual->prox = novo;

    return novo;
}

//printa a lista

void Plista(){
    Node *atual = head;
    while(atual != NULL){
        printf("\n(%d)", atual->dados);
        atual = atual->prox;
    }
    printf("\n");
    return;
}

void Menu(){
    printf("\n\n ________________Bem vindo ao sistemas de listas em C:________________ \n\n");

    printf("\n 1- Printa sua lista; \n");
    printf("\n 2- Adiciona uma Node a lista; \n");
    printf("\n 3- Remove uma Node da Lista; \n");
    printf("\n 4- Insere uma Node em uma posicao especifica da Lista; \n");
    printf("\n 5- Encerra as atividades; \n");
    return;
}



int main(int arg1, char **arg2){
    int entrada = -1;
    int a1 = 0, a2 = 0;
    while (entrada != 5){
        Menu();
        int ent_rec = scanf("%d", &entrada);
        if(ent_rec == 1 && entrada > 0 && entrada <= 5){
            switch (entrada) {
                case 1:
                    //printa a Lista
                    Plista();
                    break;

                case 2:
                    //adiciona
                    printf("Qual dado quer adicionar?\n ");
                    scanf("%d", &entrada);
                    Node *novo = adNode(entrada);
                    break;

                case 3:
                    //remove
                    printf("Qual dado quer remover?\n ");
                    scanf("%d", &a1);
                    int sucesso = Rlista(a1);
                    if(!sucesso)
                        printf("\n Nao conseguimos localizar esta node... \n");
                    break;

                case 4:
                    //insere
                    printf("Qual dado quer inserir?\n ");
                    scanf("%d", &a1);
                    printf("\n Qual posicao quer inserilo?\n");
                    scanf("%d", &a2);
                    novo = InsNode(a1,a2);
                    if(novo == NULL) printf("Falhamos na insercao! :( \n");
                    break;

                case 5:
                    //encerra
                    break;


            }
        }
    }
    Menu();
    return 0;


}