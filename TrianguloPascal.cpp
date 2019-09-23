#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

//Declaração das funções.
int fat(int n);
int comb(int a, int b);

//argc –> é um valor inteiro que indica a quantidade de argumentos que foram passados ao chamar o programa.
//argv –> é um vetor de char que contém os argumentos, um para cada string passada na linha de comando.
//argv[0] -> armazena o nome do programa que foi chamado no prompt, sendo assim, argc é pelo menos igual a 1, pois no mínimo existirá um argumento.

int main(int argc, char *argv[]) {
int i=0, j=0, linha;

printf("Digite ate qual linha deseja visualizar:\n");
scanf("%d",&linha);

//Caso digite um valor acima de 12, os valores estouram, apresentando respostas erradas.
if(linha < 0) {
	printf("Numero invalido.\n");
}
else if (linha > 12) {
	printf("Numero muito elevado para o programa.\n");
}
else {
for(i = 0; i <= linha; i++) {
for(j = 0; j <= i; j++) {
printf("%4d",comb(i,j)); 
} 
printf("\n"); 
}
}
getch();
return 0;
}

//Função que realiza o cálculo fatorial.
int fat(int n) { 
if(n == 0) 
return 1; 
else
return (n*fat(n-1)); 
}

//Função que realizar o calculo com os fatorias de a e b.
int comb(int a, int b) {
return (fat(a) / (fat(b) * fat(a-b))); 
}

 


