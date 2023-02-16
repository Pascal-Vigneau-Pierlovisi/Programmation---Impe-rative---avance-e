#include "listesTPExo1MainCodeDepart.h"


/*
 * Initialisation d'un maillon
 * Le malloc permet de créer un espace mémoire alloué pour un maillon_int
 * @output : maillon_int*
 * La valeur de retour est un pointeur sur un élément de la liste
 */
maillon_int* init_elt()
{
    maillon_int* p_nv_elt = malloc(sizeof(maillon_int));
    p_nv_elt->val = rand() % 21;
    p_nv_elt->p_suiv = NULL;
    return p_nv_elt;
}

/*
 * Permet de mettre un maillon en tête de liste
 * @input : maillon_int * p_tete, pointeur sur l'élément de tête de la liste
 * @input : maillon_int * p_nv_elt, pointeur sur un maillon de la liste
 * L'attribut p_suiv de p_nv_elt prend pour valeur un pointeur sur l'ancien premier élément de la liste
 * p_tete prend pour valeur p_nv_elt
 * @output : maillon_int*
 * La valeur de retour est un pointeur sur un élément de la liste
 */
maillon_int* ajout_tete_v1(maillon_int* p_tete, maillon_int* p_nv_elt)
{
    p_nv_elt->p_suiv = p_tete;
    p_tete = p_nv_elt;
    return p_tete;
}

/*
 * Permet de changer l'élément en tête de liste
 * @input : maillon_int ** p_p_tete, pointeur de pointeur sur l'élément de tête de la liste
 * @input : maillon_int * p_nv_elt, pointeur sur un maillon de la liste
 * Le pointeur de pointeur permet de modifier directement ici l'élément de la liste sans passer par un retour
 * @output : void
 */
void ajout_tete_v2(maillon_int** p_p_tete, maillon_int* p_nv_elt)
{
    p_nv_elt->p_suiv = *p_p_tete;   // L'attribut p_suiv du pointeur qui est pointé prend pour valeur le pointeur qui est pointé sur p_p_tete
    *p_p_tete = p_nv_elt;           // La valeur du pointeur qui est pointé *p_p_tete va pointer vers p_nv_elt
}

/*
 * Permet de lire toutes les valeurs présentent dans la liste
 * @input : maillon_int * p_tete, pointeur sur l'élément de tête de la liste
 * @precondition : Si une liste est vide, on aura un affichage en console qui permettra de savoir que la liste est vide
                    Si la liste n'est pas vide, on affichera tous les éléments de cette liste
 * @output : void
 */
void parcourir(maillon_int* p_tete)
{
    if (p_tete == NULL)
        printf("liste vide");
    else
        while (p_tete != NULL) {
            printf("%d--", p_tete->val);
            p_tete = p_tete->p_suiv;
        }
    putchar('\n');
}

/*
 * Permet d'insérer un élément dans la liste
 * @input : maillon_int * p_tete, pointeur sur l'élément de tête de la liste
 * @input : maillon_int * p_nv_elt, pointeur sur un élément de la liste
 * @output : *maillon_int
 * La valeur de retour est un pointeur sur l'élément en tête de liste
 */
maillon_int* inserer1(maillon_int* p_tete, maillon_int* p_nv_elt)
{
    maillon_int* n, * prec;     // Deux variables locales non initialisées
    
    if (p_tete == NULL || p_nv_elt->val <= p_tete->val) {   // Si le pointeur de tête de liste est NULL
        p_nv_elt->p_suiv = p_tete;                          // p_suiv va prendre pour valeur la valeur pointée par p_tete
        p_tete = p_nv_elt;                                  // p_tete va prendre pour valeur p_nv_elt
    }
    else {                      // Sinon
        n = prec = p_tete;
        while (n != NULL && p_nv_elt->val > n->val) {       // Tant que l'attribut p_suiv d'un maillon n'est pas NULL et l'attribut val de p_nv_elt > à celui de n
            prec = n;
            n = n->p_suiv;
        }
        p_nv_elt->p_suiv = n;
        prec->p_suiv = p_nv_elt;
    }
    return p_tete;
}

/*
 * Permet d'insérer un élément dans la liste
 * @input : maillon_int ** prem, pointeur de pointeur sur le premier élément de la liste
 * @input : maillon_int * e, pointeur sur un élément de la liste
 * @output : void
 * Aucune valeur de retour les modifications des valeurs se font directement dans la fonction par le biais du pointeur de pointeur
 */
