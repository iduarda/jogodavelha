#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

/* Jogo da Velha. Projeto para Técnicas e Desenvolvimento de Algoritmos */

struct Jogador{
    char nome[50];
    int vitorias;
};

int lerNumero() { // Função para tratar erros do usuário
    int numero;
    while (scanf("%d", &numero) != 1) {
        printf("\nOpção Inválida! Digite um número: \n ");
        // Limpa o buffer de entrada
        while (getchar() != '\n');
    }
    return numero;
}

int main(int argc, char *argv[]) {
	setlocale (LC_ALL, "portuguese");
	
	int i, l, c, linha, coluna, jogador, ganhou, jogadas, numero = 0;
	struct Jogador jogadores[2];
	char jogo [3][3];
	int loop = 1;
	
		while(loop==1){ // menu do jogo
		system("cls");
		printf("\n\tJOGO DA VELHA\n\n");
		printf("1 - JOGAR\n");
		printf("2 - VER RANKING\n");
		printf("3 - CRÉDITOS\n");
		printf("4 - SAIR\n\n");
		printf("Digite a opcao desejada: ");
		numero = lerNumero();
	
		switch(numero){
			case 1:{
				printf("\nDigite o nome do jogador 1 (apenas 1 nome): ");
                scanf("%s", jogadores[0].nome);

                printf("\nDigite o nome do jogador 2 (apenas 1 nome): ");
                scanf("%s", jogadores[1].nome);
				
				jogador = 1;
				ganhou = 0;
				jogadas = 0;
				// inicializando a matriz
				for(l=0; l<3; l++){
					for(c=0; c<3; c++){
						jogo[l][c] = ' ';
					}
				}
				
				do{ // repetir atÃ© alguÃ©m ganhar ou dar velha
					// imprimir o jogo
					printf("\n\n\t\n\n");
					for(l=0; l<3; l++){
						for(c=0; c<3; c++){
							if(c==0){
								printf("\t");
							}
							printf(" %c ", jogo[l][c]);
							if(c<2){
								printf("|");
							}
							if(c==2){
								
							}
						}
						if(l<2){
							printf("\n\t-----------");
						}
						printf("\n");
						
					}
					
					// ler cordenadas
					do{
						printf("\nJOGADOR 1 (%s) = o\nJOGADOR 2 (%s) = x\n", jogadores[0].nome, jogadores[1].nome);
						printf("\nJOGADOR %d: Digite a linha e a coluna que deseja jogar (observação: dê um espaco entre os números): ", jogador);
						scanf("%d%d", &linha, &coluna);
					}while(linha<0 || linha>2 || coluna<0 || coluna>2 || jogo[linha][coluna]!=' ');
					
					// salvar coordenadas
					if(jogador==1){
						jogo[linha][coluna]='o';
						jogador++;
					}else{
						jogo[linha][coluna]='x';
						jogador = 1;
					}
					jogadas++;
					
					// ganhar por linha
					if(jogo[0][0] == 'o' && jogo[0][1] == 'o' && jogo[0][2] == 'o' ||
					   jogo[1][0] == 'o' && jogo[1][1] == 'o' && jogo[1][2] == 'o' ||
					   jogo[2][0] == 'o' && jogo[2][1] == 'o' && jogo[2][2] == 'o'){
					   	printf("\nO jogador 1 (%s) venceu!\n", jogadores[0].nome);
					   	jogadores[0].vitorias++;
					   	ganhou = 1;
					}
					
					if(jogo[0][0] == 'x' && jogo[0][1] == 'x' && jogo[0][2] == 'x' ||
					   jogo[1][0] == 'x' && jogo[1][1] == 'x' && jogo[1][2] == 'x' ||
					   jogo[2][0] == 'x' && jogo[2][1] == 'x' && jogo[2][2] == 'x'){
					   	printf("\nO jogador 2 (%s) venceu!\n", jogadores[1].nome);
					   	jogadores[1].vitorias++;
					   	ganhou = 1;
					}
					
					// ganhar por coluna
					if(jogo[0][0] == 'o' && jogo[1][0] == 'o' && jogo[2][0] == 'o' ||
					   jogo[0][1] == 'o' && jogo[1][1] == 'o' && jogo[2][1] == 'o' ||
					   jogo[0][2] == 'o' && jogo[1][2] == 'o' && jogo[2][2] == 'o'){
						printf("\nO jogador 1 (%s) venceu!\n", jogadores[0].nome);
						jogadores[0].vitorias++;
						ganhou = 1;	
					}
					
					if(jogo[0][0] == 'x' && jogo[1][0] == 'x' && jogo[2][0] == 'x' ||
					   jogo[0][1] == 'x' && jogo[1][1] == 'x' && jogo[2][1] == 'x' ||
					   jogo[0][2] == 'x' && jogo[1][2] == 'x' && jogo[2][2] == 'x'){
						printf("\nO jogador 2 (%s) venceu!\n", jogadores[1].nome);
						jogadores[1].vitorias++;
						ganhou = 1;   	
					}
					
					// ganhar na diagonal principal
					if(jogo[0][0] == 'o' && jogo[1][1] == 'o' && jogo[2][2] == 'o'){
						printf("\nO jogador 1 (%s) venceu!\n", jogadores[0].nome); 
						jogadores[0].vitorias++;
						ganhou = 1;
					}
					if(jogo[0][0] == 'x' && jogo[1][1] == 'x' && jogo[2][2] == 'x'){
						printf("\nO jogador 2 (%s) venceu!\n", jogadores[1].nome); 
						jogadores[1].vitorias++;
						ganhou = 1;
					}
					
					// ganhar na diagonal secundÃ¡ria
					if(jogo[0][2] == 'o' && jogo[1][1] == 'o' && jogo[2][0] == 'o'){
						printf("\nO jogador 1 (%s) venceu!\n", jogadores[0].nome);
						jogadores[0].vitorias++;
						ganhou = 1;
					}
					if(jogo[0][2] == 'x' && jogo[1][1] == 'x' && jogo[2][0] == 'x'){
						printf("\nO jogador 2 (%s) venceu!\n", jogadores[1].nome);
						jogadores[1].vitorias++;
						ganhou = 1;
					}
				}while(ganhou == 0 && jogadas < 9);
				
				if(ganhou == 0){
					printf("\nO jogo finalizou sem ganhador!\n");
				}
				break;
			}
			case 2:{
				printf("\n\tRANKING\n\n");
                
                printf("Jogador 1: %d vitórias\n", jogadores[0].vitorias);
                printf("Jogador 2: %d vitórias\n", jogadores[1].vitorias);
				break;
			}
			case 3:{
				printf("\n\t\t\t\tCREDITOS\n\n");
				
				printf("\n\tDesenvolvido por Anna Maria, Maria Eduarda e Milena Azevedo\n");
				printf("\n\tAlunos do UNIPÊ - Ciência da Computação\n");
				printf("\n\tTurma: Técnicas e Desenvolvimento de Algoritmos - 1B 2023.2\n\n");
				break;
			}
			case 4:{
				printf("\nSaindo do jogo...\n");
				loop = 0;
				break;
			}
			default:{
				printf("\nOpção Inválida!\n");
				break;
			}
		}
		if (loop != 0) {
			printf("\nDigite '1' para voltar ao menu, ou '0' para sair do jogo.\n");
			loop = lerNumero();
		}
	}
	
	return 0;
}