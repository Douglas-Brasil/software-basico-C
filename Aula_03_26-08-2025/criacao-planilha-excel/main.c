#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	FILE *arquivo;
	arquivo = fopen("planilha.csv", "a");
	
	if (arquivo == NULL) {
		printf("Erro ao carregar o arquivo :( ");
		return 0;
	}
	
	char nome[30];
	char cidade[20];
	char estado[20];
	
	printf("Digite o 1º nome: ");
	scanf("%s", nome);
	
	printf("Digite a 1º cidade: ");
	scanf("%s", cidade);
	
	printf("Digite o 1º estado: ");
	scanf("%s", estado);
	
	fprintf(arquivo, "Nome; Cidade; Estado; \n");
	fprintf(arquivo, "%s; %s; %s; \n", nome, cidade, estado);
	
	//----------------------------------------------------------
	
	printf("Digite o 2º nome: ");
	scanf("%s", nome);
	
	printf("Digite a 2º cidade: ");
	scanf("%s", cidade);
	
	printf("Digite o 2º estado: ");
	scanf("%s", estado);
	
	fprintf(arquivo, "%s; %s; %s; \n", nome, cidade, estado);
		
		
	//----------------------------------------------------------
	
	
	printf("Digite o 3º nome: ");
	scanf("%s", nome);
	
	printf("Digite a 3º cidade: ");
	scanf("%s", cidade);
	
	printf("Digite o 3º estado: ");
	scanf("%s", estado);

	fprintf(arquivo, "%s; %s; %s; \n", nome, cidade, estado);
	fclose(arquivo);
	
	return 0;
}