void inserer2(maillon_int** prem, maillon_int* e)
{
    maillon_int* n, * prec;     // Déclaration de deux variables n'ayant pas de valeur pour le moment
    if (*prem == NULL || e->val <= (*prem)->val){   // Si le pointeur pointé par prem est NULL ou la valeur de "e" est inférieur ou égale à la valeur de l'attribut du pointeur pointé.
        e->p_suiv = *prem;                          // L'attribut p_suiv de "e" prend pour valeur le pointeur pointé
        *prem = e;                                  // Le pointeur pointé prend pour valeur "e"
    }
    else {                      // Sinon
        n = prec = *prem;
        while (n != NULL && e->val > n->val) {      // Tant que "n" n'est pas NULL et que l'attribut val de "e" est supérieur à l'attribut val de "n"
            prec = n;
            n = n->p_suiv;
        }
        e->p_suiv = n;
        prec->p_suiv = e;
    }
}

/*
 * Permet de supprimer le premier élément de la liste
 * @input : maillon_int ** prem, pointeur de pointeur sur le premier élément de la liste
 * @precondition : La liste ne doit pas être vide pour utiliser cette fonction avec utilité
 * @output : void
 * Pas de retour de fonction néanmoins un free() est présent permettant de libérer la mémoire d'un pointeur
 */
void supprimer_debut(maillon_int** prem)
{
    maillon_int* n;     // Déclaration d'une variable locale sans affectation
    if (*prem != NULL) {    // Si le pointeur pointé est différent de NULL
        n = *prem;          // n prend pour valeur le pointeur pointé
        *prem = (*prem)->p_suiv;    // Le pointeur pointé prend pour valeur la valeur de l'attribut p_suiv du pointeur pointé
        free(n);                    // Libération de l'espace mémoire
    }
}

/*
 * Permet la suppression d'un/des maillon(s) ayant pour valeur "val"
 * @input : maillon_int *prem, pointeur sur le premier élément de la liste
 * @input : int val, valeur représentant un entier
 * @output : maillon_int*
 * La valeur de retour est un pointeur sur le premier élément de la liste
 */
maillon_int* critere_supp_un1(maillon_int* prem, int val)
{
    maillon_int* e = prem, * prec = NULL, * n;      // Déclaration de 3 variables locales

    while (e != NULL) {     // Tant que le pointeur "e" n'est pas NULL
        n = NULL;
        if (e->val == val) {        // Si l'attribut val de "e" est égal à la valeur "val" passé en paramètre
            n = e;
            if (prec == NULL)       // Si le pointeur prec est NULL
                prem = e->p_suiv;   // prem va prendre la valeur de l'attribut p_suiv de "e"
            else                    // Sinon
                prec->p_suiv = e->p_suiv;   // L'attribut p_suiv du maillon pointé par prec prend la valeur de l'attribut p_suiv du maillon pointé par "e"
        }
        else        // Sinon
            prec = e;
        e = e->p_suiv;      // Le pointeur "e" prend pour valeur le pointeur affecté à l'attribut p_suiv de "e"
        if (n != NULL)      // Si "n" différent de NULL
            free(n);        // On libère l'espace mémoire du pointeur "n"
    }
    return prem;

}

/*
 * Permet de supprimer un/des élement(s) de la liste comprenant ayant pour "val" la valeur du paramètre val de la fonction
 * @input : maillon_int ** prem, pointeur de pointeur sur le premier élément de la liste
 * @input : int val, valeur représentant un entier
 * @output : void
 * Aucune valeur de retour la suppression de l'élément de la liste se fait directement dans la fonction
 */
