//
// Created by Pascal Vigneau on 07/12/2022.
//

#include "pile.h"

int main(){
    pile * p = init();
    printf("La pile est vide ? 1 = Oui / 0 = Non : %d \n", estVide(p));  // Test pour voir si la liste est vide 1 si OUI, sinon 0
    empilerElt(&p, 10);     // Je test d'empiler la valeur 10
    printf("Valeur au sommet : %d\n", afficherSommet(p));     // Je test l'affichage de la valeur au sommet de la pile
    printf("Valeur au sommet avant suppression : %d\n", afficherEtDelete(&p));
}