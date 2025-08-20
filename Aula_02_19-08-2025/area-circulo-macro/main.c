#include <stdio.h>
#include <stdlib.h>
#define pi 3.14

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	float raioCirculo = 10;
	float areaCirculo = pi*pow(raioCirculo, 2);
	
	printf("A area do circulo e: %f", areaCirculo);
	return 0;
}