void critere_supp_un2(maillon_int** prem, int val)
{
    maillon_int* e = *prem, * prec = NULL, * n;     // Déclaration de trois variables locales

    while (e != NULL) {     // Tant que le pointeur "e" est NULL
        n = NULL;
        if (e->val == val) {    // Si l'attribut val de l'élément pointé par "e" est égal à "val"
            n = e;          // "n" prend pour valeur le pointeur "e"
            if (prec == NULL)   // Si le pointeur prec est NULL
                *prem = e->p_suiv;  // Le pointeur pointé par "prem" prend pour valeur le pointeur attribué à p_suiv de l'élément pointé par "e"
            else        // Sinon
                prec->p_suiv = e->p_suiv;       // L'attribut p_suiv pointé par "prec" prend pour valeur le pointeur attribué à p_suiv pointé par "e"
        }
        else    // Sinon
            prec = e;       // Le pointeur "prec" va pointer au même endroit que le pointeur "e"
        e = e->p_suiv;      // Le pointeur "e" va prendre pour valeur le pointeur p_suiv que le pointeur "e" pointe
        if (n != NULL)      // Si le pointeur "n" est différent de NULL
            free(n);        // On libère la mémoire
    }
}

/*
 * Permet de détruire une liste
 * @input : maillon_int** prem, pointeur de pointeur sur le premier élément de la liste
 * @output : void
 * Aucune valeur de retour, cette fonction permet de supprimer une liste
 */
void detruire_liste(maillon_int** prem)
{
    maillon_int* n;     // Déclaration d'une variable locale qui sera un pointeur
    while (*prem != NULL) {     // Tant que le pointeur pointé par "prem" est différent de NULL
        n = *prem;      // Le pointeur "n" prend pour valeur le pointeur pointé par "prem"
        *prem = (*prem)->p_suiv;    // Le pointeur pointé par "prem" prend pour valeur la valeur de l'attribut p_suiv pointé par le pointeur pointé
        free(n);    // Suppression de l'espace mémoire "n"
    }
}

void detruire_liste2(maillon_int** prem)
{
    while (*prem != NULL)
        supprimer_debut(prem);
    
}

/* Permet la sérialisation format binaire dans le fichier
"saveliste.bin" de la liste d'entier (maillon_int) dont
le pointeur sur le premier élément est passé en paramètre
@input : maillon_int * prem, pointeur sur l'élément de tête de la liste à sérialiser
@output : void
@precondition : le répertoire courant et le processus père permettent l'écriture 
                le pointeur prem, est soit NULL (aucune action) soit pointe sur
                le premier élément d'une liste d'entiers
@postcondition : le fichier saveliste.bin contient les éléments de la liste 
                dont le premier élément est pointé par prem. 
                Nota : il n'y a pas de libération de la mémoire occupée par la 
                liste. Il faut donc la détruire avant d'éventuellement la recharger.
*/
void sauver_liste(maillon_int* prem)
{
    //ouvrir un fichier binaire en écriture : suffixe b
    FILE* f=fopen("saveliste.bin", "wb");
    printf("Ouvertude du fichier %p\n",f);
    // si liste non vide
    if (prem != NULL) {
        if (f==NULL)
            fprintf(stderr,"erreur création fichier :%i\n",errno);
        else // parcourir la liste jusque fin
            while (prem != NULL) {
                // écrire chaque maillon en binaire
                if (1 !=fwrite(prem, sizeof(maillon_int), 1, f))
                    fprintf(stderr,"Erreur d'écriture du maillon %p\n",prem);
                else 
                // passer au maillon suivant
                prem = prem->p_suiv;
            }
            fclose(f);	// fermer le fichier
    }
    else
        fprintf(stderr,"pas de sauvegarde pour une liste vide\n");
}

/*
 * Permet de charger la liste
 * Aucun paramètre nécessaire
 * @output : maillon_int*
 * La valeur de retour est pointeur pointant vers un maillon qui représentera le premier maillon de la liste
 */
maillon_int* load_liste()
{
    FILE* f;    // Déclaration d'un pointeur
    maillon_int* prem = NULL, * p, e;
    if ((f= fopen("saveliste.bin", "rb")) != NULL) {    // Si le contenu du fichier est différent de NULL
        prem = malloc(sizeof(maillon_int));     // Allocation mémoire
        fread(prem, sizeof(maillon_int), 1, f);
        p = prem;   // Le pointeur "p" prend pour valeur la même chose que le pointeur "prem"
        while (fread(&e, sizeof(maillon_int), 1, f)) {  // Tant que l'on peut lire le fichier
            p->p_suiv = malloc(sizeof(maillon_int));
            p = p->p_suiv;
            *p = e;
            p->p_suiv = NULL;
        }
        fclose(f);      // Fermeture du fichier
    }
    else    // Sinon
        printf("erreur ou fichier inexistant");     // Message d'erreur
    return prem;
}
