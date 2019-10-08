#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 10

void preencherVetor(int *v, int n){
	if(n>0){
		preencherVetor(v,n-1);
		v[n-1]=rand()%20;
	}
}

void exibirVetor(int *v, int n){
	if(n>0){
		exibirVetor(v,n-1);
		printf("%d\t",v[n-1]);
	}
}

void exibirParImparR(int *v, int n){
	if(n>0){
		if(v[n-1]%2 == 0){
			printf("%d\t",v[n-1]);
		}
		exibirParImparR(v,n-1);
		if(v[n-1]%2 != 0){
			printf("%d\t",v[n-1]);
		}
	}
}

int acharMaiorR(int *v, int n){
	if(n>1){
		int vemDeCima=acharMaiorR(v,n-1);
		if(vemDeCima > v[n-1])
			return vemDeCima;
		else
			return v[n-1];
	}
	return v[n-1];
}

int acharMaiorParR(int *v, int n){
	if(n>1){
		int vemDeCima=acharMaiorR(v,n-1);
		if(vemDeCima > v[n-1] && vemDeCima%2 ==0)
			return vemDeCima;
		else
			return v[n-1];
	}
	return v[n-1];
}

main (){
	int vetor[TAM];
	
	srand(time(NULL));
	preencherVetor(vetor,TAM);
	exibirVetor(vetor,TAM);
	exibirParImparR(vetor,TAM);
	printf("%d e a maior\n",acharMaiorR(vetor,TAM));
	printf("O maior valor par é:%d\n",acharMaiorParR(vetor,TAM));
}
