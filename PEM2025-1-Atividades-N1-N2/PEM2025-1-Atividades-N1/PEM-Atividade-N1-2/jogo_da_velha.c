/*--------------------------------------------
 Disciplina: Programação Estruturada e Modular
                 Prof. Verissimo
----------------------------------------------
Objetivo do Programa: Aula 3-Jogo da Velha
Data - 28/02/25
Autor: Wallace Silva de Souza*/

#include <stdio.h>
#include <stdbool.h>
int i;
int j;
// funcao para exibir o tabuleiro atualizado
void ExibirTabuleiro(char tabuleiro[3][3]){
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            printf("%c", tabuleiro[i][j]);
            if (j < 2){
                printf(" | ");
            }
        }
        printf("\n");
        if (i < 2){
            printf("-------------\n");
        }

    }
} 
// funcao para verificar se alguem ganhou o jogo
bool VerificarVencedor(char tabuleiro[3][3], char jogador){
    // verificar linhas e colunas
    for(i=0; i < 3; i++){
        if (tabuleiro[i][0] == jogador && tabuleiro[i][1] == jogador && tabuleiro[i][2] == jogador){
            return true;
        }
    }
    for(j = 0; j < 3; j++){
        if (tabuleiro[0][j] == jogador && tabuleiro[1][j] == jogador && tabuleiro[2][j]){
            return true;
        }
    }
    // verificar diagonais
    if (tabuleiro[0][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][2] == jogador){
        return true;
    }
    if(tabuleiro [0][2] == jogador && tabuleiro [1][1] == jogador && tabuleiro [2][0] == jogador){
        return true;
    }
    return 0;
}
int main(){
    char tabuleiro[3][3] = {{' ', ' ', ' '},{' ', ' ', ' '},{' ', ' ', ' '}};
        
    char jogador_atual = 'X';
    bool vencedor = false;
    while(true){
        ExibirTabuleiro(tabuleiro);
        printf("E a vez do jogador %c ", jogador_atual);
        int linha, coluna;
        printf("Digite a linha (1 a 3): ");
        scanf("%d", &linha);
        printf("Digite a coluna (1 a 3): ");
        scanf("%d", &coluna);
        // verifica se a linha e coluna esta vazia
        if (tabuleiro[linha - 1][coluna - 1]  == ' '){
            tabuleiro[linha - 1][coluna - 1] = jogador_atual;
            // verifica se houve um vencedor
            if (VerificarVencedor(tabuleiro, jogador_atual)){
                ExibirTabuleiro(tabuleiro);
                printf("O jogador %c  ", jogador_atual);
                printf("venceu!");
                vencedor = true;
                break;
            }
            else{
                if (jogador_atual == 'X'){
                    jogador_atual = 'O';
                }
                else{
                    jogador_atual = 'X';
                }
            }
        }
        else{
            printf("Essa posicao [%d] [%d] esta ocupada. Tente novamente.",coluna,linha);
        }

    }
    if(vencedor == false){
        ExibirTabuleiro(tabuleiro);
        printf("O jogo terminou em empate.");
    }
    return 0;
}
    