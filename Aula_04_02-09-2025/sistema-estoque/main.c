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
	    	int existemProdutosNoEstoque = verificarSeExistemProdutosNoEstoque();	
	    	if (existemProdutosNoEstoque == 1) {
		    	char produto[100];
				printf("Digite o nome do produto que voce quer editar: ");
				scanf("%s", produto);
				editar(produto);
			} else {
				printf("Nao ha produtos no estoque. Primeiro cadastre pelo menos um. \n \n");
			}
			
	    } else if (opcao == '3') {
	    	int existemProdutosNoEstoque = verificarSeExistemProdutosNoEstoque();	
	    	if (existemProdutosNoEstoque == 1) {
		    	char produto[100];
		    	printf("Digite o nome do produto que voce quer deletar: ");
		    	scanf("%s", produto);
		    	deletar(produto);
	    	} else {
				printf("Nao ha produtos no estoque. Primeiro cadastre pelo menos um. \n \n");
			}
			
	    } else if (opcao == '4') {
	    	printf("\n \n");
	    	int existemProdutosNoEstoque = verificarSeExistemProdutosNoEstoque();	
	    	if (existemProdutosNoEstoque == 1) {
	        	listar();
	        } else {
				printf("Nao ha produtos no estoque. Primeiro cadastre pelo menos um. \n \n");
			}
			
	    } else if (opcao == '0'){
	        printf("Fechando sistema. . .");
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

int verificarSeExistemProdutosNoEstoque() {	
	FILE *arquivoEstoque = criarOuCarregarArquivo("estoque.txt", "r");
	char produtoLidoNoArquivo[100];
	
	if (fscanf(arquivoEstoque, "%s", produtoLidoNoArquivo) == 1) {
		fecharArquivo(arquivoEstoque);
		return 1;
	}
	
	fecharArquivo(arquivoEstoque);
	return 0;

}

bool verificarSeProdutoExiste(FILE *arquivoEstoque, char *produto) {
	char produtoLidoNoArquivo[100];
	
	while (fscanf(arquivoEstoque, "%s", produtoLidoNoArquivo) == 1) {
		if (strcmp(produtoLidoNoArquivo, produto) == 0) {
			return true;
		}
	}
	return false;
}

void sobrescreverProduto(FILE *arquivoEstoque, FILE *arquivoTemporario, char *produtoSobrescrever, char *novoProduto) {	
	char produtoLidoNoArquivo[100];
	
	while (fscanf(arquivoEstoque, "%s", produtoLidoNoArquivo) == 1) {
		if (strcmp(produtoLidoNoArquivo, produtoSobrescrever) == 0) {
			fprintf(arquivoTemporario, "%s\n", novoProduto);
		} else {
			fprintf(arquivoTemporario, "%s\n", produtoLidoNoArquivo);
		}
	}
	printf("Edicao salva com sucesso.");
}

void editar(char *produtoSobrescrever) {
    FILE *arquivoEstoque = criarOuCarregarArquivo("estoque.txt", "r");    
    char novoProduto[100];
    bool existe = verificarSeProdutoExiste(arquivoEstoque, produtoSobrescrever);
    
    if (existe) {
    	printf("Produto encontrado, qual o produto que vai ficar no lugar? ");
        scanf("%99s", novoProduto);
        rewind(arquivoEstoque);
        
        FILE *arquivoTemporario = criarOuCarregarArquivo("arquivoTemporario", "w");
        sobrescreverProduto(arquivoEstoque, arquivoTemporario, produtoSobrescrever, novoProduto);
        
        fecharArquivo(arquivoEstoque);
		fecharArquivo(arquivoTemporario); 
		
        remove("estoque.txt");
		rename("arquivoTemporario", "estoque.txt"); 
		
 
	} else {
		printf("Produto nao encontrado no estoque.");
	}
	
	printf("\n \n");
	fecharArquivo(arquivoEstoque);

}

void removerProduto (FILE *arquivoEstoque, FILE *arquivoTemporario, char *produtoDeletar) {
	char produtoLidoNoArquivo[100];
	
	while (fscanf(arquivoEstoque, "%s", produtoLidoNoArquivo) == 1) {
		if (strcmp(produtoLidoNoArquivo, produtoDeletar) != 0) {
			fprintf(arquivoTemporario, "%s\n", produtoLidoNoArquivo);
		}
	}
	
	printf("Remocao salva com sucesso.");
}

void deletar(char *produtoDeletar) {
	FILE *arquivoEstoque = criarOuCarregarArquivo("estoque.txt", "r");
	
	bool existe = verificarSeProdutoExiste(arquivoEstoque, produtoDeletar);
	
	if (existe) {
		rewind(arquivoEstoque);
		FILE *arquivoTemporario = criarOuCarregarArquivo("arquivoTemporario", "w");
		
		removerProduto(arquivoEstoque, arquivoTemporario, produtoDeletar);
		
		fecharArquivo(arquivoEstoque);
		fecharArquivo(arquivoTemporario);
		
		remove("estoque.txt");
		rename("arquivoTemporario", "estoque.txt");
		
	} else {
		printf("Produto nao encontrado no estoque");
	}
	printf("\n \n");
	
	fecharArquivo(arquivoEstoque);
}

void listar () {
	FILE *arquivoEstoque = criarOuCarregarArquivo("estoque.txt", "r");
	char produtoLidoNoArquivo[100];
	printf("----- Lista de Produtos no Estoque ----- \n");
	while (fscanf(arquivoEstoque, "%s", produtoLidoNoArquivo) == 1) {
		printf("%s\n", produtoLidoNoArquivo);
	}
	printf("---------------------------------------- \n");
	printf("Listagem concluida com sucesso. \n \n \n \n");
}






