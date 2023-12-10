#include <stdio.h>
#include <stdlib.h>

//int main(){
//    int idade;
//    float preco;
//    printf("Ola mundo!\n");
//    //Atribuição a uma variável
//    idade = 33;
//    printf("A idade do usuario e: %i\n", idade);
//    if(idade  % 2 == 0){
//        preco = 15.45;
//    } else {
//        preco = 30.76;
//    }
//    printf("O valor do preco: %.3f\n", preco);
//    return 0;
//}

#include <stdio.h>

//Prototipos das funções
float soma(float, float);
float subtracao(float, float);
float multiplicacao(float, float);
float divisao(float, float);
void calculadora(int, float, float);
void menu();
int main(){
    int opcao;
    float num1, num2;
    while(1){
        menu();
        scanf("%i", &opcao);
        if(opcao == 0)
            break;
        printf("Informe dois operados:");
        scanf("%f%f", &num1,&num2);
        calculadora(opcao, num1, num2);
    }
    return 0;
}

//Definição das funções
float soma(float num1, float num2){
    return num1+num2;
}

float subtracao(float num1, float num2) {
    return num1-num2;
}
float multiplicacao(float num1, float num2){
    return num1*num2;
}
float divisao(float num1, float num2){
    return num1/num2;
}

void calculadora(int op, float num1, float num2){
    switch(op){
        case 1:
            printf("O resultado da soma: %.3f\n", soma(num1, num2));
            break;
        case 2:
            printf("O resultado da subtracao: %.3f\n", subtracao(num1, num2));
            break;
        case 3:
            printf("O resultado da multiplicacao: %.3f\n", multiplicacao(num1, num2));
            break;
        case 4:
            printf("O resultado da divisao: %.3f\n", divisao(num1, num2));
            break;
        default:
            printf("Algo de errado aconteceu, talvez uma opcao invalida!\n");
            break;
    }
}

void menu(){
    printf("Calculadora Maua\n");
    printf("1 - Somar\n");
    printf("2 - Subtrair\n");
    printf("3 - Multiplicar\n");
    printf("4 - Dividir\n");
    printf("0 - Sair\n");
    printf("Escolha sua opcao:");
}
