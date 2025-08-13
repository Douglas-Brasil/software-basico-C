#include "cubo.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int op; 
    
    do {
        calculaCubo(); 
        printf("Deseja calcular outro valor do cubo? 1-Sim ou 0-Nao\n");
        scanf("%d", &op);
    } while (op == 1);

    printf("Finalizando o programa......\n");
    return 0;
}
