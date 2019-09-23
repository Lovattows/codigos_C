#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<pthread.h>

#define N 5
#define PENSAR 0
#define FOME 1
#define COMER 2
#define ESQUERDA (nfilosofo+4)%N
#define DIREITA (nfilosofo+1)%N

void *filosofo(void *num);
void agarraGarfo(int);
void deixaGarfo(int);
void testar(int);

sem_t mutex;
sem_t S[N];
int estado[N];
int nfilosofo[N]={0,1,2,3,4};

void *filosofo(void *num){
	while(1){
		int *i = num;
		sleep(1);
		agarraGarfo(*i);
		sleep(1);
		deixaGarfo(*i);
	}
}

void agarraGarfo(int nfilosofo){
	sem_wait(&mutex);
	estado[nfilosofo] = FOME;
	printf("Filosofo %d esta com fome.\n", nfilosofo+1);
	testar(nfilosofo);
	sem_post(&mutex);
	sem_wait(&S[nfilosofo]);
	sleep(1);
}

void deixaGarfo(int nfilosofo){
	sem_wait(&mutex);
	estado[nfilosofo]=PENSAR;
	printf("Filosofo %d largou os garfos %d e %d.\n", nfilosofo+1, ESQUERDA+1, nfilosofo+1);
	printf("Filosofo %d esta pensando.\n", nfilosofo+1);
	testar(ESQUERDA);
	testar(DIREITA);
	sem_post(&mutex);
}

void testar(int nfilosofo){
	if(estado[nfilosofo]==FOME && estado[ESQUERDA] !=COMER && estado[DIREITA]!=COMER){
		estado[nfilosofo]=COMER;
		sleep(2);
		printf("Filosofo %d pegou os garfos %d e %d.\n", nfilosofo+1, ESQUERDA+1, nfilosofo+1);
		printf("Filosofo %d esta comendo.\n", nfilosofo+1);
		sem_post(&S[nfilosofo]);
	}
}

int main() {
	int i;
	pthread_t thread_id[N];

		sem_init(&mutex,0,1);
	
		for(i=0;i<N;i++){
			sem_init(&S[i],0,0);
		}

		for(i=0;i<N;i++){
			pthread_create(&thread_id[i], NULL, filosofo, &nfilosofo[i]);
			printf("Filosofo %d esta pensando.\n",i+1);
		}

		for(i=0;i<N;i++){
			pthread_join(thread_id[i],NULL);
		}

	return(0);
}
