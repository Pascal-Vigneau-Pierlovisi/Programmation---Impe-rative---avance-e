//
// Created by Pascal Vigneau on 07/12/2022.
//

#ifndef __listesTPExo1MainCodeDepart_h__
#define __listesTPExo1MainCodeDepart_h__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>


/*
 * La struct maillon_int permet la création d'une liste.
 * val représente la valeur que l'on veut mettre dans la liste
 * p_suiv représente un pointeur sur le maillon suivant de la liste
 */

typedef struct maillon {
    int val;
    struct maillon* p_suiv;
}maillon_int;

maillon_int* init_elt();

maillon_int* ajout_tete_v1(maillon_int* p_tete, maillon_int* p_nv_elt);

void ajout_tete_v2(maillon_int** p_p_tete, maillon_int* p_nv_elt);

void parcourir(maillon_int* p_tete);

maillon_int* inserer1(maillon_int* p_tete, maillon_int* p_nv_elt);

void inserer2(maillon_int** prem, maillon_int* e);

void supprimer_debut(maillon_int** prem);

maillon_int* critere_supp_un1(maillon_int* prem, int val);

void critere_supp_un2(maillon_int** prem, int val);

void detruire_liste(maillon_int** prem);

void detruire_liste2(maillon_int** prem);

void sauver_liste(maillon_int* prem);

maillon_int* load_liste();

#endif