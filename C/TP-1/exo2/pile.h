//
// Created by Pascal Vigneau on 07/12/2022.
//

#ifndef __pile_h__
#define __pile_h__

#include <stdio.h>
#include <stdlib.h>

typedef struct pile{
    int size;
    int maxSize;
    int tab[20];
    int top;
}pile;

int estVide(pile * p);

void empilerElt(pile ** p,int val);

pile * init();

int afficherSommet(pile * p);

int afficherEtDelete(pile ** p);

#endif