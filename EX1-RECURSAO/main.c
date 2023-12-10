#include <stdio.h>
#include <stdlib.h>
#define N 10

//PROTOTIPO
int somavetor(int[], int);

int main()
{
    int vetor[N] = {1,2,3,4,5,6,7,8,9,10};
    printf("A soma eh %i\n", somavetor(vetor, 10));
    return 0;
}

//DEFINIÇÕES
int somavetor(int vetor[N], int tamanho){
    if(tamanho == 0)
        return 0;
    else
        return vetor[tamanho - 1] + somavetor(vetor, tamanho - 1);
}
