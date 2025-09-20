#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

FILE *criarOuCarregarArquivo(char *nomeArquivo, char *tipoLeitura){
	FILE *arquivo;
	arquivo = fopen(nomeArquivo, tipoLeitura);
	return arquivo;
}

int main(int argc, char *argv[]) {
    FILE *arquivo = criarOuCarregarArquivo("dados.txt", "r");

    int *listaDeNumerosLidos = NULL;
    int tamanhoLista = 0;
    int numero;
    int somaTotal = 0;
    int max, min;

    while (fscanf(arquivo, "%d", &numero) == 1) {
        tamanhoLista++;
        listaDeNumerosLidos = realloc(listaDeNumerosLidos, tamanhoLista * sizeof(int));
        if (listaDeNumerosLidos == NULL) {
            printf("Erro de memória!\n");
            exit(1);
        }

        listaDeNumerosLidos[tamanhoLista - 1] = numero;
        somaTotal += numero;

        if (tamanhoLista == 1) {
            max = min = numero; // inicializa com o primeiro número
        } else {
            if (numero > max) max = numero;
            if (numero < min) min = numero;
        }
    }

    fclose(arquivo);

    if (tamanhoLista > 0) {
        double media = (double)somaTotal / tamanhoLista;

        printf("\n--- Analise do Arquivo dados.txt ---\n");
        printf("Quantidade de numeros lidos: %d\n", tamanhoLista);
        printf("Soma Total: %d\n", somaTotal);
        printf("Media: %.2f\n", media);
        printf("Maior Valor: %d\n", max);
        printf("Menor Valor: %d\n", min);
    } else {
        printf("Nenhum número foi lido do arquivo.\n");
    }
    
    return 0;
}








