#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 20.00391-9 Matheus Coelho Rocha Pinto
// 18.00266-8 Samuel Luiz Rubinec
// 20.00397-8 Sarah Silvestre

#include <math.h>
#define MAX 255
#define Ro 6372795.477598
#define VALOR_PI 3.1415

// **************************************
//    Criar a estrutura de dados GPS
// **************************************
typedef struct
{
    float lat, lon, alt;
    int tempo;
} GPS;
// **************************************


// **************************************
//        Prot�tipos das fun��es
// **************************************
void LerLinha(char linha[MAX], FILE* arq);
void Trocar(char linha[MAX], char antigo, char novo);
GPS ConverterGPS(char linha[MAX]);
float CalcularDistancia(GPS A, GPS B);
// **************************************

int i = 0;

int main()
{
    // *******************************************
    //   declara��o das vari�veis
    // *******************************************
    char linha[MAX], antigo, novo;
    float Distancia, DistanciaTotal, Velocidade;
    GPS A, B;
    // *******************************************




    // *******************************************
    //    abertura do arquivo de entrada
    // *******************************************
    FILE *arq;
    arq = fopen("rio_do_ouro.csv", "r");
    // *******************************************
    if(arq==NULL)
    {
        printf("Não foi possivel ler o arquivo, conserte e tente novamente!\n");
        exit(EXIT_FAILURE);
    }

    // *******************************************
    //    abertura do arquivo de saida
    // *******************************************
    FILE *saida;
    saida = fopen("saida_rio_do_ouro.csv", "a");
    // *******************************************
    if(saida==NULL)
    {
        printf("Não foi possivel ler o arquivo, conserte e tente novamente!\n");
        exit(EXIT_FAILURE);
    }

    // *******************************************
    //    Ler o cabe�alho do arquivo
    // *******************************************
    fgets(linha, MAX, arq);
    if(linha[strlen(linha)-1]=="\n")
    {
        linha[strlen(linha)-1]="\0";
    }
    // *******************************************




    // *******************************************
    //    Ler o primeiro dado do arquivo
    //    e armazenar como um "ponto anterior" (É O PONTO INTEIRO)
    // *******************************************
    LerLinha(linha, arq);
    A = ConverterGPS(linha);

    // *******************************************




    // *******************************************
    //    Ler os demais dados do arquivo
    // *******************************************
    while(!feof(arq))//ler o arquivo até o final
    {
        // *********************************************
        //    Ler uma linha e separar os dados do ponto
        // *********************************************
        LerLinha(linha, arq);
        Trocar(linha, antigo, novo);
        B = ConverterGPS(linha);

        // *******************************************

        // *****************************************************
        //   Se o "tempo atual" for igual ao "tempo anterior"
        //   OU
        //   se todas as coordenadas do "ponto atual" forem
        //    iguais as do "ponto anterior"
        //   O PONTO DEVE SER IGNORADO
        // *****************************************************
        if(A.tempo == B.tempo || (A.lat == B.lat && A.lon == B.lon && A.alt == B.alt)) //Condicao descrita acima
        {
            // **********************************************************************
            //  calcular a dist�ncia entre o "ponto atual" e o "ponto antrior" em m,
            //  calcular o somat�rio da dist�ncia total em m,
            //  calcular a velocidade instant�nea em km/s
            //  exibir o que foi processado
            //  acrescantar ao novo arquivo as informa��es lidas e a velocidade
            // **********************************************************************
            GPS gps;
            Distancia = CalcularDistancia(A, B);
            DistanciaTotal = 0;
            DistanciaTotal += Distancia;
            Velocidade = 3.6*((Distancia)/(A.tempo - B.tempo));
            //fprintf(saida, "%s;%s;%s;%s;%s\n", "Latitude", "Longitude", "Altitude", "Velocidade");
            fprintf(saida, "%f;%f;%f;%i;%f\n", gps.lat, gps.lon, gps.alt, gps.tempo, Velocidade);
            // *******************************************
        }  // fim do if
        // *******************************************

        // *******************************************
        //    Atualizar o "ponto anterior"
        // *******************************************
        A = B;

        // *******************************************
    } // fim do while

    // *******************************************
    //    exibir o total percorrido
    // *******************************************
    printf("O total percorrido foi de %.2f km", (DistanciaTotal/1000));

    // *******************************************

    // *******************************************
    //    Fechar os arquivos
    // *******************************************
    fclose(arq);
    fclose(saida);
    // *******************************************
    return 0;
}


// **************************************
//       Ler uma linha do arquivo
// **************************************
void LerLinha(char linha[MAX], FILE *arq)
{
    fgets(linha,MAX,arq);
    if (linha[strlen(linha)-1] == '\n')
        linha[strlen(linha)-1] = '\0';
}
// **************************************



// **************************************
//  Trocar o caractere antigo pelo novo
// **************************************
void Trocar(char linha[MAX], char antigo, char novo)
{
    int i;
    for (i = 0; i < strlen(linha); i++)
        if (linha[i] == ',')
            linha[i] = '.';
}
// **************************************



// ********************************************
//  Divide uma string pelo caractere separador
//  nos campos da estrutura de dados GPS
// ********************************************
GPS ConverterGPS(char linha[])
{
    GPS gps;
    char *token = strtok(linha, ";");

    token = strtok(NULL, ";");
    gps.lat = atof(token);

    token = strtok(NULL, ";");
    gps.lon = atof(token);

    token = strtok(NULL, ";");
    gps.alt = atof(token);

    token = strtok(NULL, ";");
    gps.tempo = atoi(token);

    return gps;
}
// **************************************

// *******************************************
//  Retorna a dist�ncia entre os pontos A e B
// NÃO ESQUECER DE CONVERTER OS VALORES DE ENTRADA
// AS FUNÇÕES TRIGONOMÉTRICAS PARA RADIANO!!
// *******************************************
float CalcularDistancia(GPS A, GPS B)
{
    float dh, dv, Distancia;

    A.lat = (A.lat * VALOR_PI)/180;
    B.lat = (B.lat * VALOR_PI)/180;
    A.lon = (A.lon * VALOR_PI)/180;
    B.lon = (B.lon * VALOR_PI)/180;

    dh = (Ro)*acos((sin(A.lat)*cos(B.lat))+(cos(A.lat)*cos(B.lat)*cos(A.lon - B.lon))); //ponto atual
    dv = B.alt - A.alt; //ponto anterior

    Distancia = sqrt(pow(dh, 2)+ pow(dv, 2));

    return Distancia;
}
// **************************************
