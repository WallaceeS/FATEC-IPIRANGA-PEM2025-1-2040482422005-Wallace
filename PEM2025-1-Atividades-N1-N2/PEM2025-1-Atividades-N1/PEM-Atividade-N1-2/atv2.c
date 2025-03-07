/*--------------------------------------------
 Disciplina: Programação Estruturada e Modular
                 Prof. Verissimo
----------------------------------------------
Objetivo do Programa: retirada e entrada de produtos em um estoque.
Data - 05/03/25
Autor: Wallace Silva de Souza*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
void estocar(char estoque[3][10][4], char rua, int gondo, char codigo_produto[4])
{
    // Determina o indice da rua
    int numerorua = -1;
    if (rua == 'A' || rua == 'a')
    {
        numerorua = 0;
    }
    else if (rua == 'B' || rua == 'b')
    {
        numerorua = 1;
    }
    else if (rua == 'C' || rua == 'c')
    {
        numerorua = 2;
    }

    // verificação se a rua for invalida
    if (numerorua == -1 || numerorua > 2)
    {
        printf("Rua invalida!\n");
        return;
    }
    // verificação para saber se o produto ja foi resgitrado
    for (int i = 0; i < 10; i++)
    {
        if (strcmp(estoque[numerorua][i], codigo_produto) == 0)
        {
            // Se o código já estiver na mesma gondola, apenas informa
            if (i == gondo)
            {
                printf("Produto  ja registrado na Gondola %d da Rua %c. Registrando novamente o produto.", gondo + 1, rua);
            }
            else
            {
                // verificação para saber se o codigo foi registrado na mesma rua
                printf("Produto ja registrado na Rua %c Gondola %d. Nao e possivel registrar novamente o mesmo codigo nessa gondola.\n", rua, i + 1);
            }
            return;
        }
    }
    // verificao para saber gondola esta ocupada
    if (estoque[numerorua][gondo][0] != '\0')
    {
        printf("Erro: Gondola %d da rua %c ja esta ocupada.\n", gondo + 1, rua);
        return;
    }

    // armazena o codigo do produto na gondola
    strcpy(estoque[numerorua][gondo], codigo_produto);
    printf("Produto armazenado com sucesso na Gondola %d na Rua %c.\n", gondo + 1, rua);
}
void retirar(char estoque[3][10][4], char rua, int gondo, char codigo_produto[4])
{
    // Determina o indice da rua
    int numerorua = -1;
    if (rua == 'A' || rua == 'a')
    {
        numerorua = 0;
    }
    else if (rua == 'B' || rua == 'b')
    {
        numerorua = 1;
    }
    else if (rua == 'C' || rua == 'c')
    {
        numerorua = 2;
    }

    // verificação se a rua for invalida
    if (numerorua == -1 || numerorua > 2)
    {
        printf("Rua invalida!\n");
        return;
    }

    // verificação para saber se o produto ja foi resgitrado
    if (strcmp(estoque[numerorua][gondo], codigo_produto) == 0)
    {
        // se o produto foi encontrado, remove ele.
        strcpy(estoque[numerorua][gondo], "\0");
        printf("Produto retirado da Gondola %d da Rua %c com sucesso.\n", gondo + 1, rua);
    }
    else
    {
        // Caso o produto não esteja na gondola
        printf("Erro: Produto  nao encontrado na Gondola %d da Rua %c.\n", gondo + 1, rua);
    }
}
int main()
{
    char estoque[3][10][4];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                estoque[i][j][k] = '\0'; // inicia o estoque em 0
            }
        }
    }
    char rua;
    int gondo;
    char codigo_produto[4];
    char escolha[7];
    char opcao[3];
    // laço inifinito para o usuario conseguir armazenar ou retirar o produto mais de uma vez, o laço apenas para se for digitado a palavra [parar].
    while (true)
    {
        printf("Digite [retirar] para retirar o produto do estoque. Digite [estocar] para adicionar o produto no estoque. Digite [parar] para encerrar o programa: ");
        scanf("%s", escolha);

        /*comando para comparar uma string. Caso o que foi digitado seja igual o que está na verificação ele retornar 0.
        Se for falso ele retorna um valor diferente de 0 e não entra no laço
         */
        if (strcmp(escolha, "parar") == 0 || strcmp(escolha, "PARAR") == 0 || strcmp(escolha, "Parar") == 0)
        {
            printf("Programa encerrado!");
            break;
        }
        else if (strcmp(escolha, "estocar") == 0 || strcmp(escolha, "ESTOCAR") == 0 || strcmp(escolha, "Escolha") == 0)
        {
            // laço infinito para armazenar os produtos no estoque, ate o usuario não querer mais armazenar.
            while (true)
            {

                printf("Digite a rua [A] [B] [C] em que deseja armazenar o produto:  ");
                scanf(" %c", &rua);
                // verificação para saber se a rua digitada está correta.
                if (rua != 'a' && rua != 'A' && rua != 'b' && rua != 'B' && rua != 'c' && rua != 'C')
                {
                    printf("Rua invalida! \n");
                    continue;
                }

                printf("Digite o codigo do produto contendo 1 letra e 3 numeros: ");
                scanf("%s", codigo_produto);
                printf("Digite a gondola que deseja armazenar o produto: ");
                scanf("%d", &gondo);
                // verificação para saber se o numero da gondola existe.
                if (gondo < 1 || gondo > 10)
                {
                    printf("Gandola invalida! Por favor digite uma valida.\n");
                    continue;
                }
                estocar(estoque, rua, gondo - 1, codigo_produto);
                // verificação para saber se o usuario deseja continuar armazenando os produtos no estoque
                printf("\nDeseja continuar adicionando produtos no estoque [Sim] ou [Nao]: ");
                scanf("%s", opcao);
                if (strcmp(opcao, "nao") == 0 || strcmp(opcao, "Nao") == 0 || strcmp(opcao, "NAO") == 0)
                {
                    break;
                }
                if (strcmp(opcao, "sim") != 0 && strcmp(opcao, "Sim") != 0 && strcmp(opcao, "SIM") != 0)
                {
                    printf("Opcao invalida! Programa encerrado");
                    break;
                }
            }
        }
        else if (strcmp(escolha, "retirar") == 0 || strcmp(escolha, "RETIRAR") == 0 || strcmp(escolha, "Retirar") == 0)
        {
            while (true)
            {
                printf("Digite a rua [A] [B] [C] em que deseja retirar o produto:  ");
                scanf(" %c", &rua);
                // verificação para saber se a rua digitada está correta.
                if (rua != 'a' && rua != 'A' && rua != 'b' && rua != 'B' && rua != 'c' && rua != 'C')
                {
                    printf("Rua invalida! \n");
                    continue;
                }

                printf("Digite o codigo do produto contendo 1 letra e 3 numeros: ");
                scanf("%s", codigo_produto);
                printf("Digite a gondola que deseja retirar o produto: ");
                scanf("%d", &gondo);
                // verificação para saber se o numero da gondola existe.
                if (gondo < 1 || gondo > 10)
                {
                    printf("Gandola invalida! Por favor digite uma valida.\n");
                    continue;
                }
                retirar(estoque, rua, gondo - 1, codigo_produto);
                // verificação para saber se o usuario deseja continuar armazenando os produtos no estoque
                printf("\nDeseja continuar retirando produtos no estoque [Sim] ou [Nao]: ");
                scanf("%s", opcao);
                if (strcmp(opcao, "nao") == 0 || strcmp(opcao, "Nao") == 0 || strcmp(opcao, "NAO") == 0)
                {
                    break;
                }
                if (strcmp(opcao, "sim") != 0 && strcmp(opcao, "Sim") != 0 && strcmp(opcao, "SIM") != 0)
                {
                    printf("Opcao invalida! Programa encerrado");
                    break;
                }
            }
        }
    }

    return 0;
}
