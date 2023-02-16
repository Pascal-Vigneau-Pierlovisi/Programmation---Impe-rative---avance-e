//
// Created by Pascal Vigneau on 07/12/2022.
//

// Question 1) Mon choix s'est orienté vers un tableau statique
// La taille est défini, on peut facilement empiler des éléments
// Et les récupérer par le biais de l'index qui dans le cas d'un tableau statique
// Donne un accès très rapide aux éléments stockés dans celui-ci a contrario du tableau chainé

#include "pile.h"

int estVide(pile * p){
    if(p->size == 0){
        return 1;
    }
    else{
        return 0;
    }
}

/*
 * Fonction d'initialisation de la pile
 * @output : pile*
 * La valeur de retour est un pointeur sur la pile
 */
pile * init(){
    pile * p = malloc(sizeof(pile));
    p->size = 0;
    p->maxSize = 100;
    return p;
}

/*
 * La Fonction permet d'empiler des éléments dans la pile
 * @output : void
 * Aucune valeur de retour tout se fait à l'intérieur de la fonction
 * avec un pointeur de pointeur
 */
void empilerElt(pile ** p,int val){
    if((*p)->size < 100){
        (*p)->tab[(*p)->size] = val;
        (*p)->top = val;
        (*p)->size++;
    } else{
        printf("%s", "La pile a atteint sa taille limite !");
    }
}

/*
 * La Fonction permet de récupérer la valeur au sommet de la pile
 * @output : int
 * La valeur de retour est un entier qui représente la valeur stockée au sommet de la pile
 */
int afficherSommet(pile *p){
    return p->top;
}

int afficherEtDelete(pile ** p){
    int temp = afficherSommet(*p);
    if((*p)->size == 0){
        printf("%s", " ⚠ La pile est vide !");
    }
    if((*p)->size == 1){
        (*p)->tab[(*p)->size] = 0;
        (*p)->size--;
        (*p)->top = 0;
    }else{
        (*p)->tab[(*p)->size] = 0;
        (*p)->size--;
        (*p)->top = (*p)->tab[(*p)->size - 1];
    }
    return temp;

}

