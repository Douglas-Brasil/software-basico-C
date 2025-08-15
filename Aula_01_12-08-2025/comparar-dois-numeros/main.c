#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int numero_1;
	int numero_2;
	
	printf("Digite o primeiro numero: ");
	scanf("%d", &numero_1);

	printf("Digite o segundo numero: ");
	scanf("%d", &numero_2);
	
	printf("\n");
	int resultado = comparacao(numero_1, numero_2);
	
	/* o valor do resultado será 0 apenas se os 2 números fornecidos forem iguais :) */
	if (resultado == 0) {
		printf("Os numeros sao iguais! ");
	}
	else{
		printf("%d", resultado);
	}
	
	return 0;
}
