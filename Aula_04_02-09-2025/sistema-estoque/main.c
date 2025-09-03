#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h> // Inclua esta biblioteca para usar strcmp()

// A função menu() agora retorna um char
char menu();

int main(int argc, char *argv[]) {
    char opcao = menu();
    
    // Use %c para imprimir o caractere
    printf("%c\n", opcao); 

    if (opcao == '1') {
        printf("cadastrar");
    } else if (opcao == '2') {
        printf("editar");
    } else if (opcao == '3') {
        printf("deletar");
    } else if (opcao == '4') {
        printf("listar");
    } else if (opcao == '0'){
        printf("fechar sistema");
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


	
