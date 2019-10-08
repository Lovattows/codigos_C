#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct nodo {
	int dado;
	struct nodo *prox;
} Celula;

Celula *inserirC(int valor, Celula *l) {
	Celula *novo, *p, *r;

	//alocar memória
	novo = (Celula *)malloc(sizeof(Celula));
	//depositar valores
	novo->dado = valor;
	novo->prox = novo;
	//eh o primeiro
	if (!l) return novo;

	//percorrer
	for(r = NULL, p = l; p->prox != l; r = p, p = p->prox) {
		if (valor < p->dado) break;
	}
	//descobrir por que parou o for
	if (valor > p->dado) {//
		p->prox = novo;
		novo->prox = l;
	} else if (!r) { //inicio
		novo->prox = l;
		for (;p->prox != l; p = p->prox);
		p->prox = novo;
		return novo;
	} else if (p->prox != l || valor < p->dado) {
		r->prox = novo;
		novo->prox = p;
	}
	return l;
}

void exibirC(Celula *l) {
	Celula *p;
	if (!l) {
		printf("Lista Circular Vazia\n");
		return;
	}
	for (p = l; p->prox != l; p = p->prox) {
		printf("%d\t", p->dado);
	}	
	printf("%d\n", p->dado);
}

Celula *removerC(int valor, Celula *l) {
	Celula *p, *r;
	if (!l) return NULL;

	for(r = NULL, p = l; p->prox != l; r = p, p = p->prox) {
		if (valor == p->dado) break;
	}
	if (valor != p->dado) return l;

	if (!r) { //inicio
		l = l->prox;
		if (!l) {
			return NULL;
		}
		r = p;
		for (p = l;p->prox != r; p = p->prox);
		p->prox = l;
		free(r);
	} else if (p->prox != l) {
		r->prox = p->prox;
		free(p);
	} else {
		r->prox  = l;
		free(p);
	}
	return l;
}

int main() {
	Celula *listaC = NULL;
	int numero,num;
	int i;
	srand(time(NULL));
	for (i = 0; i < 5; i++) {
		numero = rand() % 50;
		printf("%d\t",numero);
		listaC = inserirC(numero, listaC);
	}
	//exibirR(listaC);
	printf("\nInforme um numero para remover: ");
	scanf("%d", &num);

	listaC = removerC(num, listaC);
	exibirC(listaC);
	return 1;
}
