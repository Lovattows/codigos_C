#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Declara��o da fun��o Torre de Hanoi
int torrehanoi(int n, char p1, char p2, char p3){
	
    if (n == 1) {
       printf("O disco %d � movimentado do pilar %c para o pilar %c.\n", n, p1, p2);
    }
	else {
       torrehanoi(n - 1, p1, p3, p2);
       printf("O disco %d � movimentado do pilar %c para o pilar %c.\n", n, p1, p2);
       torrehanoi(n - 1, p3, p2, p1);
	}
}
int main(){
	
    int discos;
    
    setlocale(LC_ALL, "Portuguese");
    printf("Digite o n�mero de discos desejados: \n");
    scanf("%d", &discos);
    
	//Aqui a fun��o torrehanoi � chamada e executa todo o processo
    torrehanoi(discos, 'A', 'B', 'C');
    
    printf("Movimentos finalizados.");
    
    return 0;
  }
