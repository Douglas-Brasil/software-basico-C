#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
char menu();
int votosRealizadosPrimeiroCandidato[10];
int votosRealizadosSegundoCandidato[10];
int votosRealizadosTerceiroCandidato[10];

int contadorVotosPrimeiroCandidato;
int contadorVotosSegundoCandidato;
int contadorVotosTerceiroCandidato;

int contadorVotosGerais;

int main(int argc, char *argv[]) {
	
	while (true) {
		int opcao = menu();
		
		if (opcao == 1) {
			votar();
		} else if (opcao == 2) {
			mostrarResultado();
		}
	}
	return 0;
}

char menu() {
	while (true) {
		int opcao;
		printf("Bem vindo ao Sistema de Votacao \n\n");
		printf("1. Votar \n");
		printf("2. resultado \n");
		printf("3. Encerrar \n");
		printf("Escolha uma opcao: ");
		scanf("%d", &opcao);
		
		if (opcao == 1 || opcao == 2 || opcao == 3) {
			return opcao;
		}else {
			printf("Opcao invalida! \n\n\n\n");	
		}
	}	
}



void votar() {
	while (true) {
		int voto;
		printf("Digite o numero do candidato em quem deseja votar (1, 2 ou 3): ");
		scanf("%d", &voto);
		
		if (voto == 1 || voto == 2 || voto == 3) {
			contadorVotosGerais++;
			FILE *arquivoVoto = fopen("registroDeVotos.txt", "a+");
			fprintf(arquivoVoto, "%d \n", voto);
			fclose(arquivoVoto);
			printf("Voto registrado com sucesso! \n \n");
			
			if (voto == 1) {
				votosRealizadosPrimeiroCandidato[contadorVotosPrimeiroCandidato] = voto;
				contadorVotosPrimeiroCandidato++;
			} else if (voto == 2) {
				votosRealizadosSegundoCandidato[contadorVotosSegundoCandidato] = voto;
				contadorVotosSegundoCandidato++;
			} else {
				votosRealizadosTerceiroCandidato[contadorVotosTerceiroCandidato] = voto;
				contadorVotosTerceiroCandidato++;
			}
			break;
		}
		else {
			printf("Candidato não encontrado, tente novamente! \n \n");
		}
	}
}

void mostrarResultado() {
	printf("Resultado da eleicao: \n \n");
	printf("Candidato 1: %d votos \n", contadorVotosPrimeiroCandidato + 1);
	printf("Candidato 2: %d votos \n", contadorVotosSegundoCandidato + 1);
	printf("Candidato 3: %d votos \n \n", contadorVotosTerceiroCandidato);
};


