#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	float peso;
	float altura;
	float imc;
	
	printf("Qual o seu peso? ");
	scanf("%f", &peso);
	printf("Qual a sua altura? ");
	scanf("%f", &altura);
	
	imc = peso/pow(altura,2);
	
	
	if (imc < 20) {
		printf("Seu IMC e %f e voce esta abaixo do do peso :(", imc);
	} else if (imc >= 20 && imc < 30){
		printf("Seu IMC e %f e voce esta no peso ideal :)) ", imc);
	} else if (imc >= 30 && imc < 35) {
		printf("Seu IMC e %f e voce esta obeso :(", imc);
	} else {
		printf("Seu imc e %f e voce esta muito obeso :((", imc);
	}
	return 0;
}
