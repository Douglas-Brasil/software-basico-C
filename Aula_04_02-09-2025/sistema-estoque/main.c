#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h> 

char menu();

int main(int argc, char *argv[]) {
	while (true) {
		char opcao = menu();
	
	    if (opcao == '1') {
			char produto[100];
			printf("Digite o nome do produto: ");
			scanf("%s", produto);
			
			cadastrar(produto);
			
	    } else if (opcao == '2') {
	    	char produto[30];
			printf("Digite o nome do produto que voce quer editar: ");
			scanf("%s", produto);
			
			editar(produto);
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

FILE *criarOuCarregarArquivo(char *nomeArquivo, char *tipoLeitura){
	FILE *arquivo;
	arquivo = fopen(nomeArquivo, tipoLeitura);
	return arquivo;
}

void fecharArquivo(FILE *arquivo){
	fclose(arquivo);
}

void cadastrar(char *produto) {
	FILE *arquivo = criarOuCarregarArquivo("estoque.txt", "a+");
	fprintf(arquivo, "%s \n", produto);
	fecharArquivo(arquivo);
	printf("Produto cadastrado com sucesso. \n \n");
}

void editar(char *produto) {
    FILE *arquivo = criarOuCarregarArquivo("estoque.txt", "r");
    FILE *temp = criarOuCarregarArquivo("arquivoTemporario.txt", "w");
    char produtoLidoNoArquivo[100];
    bool encontrado = false;

    while (fscanf(arquivo, "%s", produtoLidoNoArquivo) == 1) {
        if (strcmp(produtoLidoNoArquivo, produto) == 0) {
            char novoProduto[100];
            printf("Produto encontrado, qual o produto que vai ficar no lugar? ");
            scanf("%99s", novoProduto);

            fprintf(temp, "%s\n", novoProduto); // escreve o novo produto
            encontrado = true;
        } else {
            fprintf(temp, "%s\n", produtoLidoNoArquivo); // mantém os antigos
        }
    }
    
    if (encontrado) {
    	printf("Edicao salva com sucesso.");
	} else {
		printf("Produto não encontrado no estoque.");
	}
	printf("\n \n");
    fclose(arquivo);
    fclose(temp);

    // substitui o original pelo temporário
    remove("estoque.txt");
    rename("arquivoTemporario.txt", "estoque.txt");
}








