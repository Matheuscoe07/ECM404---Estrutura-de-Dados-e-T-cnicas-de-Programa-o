#include <stdio.h>
#include <stdlib.h>

//PROTOTIPOS
int multiplicacao(int, int);

int main()
{
    int num1, num2, resultado;
    num1 = 10;
    num2 = 3;
    resultado = multiplicacao(num1, num2);
    printf("O resultado de %i vezes %i eh %i\n", num1, num2, resultado);
    return 0;
}

//definicao
int multiplicacao(int num1, int num2){
    if(num2==0)
        return 0;
    else
        return num1 + multiplicacao(num1, num2-1);
}
