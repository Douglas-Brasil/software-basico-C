#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int numero;
	
	printf("Digite um numero: ");
	scanf("%d", &numero);
	
	if (numero > 0) {
		printf("O numero e positivo \n");
	} else if (numero < 0) {
		printf("O numero e negativo \n");
	} else {
		printf("O numero e 0 \n");
	}
	
	if (numero % 2 == 0) {
		printf("O numero e par");
	} else {
		printf("O numero e impar");
	}
	
	return 0;
}
