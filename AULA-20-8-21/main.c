//complexidade do algoritimo medida pelo big O
//espa�o � a quantidade de coisas
//tempo � o tempo
//s�o formas diferentes de organizar dados, mas no fim o resultado � o mesmo
//QUICKSORT
//ordena por parti��o (reorganiza por partes)
//faz a troca entre elementos mais distantes entre si na lista
//faz n/2 trocas
//escolhe um piv� e a partir dele faz a organizacao com coisas maiores e menores em rela��o a ele

#include <stdio.h>
#include <stdlib.h>

//Prototipos de funcao
void quicksort(int vetor[], int inicio, int fim);
void exibirVetor(int vetor[], int tamanho);
int particionar(int vetor[], int inicio, int fim, int pivo);
void trocar(int *num1, int *num2);

int main(){
    int dados[10] = {10, 89, -5, 78, 56, 89, 90, 67, 22, 156};
    printf("Vetor fora de ordem:\n");
    exibirVetor(dados, 10);
    quicksort(dados, 0, 9);
    printf("Vetor em de ordem:\n");
    exibirVetor(dados, 10);
    return 0;
}

//Defini��o das fun��es
void exibirVetor(int vetor[], int tamanho){
    for(int i = 0; i < tamanho; i++)
        printf("%i: %i\n", i, vetor[i]);
}

void quicksort(int vetor[], int inicio, int fim){
    int pivo, novoPivo;
    if(inicio < fim){
        pivo = (inicio+fim)/2;
        novoPivo = particionar(vetor, inicio, fim, pivo);
        quicksort(vetor, inicio, novoPivo-1);
        quicksort(vetor, novoPivo+1, fim);
    }
}

void trocar(int *num1, int *num2){
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int particionar(int vetor[], int inicio, int fim, int pivo){
    int i, j;
    int valor_pivo = vetor[pivo];
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
