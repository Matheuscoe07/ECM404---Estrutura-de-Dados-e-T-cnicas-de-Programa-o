#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOME 80

//STRUCT
typedef struct{
    char* nome;
    int idade;
}pessoa;

//Prototipos de funcao
void quicksort(pessoa, int inicio, int fim);
void exibirVetor(pessoa vetor[], int tamanho);
int particionar(pessoa vetor[], int inicio, int fim, int pivo);
void trocar(float *num1, float *num2);
int buscaBinaria(float vetor[], int inicio, int fim, float procurado);

int main(){+
    float dados[10] = {10., 89., -5., 7.8, 5.6, .89, 9.0, 67., 2.2, 1.56};
    printf("NOMES E IDADE FORA DE ORDEM:\n");
    exibirVetor(dados, 10);
    quicksort(dados, 0, 9);
    printf("NOMES E IDADE EM ORDEM:\n");
    exibirVetor(dados, 10);
    float alvo = 1.560;
    printf("Buscando por %.2f = %i\n", alvo, buscaBinaria(dados, 0, 9, alvo));
    return 0;
}

//Definição das funções
void exibirVetor(float vetor[], int tamanho){
    for(int i = 0; i < tamanho; i++)
        printf("%i: %.2f\n", i, vetor[i]);
}

void quicksort(float vetor[], int inicio, int fim){
    int pivo, novoPivo;
    if(inicio < fim){
        pivo = (inicio+fim)/2;
        novoPivo = particionar(vetor, inicio, fim, pivo);
        quicksort(vetor, inicio, novoPivo-1);
        quicksort(vetor, novoPivo+1, fim);
    }
}

void trocar(float *num1, float *num2){
    float temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int particionar(float vetor[], int inicio, int fim, int pivo){
    int i, j;
    float valor_pivo = vetor[pivo];
    trocar(&vetor[pivo], &vetor[fim]);
    j = inicio;
    for(i = inicio; i < fim; i++){
        if(vetor[i] <= valor_pivo){
            trocar(&vetor[i], &vetor[j]);
            j++;
        }
    }
    trocar(&vetor[j], &vetor[fim]);
    return j;
}

int buscaBinaria(float vetor[], int inicio, int fim, float procurado){
    if (inicio > fim )
        return -1;
    int centro = (inicio+fim)/2;
    if(vetor[centro] == procurado)
        return centro;

    if(procurado > vetor[centro])
        return buscaBinaria(vetor, centro+1, fim, procurado);
    else
        return buscaBinaria(vetor, inicio, centro-1, procurado);
}
