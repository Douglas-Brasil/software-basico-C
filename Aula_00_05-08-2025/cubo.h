#include <stdio.h>

void calculaCubo() {
    int num, cubo;
    

    printf("Cubo de um numero \n\n");
    printf("Digite o numero: ");
    scanf("%d", &num);

    cubo = num * num * num;

    printf("Cubo de %d = %d\n\n", num, cubo);
}
