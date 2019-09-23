#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

//Declara��o das fun��es.
int fat(int n);
int comb(int a, int b);

//argc �> � um valor inteiro que indica a quantidade de argumentos que foram passados ao chamar o programa.
//argv �> � um vetor de char que cont�m os argumentos, um para cada string passada na linha de comando.
//argv[0] -> armazena o nome do programa que foi chamado no prompt, sendo assim, argc � pelo menos igual a 1, pois no m�nimo existir� um argumento.

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

//Fun��o que realiza o c�lculo fatorial.
int fat(int n) { 
if(n == 0) 
return 1; 
else
return (n*fat(n-1)); 
}

//Fun��o que realizar o calculo com os fatorias de a e b.
int comb(int a, int b) {
return (fat(a) / (fat(b) * fat(a-b))); 
}

 


