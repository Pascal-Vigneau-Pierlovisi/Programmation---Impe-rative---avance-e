/*
    Documentation section
    @Project Geometrie en L3 
    @Author Marie-Laure Nivet
    @Created 20221010
    @Program Description, Program to compute the area of a cirlce
*/

//Link section
#include <stdio.h>

//Definition section
#define PI 3.14159

#define carre(r) r*r
#define surface(r) (PI*carre(r))

//Global declaration section

//Function prototype declaration section
void message();
//Sub functions
void message(){
    printf("Ceci est une sous-fonction \n");
    printf("Il peut y en avoir plusieurs \n");
}

