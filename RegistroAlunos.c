#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    int matricula;
    int idade;
    float n1;
	float n2;
    float media;

}TURMA;

void registra_aluno (TURMA tur[3]) {
    int i;

    for(i=0;i<3;i++){
        printf("Nome do aluno: \n");
        fflush(stdin);
		gets(tur[i].nome);

        printf("\nMatricula do %s: \n", tur[i].nome);
        scanf("%d",&tur[i].matricula);

        printf("\nIdade do %s: \n", tur[i].nome);
        scanf("%d",&tur[i].idade);

        printf("\nNota1 e Nota2 do %s: \n", tur[i].nome);
        scanf("%f %f",&tur[i].n1, &tur[i].n2);

        tur[i].media = ((tur[i].n1 + tur[i].n2)/2);

        printf("\n__________________\n");
    }
}

int aluno_aprovado (TURMA tur[3]) {
    int aprov = 0;
    int i;

    for(i=0;i<3;i++){
        if (tur[i].media >=7){
            aprov++;
        }
    }
    return aprov;
}

int aluno_reprovado (TURMA tur[3]) {
    int reprov = 0;
    int i;

    for(i=0;i<3;i++){
        if (tur[i].media <7){
            reprov++;
        }
    }
    return reprov;
}

float media_turma (TURMA tur[3]){
    int i;
    float media_geral=0;

    for(i=0;i<3;i++){
        media_geral = media_geral + tur[i].media;
    }
    return media_geral/i;
}

void maior_media (TURMA tur[3]){
    float maior = -9999999;
    int i, x;

    for(i=0; i<3; i++){
        if(maior < tur[i].media){
            maior = tur[i].media;
            x=i;
        }
    }
    printf("\n NOME: %s \n MATRICULA: %d \n IDADE: %d \n NOTA 1: %f \n NOTA 2: %f \n MEDIA: %f", tur[x].nome, tur[x].matricula, tur[x].idade, tur[x].n1, tur[x].n2, tur[x].media);
}

main(){
    TURMA tur[3];
    int op;
    registra_aluno(tur);

    printf("\n\nEscolha uma das opções abaixo: \n\n");
    printf("1: Mostrar aprovados\n");
    printf("2: Mostrar reprovados\n");
    printf("3: Mostrar media da turma\n");
    printf("4: Mostrar dados do aluno com maior media\n\n");
    scanf("%d", &op);

    switch(op){
        case 1:
            printf("\n Alunos aprovados: %d \n",aluno_aprovado(tur));
            break;
        case 2:
            printf("\nAlunos reprovados: %d \n",aluno_reprovado(tur));
            break;
        case 3:
            printf("\nMedia geral da turma: %f \n", media_turma(tur));
            break;
        case 4:
            maior_media(tur);
            break;

    }
}
