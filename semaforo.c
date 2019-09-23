#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h> 
#define N 3

sem_t exclusao_mutua;
sem_t espera_vaga;
sem_t espera_dado;
int buffer[N];
int proxima_insercao = 0;
int proxima_remocao = 0;

void* produtor(void* nome) {
    int i = 0;
    for (;;) {
        sem_wait(&espera_vaga);
        sem_wait(&exclusao_mutua);
        buffer[proxima_insercao] = 1;
        proxima_insercao = (proxima_insercao + 1) % N;
        printf("\nProdutor");
        for (i = 0; i < N; i++) {
            printf("%d ", buffer[i]);
        }
        sem_post(&exclusao_mutua);
        sem_post(&espera_dado);
    }
    pthread_exit(0);
}

void* consumidor(void* nome) {
    int i = 0;
    for (;;) {
        sem_wait(&espera_dado);
        sem_wait(&exclusao_mutua);
        buffer[proxima_remocao] = 0;
        proxima_remocao = (proxima_remocao + 1) % N;
        printf("\nConsumidor:");
        for (i = 0; i < N; i++) {
            printf("%d ", buffer[i]);
        }
        sem_post(&exclusao_mutua);
        sem_post(&espera_vaga);
    }
    pthread_exit(0);
}

int main() {
    pthread_t thUm, thDois;

    sem_init(&exclusao_mutua, 0, 1);
    sem_init(&espera_vaga, 0, N);
    sem_init(&espera_dado, 0, 0);

    pthread_create(&thUm, NULL, produtor, "Um");
    pthread_create(&thDois, NULL, consumidor, "Dois");

    pthread_join(thUm, NULL);
    pthread_join(thDois, NULL);

    sem_destroy(&exclusao_mutua);
    sem_destroy(&espera_vaga);
    sem_destroy(&espera_dado);

    return 0;
}