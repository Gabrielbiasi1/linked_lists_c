#include<stdio.h>
#include<stdlib.h>
// funcoes listas encadeadas //

//-----------CRIAR Node-------------
typedef struct Node{
	int data;
	struct Node *prox;
}Node;
//---------------------------------------------

//-----------Criar a Lista-------
typedef struct{
	Node *head;
}

//aloca na head da lista
void apl_inic(Lista *lista,int dado){
	Node *new = (Node*)malloc(sizeof(Node));
		//pego o dado Node scanf e coloco ele la Node data
	new->data = dado;
		// eu pego o prox desse data que vai ser inserido e coloco pra onde o head estava apontando ou null ou pra outra
	new->prox = lista->head;
	  // agora eu eu transformo o head sendo new
	lista->head = new;
	
}
//cria dado no fim da lista
void apl_fim(Lista *lista,int dado){
	Node *Node,*new = (Node*)malloc(sizeof(Node));
	new->data= dado;
	new->prox= NULL;
	if(lista->head==NULL){
		lista->head= new;
	}
	else{
		Node = lista->head;
		while(Node->prox!=NULL){
			Node = Node->prox;
		}
		Node->prox = new;
	}
}
//inserir depois
void depois(Lista *lista, int dado, int y){
  Node *atual,*new = (Node*)malloc(sizeof(Node));
  new->data = dado;

  atual = lista->head;
  while(atual != NULL && atual->data != y){
    atual = atual->prox;
  }
  if(atual != NULL){
    new->prox = atual->prox;
    atual->prox = new;
  }
}

//imprime a lista 

void imprimir(Lista *lista){
	Node *head = lista->head;
	while(head!=NULL){
		printf("%d ",head->data);
		head = head->prox;
	}
	printf("\n\n");
}
//-----------------------------------------

//busca na lista
int bLista(Lista *lista, int dado) {
  Node *atual = lista->head;
  while (atual != NULL && atual->data != dado) {
    atual = atual->prox;
  }
  return atual != NULL;
}


//Inserir antes
void antes(Lista *lista, int dado, int y) {
    Node *new = (Node*)malloc(sizeof(Node));
    new->data = dado;

    if (lista->head == NULL) {
        new->prox = NULL;
        lista->head = new;
    } else {
        if (lista->head->data == y) {
            new->prox = lista->head;
            lista->head = new;
        } else {
            Node *prim = NULL;
            Node *atual = lista->head;

            while (atual != NULL && atual->data != y) {
                prim = atual;
                atual = atual->prox;
            }

            if (atual != NULL) {
                new->prox = atual;
                prim->prox = new;
            }
        }
    }
}
//remove dado //
void remover(Lista *lista,int dado){
	Node *head = lista->head;
	Node *temp = NULL;
	if(head!=NULL && lista->head->data==dado){
		temp = lista->head;
		lista->head=temp->prox;
	}
	else {
		while(head!= NULL && head->prox !=NULL && head->prox->data==dado){
			temp= head->prox;
			head->prox= temp->prox;
		}
	}
	if(temp!=NULL){
		free(temp);
		
			
	}
}
//inverter a lista //
void inverter(Lista *lista) {
  Node *atual = lista->head;
  Node *prim = NULL;
  Node *prox;

  while (atual != NULL) {
    prox = atual->prox;
    atual->prox = prim;
    prim = atual;
    atual = prox;
  }

  lista->head = prim;
}
// ordenar de forma crescente //
void cresc(Lista *lista,int dado){
	Node *aux,*new = malloc(sizeof(Node));
	new->data=dado;
	if(lista->head==NULL){
		new->prox=NULL;
		lista->head=new;
	}
	else if(new->data < lista->head->data){
		new->prox = lista->head;
		lista->head = new;
	}
	else{
		aux = lista->head;
		while(aux->prox && new->data > aux->prox->data){
			aux = aux->prox;
		}
		new->prox = aux->prox;
		aux->prox = new;
		 	
	}
}
//ordenar decrescente //
void decres(Lista *lista,int dado){
	Node *aux,*new = malloc(sizeof(Node));
	new->data=dado;
	if(lista->head==NULL){
		new->prox=NULL;
		lista->head=new;
	}
	else if(new->data > lista->head->data){
		new->prox = lista->head;
		lista->head = new;
	}
	else{
		aux = lista->head;
		while(aux->prox && new->data < aux->prox->data){
			aux = aux->prox;
		}
		new->prox = aux->prox;
		aux->prox = new;
		 	
	}
}


