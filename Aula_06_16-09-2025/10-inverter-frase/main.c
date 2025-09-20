#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
char inverterTexto(char *texto);

int main(int argc, char *argv[]) {
	char textoQueSeraInvertido[50];

	printf("Digite o texto que voce deseja inverter: ");
	fgets(textoQueSeraInvertido, sizeof(textoQueSeraInvertido), stdin);
	textoQueSeraInvertido[strcspn(textoQueSeraInvertido, "\n")] = 0;
	inverterTexto(textoQueSeraInvertido);
	
	return 0;
}

char inverterTexto(char *texto) {
    char **textoInvertido = NULL; // array de ponteiros para palavras
    int tamanhoLista = 0;

    // separa palavras por espaço
    char *palavra = strtok(texto, " ");
    while (palavra != NULL) {
        tamanhoLista++;
        textoInvertido = realloc(textoInvertido, tamanhoLista * sizeof(char *));
        textoInvertido[tamanhoLista - 1] = palavra;
        palavra = strtok(NULL, " ");
    }

    // imprime as palavras em ordem inversa
    printf("Frase invertida:\n");

    int i = tamanhoLista - 1; // Inicializa o contador fora do loop
    while (i >= 0) {
        printf("%s ", textoInvertido[i]);
        i--; // Decrementa o contador dentro do loop
    }

}
