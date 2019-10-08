#include <stdio.h>
#include <stdlib.h>

void fibonacci(int pen, int ult, int n){
	if(n>2){
		printf("%d\t",pen+ult);
		fibonacci(ult,pen+ult,n-1);
	}
}

int main (){
	printf("\t1\t");
	fibonacci(0,1,18);
}
