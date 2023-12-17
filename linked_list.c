#include <stdlib.h>
#include <stdio.h>

typedef struct{
    void *next;
    int data;
}Node;


Node *head= NULL;

Node *adcNode(int data){
    Node *new = NULL;

    if(head==NULL){
        new = malloc(sizeof(Node));
        if(new == NULL) return NULL;

        new->data = data;
        head = new;
        new->next = NULL;
    }else{
        new = malloc(sizeof(Node));
        if(new == NULL) return NULL;

        new->data = data;
        new->next = head;
        head = new;

        return new;

    }
}

int rmvNode(int data){
    Node *current = head;
    Node *prev = head;
    while(current != NULL) if (current->data==data){
        if(current == head) {
            head = current->next;
        } else{
            prev->next = current->next;
            free(current);
            current =NULL;
        }
        return 1;
    }
    prev = current;
    current = current->next;
}

Node *inicNode(int data, int position){
    Node *current = head;
    while(current != NULL && position != 0) position--;
    if(position != 0){
        printf("Erro: Posicao nao suportada \n\n");
        return NULL;
    }
    Node *new = malloc(sizeof(Node));
    if (new == NULL) return new;

}


void printaListas(){
    Node *current = head;
    while(current != NULL){
        printf("\n\nA sua linha é: %d->", current->data);
        current = current->next;
    }
    printf("\n");
    return;
}


void printaMenu(){
    printf("\nSeja bem vindo a impressora de listas:\n\n\n");
    printf("\t1. Adicione um numero na lista; .\n\n");
    printf("\t2. Remova um numero na lista; .\n\n");
    printf("\t3. Insira um numero em posicao especifica; .\n\n");
    printf("\t4. Imprima sua lista; .\n\n");
    printf("\t5. Fechar; .\n");
    return;
}

int main(int argc,char **argv){
    int op = -1;
    int a1 = 0;
    int a2= 0;
    while (op != 5){
        printaMenu();
        int qtdNum = scanf("%d", &op);
        if(qtdNum == 1 && op >0 && op <= 5){
            switch(op){
                case 1:
                    printf("Qual numero quer inserir?\n");
                    scanf("%d", &a1);
                    Node *new = adcNode(a1);
                    break;
                case 2:
                    printf("Qual numero quer apagar? \n");
                    scanf("%d", &a2);
                    int result = rmvNode(a1);
                    if(!result) printf("not found");
                    break;
                case 3:
                    printf("Qual numero quer inserir?\n");
                    scanf("%d", &a1);
                    printf("Em qual posicao? \n");
                    scanf("%d",&a2);
                    new = inicNode(a1,a2);
                    if (new == NULL) printf("!...3RR0...!");
                    break;
                case 4:
                    printaListas();
                    break;
                case 5:
                    break;
            }
        }
    }
    return 0;
}