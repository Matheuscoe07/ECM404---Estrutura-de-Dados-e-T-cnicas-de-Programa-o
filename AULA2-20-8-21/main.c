#include <stdio.h>
#include <stdlib.h>

//Prototipos de funcao
void quicksort(float vetor[], int inicio, int fim);
void exibirVetor(float vetor[], int tamanho);
int particionar(float vetor[], int inicio, int fim, int pivo);
void trocar(float *num1, float *num2);

int main(){
    float dados[10] = {10., 89., -5., 7.8, 5.6, .89, 9.0, 67., 2.2, 1.56};
    printf("Vetor fora de ordem:\n");
    exibirVetor(dados, 10);
    quicksort(dados, 0, 9);
    printf("Vetor em de ordem:\n");
    exibirVetor(dados, 10);
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
