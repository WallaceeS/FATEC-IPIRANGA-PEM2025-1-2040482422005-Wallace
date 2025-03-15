/*--------------------------------------------
 Disciplina: Programação Estruturada e Modular
                 Prof. Verissimo
----------------------------------------------
Objetivo do Programa: Modularização da atv2 e uso de ponteiro
Data - 15/03/25
Autor: Wallace Silva de Souza*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Função para inicializar o estoque
void inicializar_estoque(char estoque[3][10][4]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 4; k++) {
                estoque[i][j][k] = '\0'; // Inicializa o estoque vazio'
            }
        }
    }
}

// Função para determinar o índice da rua
int obter_indice_rua(char rua) {
    if (rua == 'A' || rua == 'a') {
        return 0;
    } else if (rua == 'B' || rua == 'b') {
        return 1;
    } else if (rua == 'C' || rua == 'c') {
        return 2;
    }
    return -1; // Rua inválida
}

// Função para verificar se a gondola está ocupada
bool verificar_gondola_ocupada(char estoque[3][10][4], int numerorua, int gondo) {
    return estoque[numerorua][gondo][0] != '\0'; 
}

// Função para estocar um produto
void estocar_produto(char estoque[3][10][4], char rua, int gondo, char codigo_produto[4]) {
    int numerorua = obter_indice_rua(rua);
    if (numerorua == -1) {
        printf("Rua invalida!\n");
        return;
    }

    if (verificar_gondola_ocupada(estoque, numerorua, gondo)) {
        printf("Erro: Gondola %d da rua %c ja esta ocupada.\n", gondo + 1, rua);
        return;
    }

    // Armazena o codigo do produto na gondola
    strcpy(estoque[numerorua][gondo], codigo_produto);
    printf("Produto armazenado com sucesso na Gondola %d na Rua %c.\n", gondo + 1, rua);
}

// Função para retirar um produto
void retirar_produto(char estoque[3][10][4], char rua, int gondo, char codigo_produto[4]) {
    int numerorua = obter_indice_rua(rua);
    if (numerorua == -1) {
        printf("Rua invalida!\n");
        return;
    }

    if (strcmp(estoque[numerorua][gondo], codigo_produto) == 0) {
        strcpy(estoque[numerorua][gondo], "\0"); // Retira o produto da gondola
        printf("Produto retirado da Gondola %d da Rua %c com sucesso.\n", gondo + 1, rua);
    } else {
        printf("Erro: Produto nao encontrado na Gondola %d da Rua %c.\n", gondo + 1, rua);
    }
}

// Função para ler a escolha do usuario
bool ler_escolha_usuario(char *escolha) {
    printf("Digite [retirar] para retirar o produto do estoque. Digite [estocar] para adicionar o produto no estoque. Digite [parar] para encerrar o programa: ");
    scanf("%s", escolha);

    return strcmp(escolha, "parar") != 0; // Retorna true se não for "parar"
}

// Função para ler a rua, verificando sua validade
bool ler_rua(char *rua) {
    printf("Digite a rua [A] [B] [C] em que deseja armazenar o produto: ");
    scanf(" %c", rua);

    if (*rua != 'A' && *rua != 'B' && *rua != 'C' && *rua != 'a' && *rua != 'b' && *rua != 'c') {
        printf("Rua invalida! \n");
        return false;
    }
    return true;
}

// Função para ler o codigo do produto
void ler_codigo_produto(char *codigo_produto) {
    printf("Digite o codigo do produto contendo 1 letra e 3 numeros: ");
    scanf("%s", codigo_produto);
}

// Função para ler a gondola
bool ler_gondola(int *gondo) {
    printf("Digite a gondola que deseja armazenar o produto : ");
    scanf("%d", gondo);

    if (*gondo < 1 || *gondo > 10) {
        printf("Gondola invalida! Por favor, digite uma valida.\n");
        return false;
    }
    return true;
}

// Função principal para executar o programa
int main() {
    char estoque[3][10][4];
    // chama a função para iniciar o estoque em vazio
    inicializar_estoque(estoque);

    char rua;
    char escolha[7];
    char opcao[3];
    char codigo_produto[4];
    int gondo;

    while (true) {
        // Chama a função para saber a escolha do usuario
        if (ler_escolha_usuario(escolha) == false) {
            printf("Programa encerrado!\n");
            break;
        }

        if (strcmp(escolha, "estocar") == 0 || strcmp(escolha, "ESTOCAR") == 0 || strcmp(escolha, "Estocar") == 0) {
            while (true) {
                // Chama a funcao para o usuario digitar a rua e verifica se a rua é valida.
                if (ler_rua(&rua) == false){
                    continue;
                } 
                ler_codigo_produto(codigo_produto);
                 // Chama a funcao para o usuario digitar a gondola e verifica se a gondola é valida.
                if (ler_gondola(&gondo) == false){
                    continue;
                }

                estocar_produto(estoque, rua, gondo - 1, codigo_produto);

                printf("\nDeseja continuar adicionando produtos no estoque [Sim] ou [Nao]: ");
                scanf("%s", opcao);
                if (strcmp(opcao, "nao") == 0 || strcmp(opcao, "Nao") == 0 || strcmp(opcao, "NAO") == 0) {
                    break;
                }
            }
        } else if (strcmp(escolha, "retirar") == 0 || strcmp(escolha, "RETIRAR") == 0 || strcmp(escolha, "Retirar") == 0) {
            while (true) {
                if (ler_rua(&rua) == false){
                    continue;
                }
                ler_codigo_produto(codigo_produto);
                if (ler_gondola(&gondo) == false){
                    continue;
                }
                // Chama a função retirar o produto
                retirar_produto(estoque, rua, gondo - 1, codigo_produto);

                printf("\nDeseja continuar retirando produtos no estoque [Sim] ou [Nao]: ");
                scanf("%s", opcao);
                // Para o programa caso o usuario digite nao
                if (strcmp(opcao, "nao") == 0 || strcmp(opcao, "Nao") == 0 || strcmp(opcao, "NAO") == 0) {
                    break;
                }
            }
        }
    }

    return 0;
}
