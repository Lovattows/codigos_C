#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct nodo {
	int dado;
	struct nodo *prox;
}Celula;


Celula *inserirSimplesOrdenado(int valor, Celula *l) {
	Celula *novo, *p, *r;

	//alocar memoria
	novo = (Celula *)malloc(sizeof(Celula));

	//depositar valores
	novo->dado = valor;
	novo->prox = NULL; //se fosse circular seria diferente

	//percorrer lista
	if (!l) return novo;

	r = NULL;
	for (p = l; p; p = p->prox) {
		if (novo->dado < p->dado) {
			novo->prox = p;
			if (!r) {
				return novo;
			} else break;		
		}
		r = p;
	}

	//engatar o novo elemento
	r->prox = novo;

	return l;
}

void exibirSimples(Celula *l) {
	if(!l) printf("Lista vazia");
	
	else {
		for (;l; l = l->prox) {
			printf("%d\t",l->dado);
		}
		printf("\n");
	}
}

Celula *removerSimples(int valor, Celula *l){
    Celula *r, *p;

    for(r=NULL, p=l; p ; r=p, p= p->prox){
        if(valor == p->dado){
            break;
        }
    }

    if(!p){
        printf("dado nao localizado");
        return l;
    }

    if(!r)/*if(p == l) TESTE PARA SABER SE É O PRIMEIRO ELEMENTO*/{
        r=l;
        l = l->prox;
        free(r);
        return l;
    }else if(!p->prox){ //TESTE PARA SABER SE É O ultimo ELEMENTO
        r->prox = NULL;
        free(p);
    }else{
        r->prox = p->prox; //exclui o elemento do meio
        free(p);
    }
    return l;
}

int main() {
	Celula *lista = NULL;
	srand(time(NULL));
	int valor, i;
	int numeroRemove;
	//lista = inserirSimplesOrdenado (10, lista);
	//lista = inserirSimplesOrdenado (20, lista);
	//lista = inserirSimplesOrdenado (30, lista);
	for(i=0; i<4; i++){
	valor= rand()%20;
	lista = inserirSimplesOrdenado (valor, lista);
	}
	exibirSimples(lista);
	
	printf("Digite um numero para remover: ");
	scanf("%d", &numeroRemove);
	lista = removerSimples (numeroRemove, lista);
	exibirSimples (lista);

	lista = inserirSimplesOrdenado (5, lista);
	exibirSimples (lista);
	return 1;
}
