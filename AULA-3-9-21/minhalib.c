//Aqui ficam definidos os comportamentos das funções
#include "minhalib.h"
#include <stdio.h>
#include <stdlib.h>

void olaMundo(){
    printf("Ola Mundo de dentro da lib!\n");
}

void tchauMundo(char s[]){
    printf(" Bom FDS %s! \n", s);
}
float calcular(float base, float altura){
    return base*altura / 2;
}
