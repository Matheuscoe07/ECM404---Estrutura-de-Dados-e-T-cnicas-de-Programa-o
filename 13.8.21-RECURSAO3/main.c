#include <stdio.h>
#include <stdlib.h>

//PROTOTIPOS
int fibonacci(int);

int main()
{
    int numero = 10;
    int resultado = fibonacci(numero);
    printf("O %i da seq de fibonacci eh %i\n", numero, resultado);
    return 0;
}

//DEFINICAO
int fibonacci(int numero){
    if(numero == 0)
        return 0;
    else if(numero == 1)
        return 1;
    else
        return fibonacci(numero-1) + fibonacci(numero-2);
}