// Inserir em qualquer lugar:


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

//Main


int main(){
 //criar minha lista
 Lista lista;
 //setar minha lista inicalmente em Null 
 lista.head=NULL;
	int op, data,y;
	
	do{
		printf("1 - Inserir Node head\n2 - Imprimir\n3 - Inserir Node Final\n4 - Inserir depois Num\n5 - bLista NUmero\n6 - Inserir antes de um Num\n7 - Remover Item\n8 - Inverter a Lista\n9 - Inserir Ordenado\n10 - Ordenar decrescente\n11 - SAIR\n");
		scanf ("%d", &op);
		switch(op){
			//--------COLOCAR Node headOO
			case 1:
				printf("Qual data deseja Inserir:\n");
				scanf("%d",&data);
				apl_inic(&lista, data);
				break;
				
			//---------IMPRIMIR	
			case 2:
				imprimir(&lista);
				break;
				
			//-----------COLOCAR Node FIMMMMm	
			case 3:
				 printf("Qual data inserir Node Final:\n");
				 scanf("%d",&data);
				 apl_fim(&lista, data);
				 break;
				 	 
			//---------------- INSERIR DEPOIS DE UM NUMERO
			case 4:
				printf("Qual data deseja inserir:\n ");
				scanf("%d",&data);
				printf("data referente:\n");
				scanf("%d",&y);
				depois(&lista,data,y);
				break;
				
			//----------------bLista	
			case 5:
			      printf("Numero buscado:");
                   scanf("%d", &data);
                   if (bLista(&lista, data)) {
                   printf("O data %d encontrado\n", data);
                   } else {
                   printf("O data %d n�o encontrado\n", data);
                   }
                   break;
				   
			//-------------Inserir antes de um N
			case 6:
				  printf("insira o data:");
			       scanf("%d",&data);
			       printf("insira o data de referencia:");
			       scanf("%d",&y);
			       antes(&lista,data,y);
			       break;	
			
			//-------------REMOVER NUM
			case 7:
				printf(" data a ser removido:");
			        scanf("%d",&data);
			        remover(&lista,data);
			        break;
			//-------------INVERTER        
			case 8:
				 inverter(&lista);
        		 imprimir(&lista);
        		 break;
			//---------inserir ordenado crescente
			case 9:
				printf("insira o data:");
			    scanf("%d",&data);
			    cresc(&lista,data);
			    break;
			//----------inserir ordenado decrescente
			case 10:
				printf("insira o data:");
			    scanf("%d",&data);
			    decres(&lista,data);
			    break;
			
			//-------------SAIRR	
			case 11:
				printf("Finalizando...\n");
				break;
			default:
				printf("Comando Invalido\n");
				break;
				
		}
	}while(op !=11);
	
	
	return 0;
}
// Main sem Menu //
#include <stdio.h>
#include <stdlib.h>

// Estrutura de dados para a lista encadeada
struct Node {
    int data;
    struct Node* next;
};

// Função para criar uma nova lista encadeada
struct Node* createList() {
    int data;
    struct Node* head = NULL;

    // Leia os dados do usuário até que ele digite 0
    do {
        printf("Entre com um valor (0 para parar): ");
        scanf("%d", &data);

        // Cria uma nova celula para a lista
        struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = NULL;

        // Adiciona a celula à lista
        if (head == NULL) {
            head = newNode;
        } else {
            struct Node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
    } while (data != 0);

    return head;
}

// Função para imprimir a lista encadeada
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    // Cria uma nova lista encadeada
    struct Node* head = createList();

    // Imprime a lista encadeada
    printList(head);

    return 0;
}