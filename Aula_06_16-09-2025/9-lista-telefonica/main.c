#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char menu();
char **listaTelefonica = NULL; // agora é matriz de strings
int tamanhoLista = 0;

int main(int argc, char *argv[]) {
	while (true) {
		char opcao = menu();
	
	    if (opcao == '1') {
			char nome[20];
			char numero[20];
			
			printf("--- Adicionar Novo Contato --- \n");
			printf("Digite o nome: ");
			scanf("%19s", nome);
			printf("Digite o telefone: ");
			scanf("%19s", numero);
			
			// aumenta espaço (2 strings por contato: nome + telefone)
			tamanhoLista += 2;
	        listaTelefonica = realloc(listaTelefonica, tamanhoLista * sizeof(char*));

	        // copia as strings
	        listaTelefonica[tamanhoLista - 2] = strdup(nome);
	        listaTelefonica[tamanhoLista - 1] = strdup(numero);
	        
	        printf("Contato adicionado!\n\n");
        	
	    } else if (opcao == '2') {
	    	printf("--- Lista de Contatos --- \n");
		    int i = 0;
		    
		    while (i < tamanhoLista) {
		        printf("Indice: %d | Nome: %s | Telefone: %s\n", i/2, listaTelefonica[i], listaTelefonica[i+1]);
		        i += 2; 
		    }
			printf("\n");
			
	    } else if (opcao == '3') {
	    	char buscarPeloNome[30];
	    	bool encontrado = false;
	    	printf("Qual o nome do contato que deseja buscar? ");
	    	scanf("%29s", buscarPeloNome);

		    int i = 0; 
		    
		    while (i < tamanhoLista) {
		        if (strcmp(listaTelefonica[i], buscarPeloNome) == 0) {
		            encontrado = true;
		            printf("Indice: %d | Nome: %s | Telefone: %s\n", i/2, listaTelefonica[i], listaTelefonica[i+1]);
		        }
		        i += 2; 
		    }
			if (!encontrado) {
				printf("Contato não encontrado! \n");
			}
			printf("\n");
			
	    } else{
	        printf("Fechando sistema. . .\n");
	        break;
	    }
	}
	
    return 0;
}

char menu() {
    char opcao[5];
    
    while (true) {
        printf("Agenda de Contatos \n");
        printf("1. Adicionar Contato \n");
        printf("2. Listar Contatos \n");
        printf("3. Buscar Contato \n");
        printf("4. Sair \n");
        printf("Escolha uma opcao: ");
        scanf("%s", opcao);
        
        if (strcmp(opcao, "1") == 0 || strcmp(opcao, "2") == 0 || strcmp(opcao, "3") == 0 ||
            strcmp(opcao, "4") == 0) {
            
            return opcao[0];
            
        } else {
            printf("\nOpcao invalida, por favor escolha uma das opcoes do menu! \n\n");
        }
    }
}

