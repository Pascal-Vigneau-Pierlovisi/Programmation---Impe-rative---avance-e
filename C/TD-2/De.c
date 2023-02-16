//
// Created by Pascal Vigneau on 30/11/2022.
//

//Link section
#include "header/random.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>



//Main function
int main(int argc, char const *argv[])
{
    srand(time(NULL));
    printf("Combien de Dé voulez vous lancer ? 1 | 2 | 3 | 4 ? ");
    int nbDe;
    scanf("%i", &nbDe);
    int win = ((nbDe * 6) / 3) * nbDe;
    int equal = 0;

    for(int i = 0; i < nbDe; i++){
        equal = equal + randomA(6);
        printf("%i\n", equal);
    }

    if(equal >= win){
        printf("C'est la WIN");
    }else{
        printf("Il manquait : %i pour avoir la valeur gagnante", win-equal);
    }
}

int randomMax(){
    return rand();
}

int randomA(int nbMax){
    return  1 + (rand() % (nbMax + 1));
}

int randomB(int nbMin, int nbMax){
    return nbMin + (rand() % ((nbMax + 1) - nbMin));
}

float randomOne(){
    return (float)rand() / (float)RAND_MAX;
}

float randomNumber(float nbMin, float nbMax){
    return nbMin + randomOne() * (nbMax - nbMin);
}

