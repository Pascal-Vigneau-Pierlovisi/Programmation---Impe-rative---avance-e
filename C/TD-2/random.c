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
    printf("number %i\n", randomMax());
    printf("number %i\n", randomA(10));
    printf("number %i\n", randomB(10, 20));
    printf("number %f\n", randomOne());
    printf("number %f\n", randomNumber(1.21, 2.33));

}

int randomMax(){
    return rand();
}

int randomA(int nbMax){
    return rand() % (nbMax + 1);
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



