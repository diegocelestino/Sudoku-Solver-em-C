#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define TAM 9


void imprimeTabuleiro(int tabuleiro [TAM][TAM], int linha, int coluna);
int encontraLinhaVazia(int tabuleiro[TAM][TAM]);
int encontraColunaVazia(int tabuleiro[TAM][TAM]);
int ehValido(int tabuleiro[TAM][TAM], int num, int linha, int coluna);
int resolve(int tabuleiro[TAM][TAM]);

int main(void){
	
	int tabuleiro[9][9] = {
                {5, 3, 0, 0, 7, 0, 0, 0, 0},
                {6, 0, 0, 1, 9, 5, 0, 0, 0},
                {0, 9, 8, 0, 0, 0, 0, 6, 0},
                {8, 0, 0, 0, 6, 0, 0, 0, 3},
                {4, 0, 0, 8, 0, 3, 0, 0, 1},
                {7, 0, 0, 0, 2, 0, 0, 0, 6},
                {0, 6, 0, 0, 0, 0, 2, 8, 0},
                {0, 0, 0, 4, 1, 9, 0, 0, 5},
                {0, 0, 0, 0, 8, 0, 0, 7, 9}};
	
	imprimeTabuleiro(tabuleiro, 0, 0);
	
	
	resolve(tabuleiro);
	printf("\n\n");
	imprimeTabuleiro(tabuleiro, 0, 0);
	
	
	
}

int resolve(int tabuleiro[TAM][TAM]){
	int linha, coluna, i;
	linha = encontraLinhaVazia(tabuleiro);
	coluna = encontraColunaVazia(tabuleiro);
	

	
	if(linha == 10 && coluna ==10){
		return 1;
		

	}else{
		for(i = 1; i < 10; i++){
		
				
            if (ehValido(tabuleiro, i, linha, coluna)){
                tabuleiro[linha][coluna] = i;
                	system("cls");
					imprimeTabuleiro(tabuleiro, linha, coluna);
					Sleep(700);
                
                if (resolve(tabuleiro) == 1){
                    return 1;
                }else{
                    tabuleiro[linha][coluna] = 0;
                  	system("cls");
					imprimeTabuleiro(tabuleiro, linha, coluna);
					Sleep(700);
                    
                }
            }
		}
	
		return 0;
		
	}
}

int ehValido(int tabuleiro[TAM][TAM], int num, int linha, int coluna){
	int i, j;
	
	//Checar linha
	for(i = 0; i < TAM; i++){
		if(tabuleiro[linha][i] == num && coluna != i){
			return 0;
		}
	}
	
	//checar coluna 
	for (i = 0; i < TAM; i++){
        if (tabuleiro[i][coluna] == num && linha != i){
            return 0;
        }
    }
    
    //checar caixa
    int caixaX = coluna / 3;
    int caixaY = linha / 3;

    	for (i = caixaY * 3; i < (caixaY * 3 + 3); i++){
            for (j = caixaX * 3; j < (caixaX * 3 + 3); j++){
                if (tabuleiro[i][j] == num && (i != linha && j != coluna)){
                    return 0;
                }
            }
        }

    return 1;
}

int encontraLinhaVazia(int tabuleiro[TAM][TAM]){
	int linha;
	int i, j;
	for(i = 0; i < TAM; i++){
		for(j = 0; j < TAM; j++){
			if(tabuleiro[i][j] == 0){
				linha = i;
				return linha;
			}
		}
	}
	return 10;
}

int encontraColunaVazia(int tabuleiro[TAM][TAM]){
	int coluna;
	int i, j;
	for(i = 0; i < TAM; i++){
		for(j = 0; j < TAM; j++){
			if(tabuleiro[i][j] == 0){
				coluna = j;
				return coluna;
			}
		}
	}
	return 10;
}

void imprimeTabuleiro(int tabuleiro [TAM][TAM], int linha, int coluna){
	int i, j;
	for(i = 0; i < TAM; i++){
		if (i % 3 == 0 && i != 0){
			printf("--------------------------------------------------------------\n");
		}
	
		for(j = 0; j < TAM; j++){
		
			
			if ((j % 3 == 0) && (j != 0)){
                printf("|");
			}	
			if(i == linha && j == coluna){
				printf(">%d<    ", tabuleiro[i][j]);
			}
            else if (j == 8){
                printf("%d", tabuleiro[i][j]);
            }else{
                printf("%d,     ", tabuleiro[i][j]);
            }
		}
		printf("\n");
	}
}
