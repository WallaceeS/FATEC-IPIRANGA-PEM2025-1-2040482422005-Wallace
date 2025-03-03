//=======================================
// Nome: Wallace Souza
//=======================================
#include <stdio.h>
#include <string.h>
// Código para remover a nota maior e a nota menor.
int c;
float soma;
float notamax;                      // maior nota
float notamin;                      // menor nota
float notac(float notas1[], int aa) // notac = nota central
{
    notamax = notas1[0];
    notamin = notas1[0];
    soma = 0;
    for (c = 0; c < aa; c++)
    {
        if (notas1[c] > notamax)
        {
            notamax = notas1[c];
        }
        if (notas1[c] < notamin)
        {
            notamin = notas1[c];
        }
        soma = soma + notas1[c];
    }
    return soma - notamax - notamin;
}
int main()
{
    int qc = 0; // qc = quantidade de candidatos
    char nomes[50][100];
    float PE[4];  // PE = Prova Escrita
    float AC[5];  // AC =  Análise curricular
    float PP[10]; // PP = Prova Prática
    float EB[3];  // EB = Entrevista em Banca Avaliadora
    float nf[50];
    int ind[50]; // armazenar um indice

    printf("Digite o numero de candidatos: ");
    scanf("%d", &qc);
    // Verificação para saber se a quantidade de candidatos passa do número máximo.
    while (qc > 50)
    {
        if (qc < 1 || qc > 50)
        {
            printf("Numeros de candidatos ultrapassam o limite!");
            printf("\nPor favor digite uma quantidade menor de candidatos: ");
            scanf("%d", &qc);
        }
    }
    int dd;
    int m;
    int nn;
    int a;
    for (dd = 0; dd < qc; dd++)
    {   
        printf("\nDigite o nome do cadidato: ");

        getchar();
        //para armazenar nome e sobrenome
        fgets(nomes[dd], sizeof(nomes[dd]), stdin);
        //remove o \n ou "pular linha", para que seja possivel digitar o nome.
        nomes[dd][strcspn(nomes[dd], "\n")] = '\0';
        printf("\nDigite a quantidade de notas da prova escrita (PE): ");
        scanf("%d", &nn);

        // Verificação para saber se  o candidato possui a quantidade necessaria de notas (PE)
        if (nn != 4)
        {
            printf("Numeros de notas nao atingidos.");
            printf("\nCandidato %s nao seguira no processo.", nomes[dd]);
            continue;
        }
        else
        {

            // Pedindo a entrada de notas da (PE)
            printf("Digite as notas da prova escrita (PE): ");
            for (a = 0; a < nn; a++)
            {
                scanf("%f", &PE[a]);
            }
        }
        printf("Digite a quantidade de notas da prova analise curricular (AC): ");
        scanf("%d", &nn);

        // Verificação para saber se  o candidato possui a quantidade necessaria de notas (AC)
        if (nn != 5)
        {
            printf("Numeros de notas nao atingidos.");
            printf("\nCandidato %s nao seguira no processo.", nomes[dd]);
            continue;
        }
        else
        {

            // Pedindo a entrada de notas da (AC)
            printf("Digite as notas da prova analise curricular (AC): ");
            for (a = 0; a < nn; a++)
            {
                scanf("%f", &AC[a]);
            }
        }
        printf("Digite a quantidade de notas da prova pratica (PP): ");
        scanf("%d", &nn);

        // Verificação para saber se  o candidato possui a quantidade necessaria de notas (PP)
        if (nn != 10)
        {
            printf("Numeros de notas nao atingidos.");
            printf("\nCandidato %s nao seguira no processo.", nomes[dd]);
            continue;
        }

        else
        {
            // Pedindo a entrada de notas da (PP)
            printf("Digite as notas da prova pratica (PP): ");
            for (a = 0; a < nn; a++)
            {
                scanf("%f", &PP[a]);
            }
        }

        printf("Digite a quantidade de notas da entrevista banca avaliadora (EB): ");
        scanf("%d", &nn);

        // Verificação para saber se  o candidato possui a quantidade necessaria de notas (EB)
        if (nn != 3)
        {
            printf("Numeros de notas nao atingidos.");
            printf("\nCandidato %s nao seguira no processo.", nomes[dd]);
            continue;
        }

        else
        {
            // Pedindo a entrada de notas da (EB)
            printf("Digite as notas da entrevista banca avaliadora (EB): ");
            for (a = 0; a < nn; a++)
            {
                scanf("%f", &EB[a]);
            }
        }
        // chama a função para remover a menor e a maior nota
        // nf = nota final.
        float nfPE = notac(PE, 4);
        float nfAC = notac(AC, 5);
        float nfPP = notac(PP, 10);
        float nfEB = notac(EB, 3);

        // calcular a nota final do candidato
        nf[dd] = (nfPE * 0.3) + (nfAC * 0.1) + (nfPP * 0.4) + (nfEB * 0.2);
        ind[dd] = dd; // armazena um indice para o nome digitado


    }
    
    for (int r = 0; r < qc - 1; r++)
    {
        for (int s = 0; s < qc - 1 - r; s++)
        {
            if (nf[s] < nf[s + 1]) // Ordenar em ordem decrescente
            {
                // Trocar as notas finais
                float temporaria = nf[s];
                nf[s] = nf[s + 1];
                nf[s + 1] = temporaria;

                // Trocar os indices para a nota corresponder com o nome.
                int tempind = ind[s];
                ind[s] = ind[s + 1];
                ind[s + 1] = tempind;

                // tempind = indice temporario.
            }
        }
    }

    // Exibir os 15 melhores candidatos
    printf("\nOs 15 melhores candidatos:\n");
    for (int r = 0; r < qc && r < 15; r++)
    {
        printf("Candidato %s - Nota Final: %.2f\n", nomes[ind[r]], nf[r]);
    }
    return 0;
}