#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	FILE *arquivo;
	arquivo = fopen("dados.txt", "w");
	
	if (arquivo == NULL) {
		printf("Erro ao carregar o arquivo :( ");
		return 0;
	}
	
	char nome[20];
	int matricula;
	char cadeira[20];
	
	printf("Digite seu Nome: ");
	scanf("%s", nome);
	
	printf("Digite a sua matricula: ");
	scanf("%d", &matricula);
	
	printf("Digite a sua disciplina: ");
	scanf("%s", cadeira);

	fprintf(arquivo, "Nome: %s \n", nome);
	fprintf(arquivo, "Matricula: %d \n", matricula);
	fprintf(arquivo, "Disciplina: %s", cadeira);
	fclose(arquivo);
	
	return 0;
}
