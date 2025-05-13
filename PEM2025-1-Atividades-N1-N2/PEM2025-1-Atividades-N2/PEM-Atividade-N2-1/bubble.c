/*-------------------------------------------------------*
 *                      FATEC Ipiranga                    *
 * Disciplina: Programaçao Estruturada e Modular          *
 *          Prof. Veríssimo                               *
 *--------------------------------------------------------*
 * Objetivo do Programa: Ordenação de números com bubblesort*
 * Data - 10/5/2025                                       *
 * Autor: Wallace Silva de Souza                          *
 *--------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

// Função para pedir o  tamanho do array.
void tamanhoArray(int *tamanho)
{
    printf("Digite o tamanho: ");
    // faz a leitura sem precisar utilizar o "&" pois a variavel "tamanho" é um ponteiro.
    scanf("%d", tamanho);
}

// Função para o usuario digitar os elementos do array
void leituraArray(int *array, int *tamanho)
{
    int i;
    // Percorre os indices do array
    for (i = 0; i < *tamanho; i++)
    {
        printf("Digite o numero: ");
        scanf("%d", (array + i));
    }
}

// Função para fazer a ordenação do array em ordem crescente atraves do metodo bubblesort
void bubbleSort(int *array, int *tamanho)
{
    int i, j, temporaria;
    for (i = 0; i < *tamanho; i++)
    {
        for (j = 0; j < *tamanho - i - 1; j++)
        {
            // Faz a verificação se o elemento atual do array é maior que seguinte se sim vai fazer a troca entre eles.
            // Faz essa verificação utilizando ponteiros.
            // Variavel "temporaria" apenas para armazenar o valor e não perder ele.
            if (*(array + j) > *(array + j + 1))
            {
                temporaria = *(array + j);
                *(array + j) = *(array + j + 1);
                *(array + j + 1) = temporaria;
            }
        }
    }
}

// Função para exibir o array ordenado
void exibir()
{
    int qtdElementos;
    tamanhoArray(&qtdElementos);

    // Cria um array com o tamanho digitado pelo usuario
    // malloc aloca um espaço na memória
    // Vai fazer o calculo para criar o vetor do tamanho exigido pelo usuario.
    // vai pegar o número que o usuario digitou do tamanho e vai fazer vezes o tamanho de um int que são 4 bytes.
    int *vetor = malloc(qtdElementos * sizeof(int));
    leituraArray(vetor, &qtdElementos);
    bubbleSort(vetor, &qtdElementos);
    printf("Numeros organizados de forma crescente: [");
    for (int i = 0; i < qtdElementos; i++)
    {
        printf("%d", vetor[i]);

        // Apenas para  mostrar os números de maneira mais bonita
        if (i != qtdElementos - 1)
        {
            printf(",");
        }
        else
        {
            printf("]");
        }
    }
    // Libera a memória alocada pelo malloc depois do programa se encerrar, para não gerar problemas de memoria.
    free(vetor);
}

int main()
{
    exibir();

    return 0;
}