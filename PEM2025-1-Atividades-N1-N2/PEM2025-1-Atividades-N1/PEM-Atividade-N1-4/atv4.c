/*--------------------------------------------
 Disciplina: Programação Estruturada e Modular
                 Prof. Verissimo
----------------------------------------------
Objetivo do Programa: Explorar arvore de diretórios usando recursividade
Data - 31/03/25
Autor: Wallace Silva de Souza
----------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

void listarDiretorios(const char *caminho)
{
    DIR *dir; //Cria um ponteiro para manipular o diretorio que esta aberto
    struct dirent *item; //armazena informações de um item do diretório
    struct stat a; //armazena informações detalhadas dos arquivos.
    char caminhoCompleto[1024]; //armazenar caminhos completos

    // Abrir o diretório fornecido
    dir = opendir(caminho);

    if (dir == NULL)
    {
        //Comando caso nao seja possivel abrir um diretorio, perror exbibi uma mensagem detalhada do motivo do diretorio nao abrir.
        //Ele da um detalhamento sobre o erro
        perror("Nao foi possivel abrir o diretorio");
        return;
    }

    //Leitura dos proximos arquivos do diretorio e armazena em item
    //E retorna NULL quando todos os arquivos forem lidos
    while ((item = readdir(dir)) != NULL)
    {
        // Ignora as entradas "." e ".."
        if (strcmp(item->d_name, ".") == 0 || strcmp(item->d_name, "..") == 0)
            continue;

        // Constroi o caminho completo do arquivo/subdiretório

        /*snprintf é usado para formatar uma string e evitar o estouro de buffer
        O tamanho maximo do buffer foi declarado no array caminhocompleto, que tem um tamanho de  1024 caracteres*/
        snprintf(caminhoCompleto, sizeof(caminhoCompleto), "%s/%s", caminho, item->d_name);

        // Verifica se é um subdiretorio
        /*Stat é utilizada para obter informação sobre o diretorio ou arquivo, stat vai preencher a strutura "a" com com os dados adquiridos, 
       Stat preenche a posicao de memoria de  a com as informacoes sobre os arquivos ou diretorios.*/
       //S_ISDIR verifica se o valor de st_mode de a indica que o item é um diretório
       //st_mode contém informações sobre o tipo de arquivo por meio de um numero de bits.
        if (stat(caminhoCompleto, &a) == 0 && S_ISDIR(a.st_mode))
        {
            printf("- Diretorio: %s\n", item->d_name);

            // Faz a recursividade caso tenha um subdiretorio
            listarDiretorios(caminhoCompleto);
        }
        else
        {
            //Exibi os itens do diretório
            printf("- Arquivo: %s\n", item->d_name);
        }
    }

    //Fecha o diretório
    closedir(dir);
}

int main()
{
    //Caminho inicial para começar a listagem
    const char *caminhoInicial = "C:\\Users\\aa\\documents\\test"; // Coloque aqui o diretório que deseja abrir necessario utilizar duas barras inversas "\\" ao inves de uma.
                                                                           // Exemplo C:\\Users\\aa\\Documents\\codigos_C
    listarDiretorios(caminhoInicial);

    return 0;
}
