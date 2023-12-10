//RECURSIVIDADE --> resolver um problema reduzindo ele (simplificando)
// um problema grandao vc resolve em pedacinhos ate que vc "sem querer" arruma o problema grande
//deve haver uma base e a partir dessa base vc parte pra recursão
//arvore de recursao --> representacao grafica do problema "de cima pra baixo" e "de baixo pra cima"
//

#include <stdio.h>
#include <stdlib.h>

//PROTOTIPOS
int fatorial(int);

int main()
{
    int valor, resultado;
    valor = 7;
    resultado = fatorial(valor);
    printf("O fatorial de %i vale %i\n", valor, resultado);
    return 0;
}

//funcoes
int fatorial(int numero){
    if(numero == 0)
        return 1;
    else
        return numero * fatorial(numero - 1);
}
