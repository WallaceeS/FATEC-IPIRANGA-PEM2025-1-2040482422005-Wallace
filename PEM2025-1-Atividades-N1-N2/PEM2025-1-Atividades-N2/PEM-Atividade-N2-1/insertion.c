/*-------------------------------------------------------*
 *                      FATEC Ipiranga                    *
 * Disciplina: Programaçao Estruturada e Modular          *
 *          Prof. Veríssimo                               *
 *--------------------------------------------------------*
 * Objetivo do Programa: Ordenação de números com insertionsort*
 * Data - 11/5/2025                                       *
 * Autor: Wallace Silva de Souza                          *
 *--------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

// Função para pedir o  tamanho do array.
void tamanhoArray(int *tamanho)
{
    printf("Digite o tamanho: ");
    // Faz a leitura sem precisar utilizar o "&" pois a variavel "tamanho" é um ponteiro.
    scanf("%d", tamanho);
}

// Função para o usuario digitar os elementos do array
void leituraArray(int *array, int *tamanho)
{
    int i;
    for (i = 0; i < *tamanho; i++)
    {
        printf("Digite o numero: ");
        scanf("%d",(array + i));
    }
}
// Função para fazer a ordenação do array em ordem crescente atraves do metodo insertionsort
void insertionSort(int *array, int *tamanho)
{
    for (int i = 1; i < *tamanho; i++)
    {
        // Recebe o elemento atual do array
        int temporaria = *(array + i);
        // Recebe o elemento anterior do array
        int j = i - 1;
        // Faz a verificação se o elemento anterior é maior que o elemento atual se sim entra no loop
        while (j >= 0 && *(array + j) > temporaria)
        {
            *(array + j + 1) = *(array + j);
            j = j - 1;
        }
        *(array + j + 1) = temporaria;
    }
}

// Função para exibir o array ordenado
void exibir()
{
    int qtElementos;
    tamanhoArray(&qtElementos);
    // Cria um array com o tamanho digitado pelo usuario
    // malloc aloca um espaço na memória
    // Vai fazer o calculo para criar o vetor do tamanho exigido pelo usuario.
    // vai pegar o número que o usuario digitou do tamanho e vai fazer vezes o tamanho de um int que são 4 bytes.
    int *vetor = malloc(qtElementos * sizeof(int));
    leituraArray(vetor, &qtElementos);
    insertionSort(vetor, &qtElementos);
    printf("Numeros organizados de forma crescente: [");
    for (int i = 0; i < qtElementos; i++)
    {
        printf("%d", vetor[i]);
        // Apenas para  mostrar os números de maneira mais bonita
        if (i != qtElementos - 1)
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