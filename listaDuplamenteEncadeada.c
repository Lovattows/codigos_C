#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct nodo {
	int dado;
	struct nodo *ant, *prox;
} CelulaD;

CelulaD *inserirD(int valor, CelulaD *l) {
	CelulaD *novo, *p, *r;

	//alocar memoria
	novo = (CelulaD *)malloc(sizeof(CelulaD));

	//depositar valores
	novo->dado = valor;
	novo->ant = NULL;
	novo->prox = NULL;

	//percorrer a lista

	//1o - verificar se eh o primeiro elemento
	if (!l) return novo;

	//2o - posiciona l no inicio da lista
	for (;l->ant; l = l->ant);

	//3o - percorrer até o final
	for (r =NULL , p = l ;p; r=p, p = p->prox){
        if(valor < p->dado) break;
	} //aqui é colocado o código para inserir ordenado

    if(!r) { //primeiro
        novo->prox = p;
        p->ant = novo;
        return novo;
    }
    r->prox = novo; //no final e no meio
    novo->ant = r;
    if (p){ // no meio
        novo->prox = p;
        p->ant = novo;
    }
	return l;
}

void exibirD(CelulaD *l) {
	if (!l) printf("\nLista vazia\n");
	else {
		//posiciona l no inicio da lista
		for (;l->ant; l = l->ant);

		//percorre a lista exibindo
		for(;l; l = l->prox) {
			printf("%d\t", l->dado);
		}

		printf("\n");
	}
}

int contaNosD(CelulaD *l) {
	int qtd = 0;

	if (!l) return qtd;

	//posiciona l no início da lista
	for (; l->ant; l = l->ant);

	for (; l; l = l->prox, qtd++);

	return qtd;
}

CelulaD *elementoMeioD(CelulaD *l) {
	int qtd = contaNosD(l);

	if (qtd < 3) {
		printf("Quantidade de nós menor que 3. Sem meio.\n");
		return NULL;
	}

	//posiciona l no início da lista
	for (; l->ant; l = l->ant);

	//posiciona l no meio da lista
	for (qtd/=2; qtd > 0; l = l->prox, qtd--);

	return l;
}

CelulaD *retiraUltimoElementoD(CelulaD *l) {
	if (!l) return l;

	if (!l->ant && !l->prox) { //somente um elemento
		free(l);
		return NULL;
	}

	for (;l->prox->prox; l = l->prox);

	free(l->prox);
	l->prox = NULL;

	return l;
}

CelulaD *removerD(int valor, CelulaD *l){
    CelulaD *p, *r;

    if (!l) {
            printf("LISTA DUPLA VAZIA!\n");
    return;
    }

    for (;l->ant; l = l->ant);

    for (r =NULL , p = l ;p; r=p, p = p->prox){
        if(valor == p->dado){
            if(!r){ //primeiro
                l=l->prox;
                l->ant = NULL;

            }else if(!p->prox){ //fim
                r->prox = NULL;
            }else { //meio
                r->prox = p->prox;
                p->prox->ant = r;
            }
            free(p);
        }
	}
    return l;
}

int main() {
	int tamanhoLista;
	int numeroSorteado;
	int i;
	int numero;
	CelulaD *lista = NULL;
	CelulaD *meio;

	srand(time(NULL)); //para gerar a semente do sorteio

	tamanhoLista = rand() % 50; //sortear numeros entre 0 - 9

	//popular a lista duplamente encadeada
	for (i = 0; i < tamanhoLista; i++) {
		numeroSorteado = rand() % 100;
		lista = inserirD(numeroSorteado,lista);
	}
	exibirD(lista);

	printf("Digite um numero a ser removido: ");
    scanf("%d", &numero);

    lista =removerD(numero, lista);
     exibirD(lista);

	printf("Quantidade elementos: %d\n", contaNosD(lista));
	meio = elementoMeioD(lista);

	if (meio) printf("Elemento do meio: %d\n", meio->dado);

	//lista = retiraUltimoElementoD(lista);
	//printf("Nova lista\n");
	//exibirD(lista);

	return 1;
}

