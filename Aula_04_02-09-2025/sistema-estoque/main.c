#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h> // Inclua esta biblioteca para usar strcmp()

// A função menu() agora retorna um char
char menu();

int main(int argc, char *argv[]) {
	while (true) {
		char opcao = menu();
	
	    if (opcao == '1') {
			char produto[30];
			printf("Digite o nome do produto: ");
			scanf("%s", produto);
			
			cadastrar(produto);
			
	    } else if (opcao == '2') {
	        printf("editar");
	    } else if (opcao == '3') {
	        printf("deletar");
	    } else if (opcao == '4') {
	        printf("listar");
	    } else if (opcao == '0'){
	        printf("fechar sistema");
	        break;
	    }
	}
	
    return 0;
}

char menu() {
    char opcao[5];
    
    while (true) {
        printf("Menu: \n");
        printf("1. Cadastrar Produto \n");
        printf("2. Editar Produto \n");
        printf("3. Deletar Produto \n");
        printf("4. Listar Produtos \n");
        printf("0. Sair \n");
        printf("Escolha uma opcao: ");
        scanf("%s", opcao);
        
        if (strcmp(opcao, "1") == 0 || strcmp(opcao, "2") == 0 || strcmp(opcao, "3") == 0 ||
            strcmp(opcao, "4") == 0 || strcmp(opcao, "0") == 0) {
            
            return opcao[0];
            // O 'break' após 'return' é redundante e pode ser removido
        } else {
            printf("\nOpcao invalida, por favor escolha uma das opcoes do menu! \n");
        }
    }
}

FILE *criarOuCarregarArquivo(){
	FILE *arquivo;
	arquivo = fopen("estoque.txt", "a");
	return arquivo;
}
void fecharArquivo(FILE *arquivo){
	fclose(arquivo);
}

void cadastrar(char *produto) {
	FILE *arquivo = criarOuCarregarArquivo();
	fprintf(arquivo, "%s \n", produto);
	fecharArquivo(arquivo);
	printf("Produto cadastrado com sucesso. \n \n");
}


	
