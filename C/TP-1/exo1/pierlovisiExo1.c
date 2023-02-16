//
// Created by Pascal Vigneau on 07/12/2022.
//
#include "listesTPExo1MainCodeDepart.h"


/*
 * La fonction menu() représente un menu dans lequel l'utilisateur va choisir ce qu'il souhaite effectuer.
 * L'utilisateur va rentrer son choix parmi plusieurs propositions.
 * @output : entier représentant le choix de l'utilisateur.
 */
int menu()
{
    int choix = 0;
    printf("1 Creer une liste d'entiers compris entre 0 et 20 de taille aleatoire comprise entre 1 et 20\n"
           "2 Ajouter un élément entier aléatoire (compris entre 0 et 20) en tête de liste\n"
           "3 Inserer un élément entier aléatoire dans sa place dans la liste suivant l'ordre croissant des premiers éléments\n"
           "4 Supprimer l'élément de tête\n"
           "5 Supprimer tous les maillons d'une valeur donnee\n"
           "6 Detruire liste\n"
           "7 Sauver la liste courante en binaire dans le fichier \"saveliste.bin\"\n"
           "8 Charger une liste depuis le fichier \"savelist.bin\"\n");

    scanf("%d", &choix);
    rewind(stdin);

    return choix;
}

/*
 * Fonction de lancement par défaut
 */
int main()
{
    maillon_int* premier = NULL;
    maillon_int* nouveau;
    int fin = 0;
    int i, nb;

    srand((unsigned)time(NULL));
    while (!fin) {
        i = menu();
        switch (i) {

            case 1: //Créer une liste de taille aléatoire
                nb =  1 + rand() % 20;
                if(premier != NULL){
                    detruire_liste(&premier);
                    for(i = 0; i < nb; i++){
                        nouveau = init_elt();
                        ajout_tete_v2(&premier, nouveau);
                    }
                    parcourir(premier);     // Affichage pour voir le bon fonctionnement
                }else{
                    for(i = 0; i < nb; i++){
                        nouveau = init_elt();
                        ajout_tete_v2(&premier, nouveau);
                    }
                    parcourir(premier);     // Affichage pour voir le bon fonctionnement
                }
                break;

            case 2: // Ajouter
                premier = init_elt();
                parcourir(premier);
                nouveau = init_elt();
                ajout_tete_v2(&premier, nouveau);
                parcourir(premier);
                break;

            case 3: // Inserer (ordre croissant)
                premier = init_elt();
                parcourir(premier);
                nouveau = init_elt();
                inserer2(&premier, nouveau);
                parcourir(premier);
                break;

            case 4: //Supprimer debut:
                nb =  1 + rand() % 20;
                if(premier != NULL){
                    detruire_liste(&premier);
                    for(i = 0; i < nb; i++){
                        nouveau = init_elt();
                        ajout_tete_v2(&premier, nouveau);
                    }
                    parcourir(premier);     // Affichage pour voir le bon fonctionnement
                    supprimer_debut(&premier);
                    parcourir(premier);

                }else{
                    for(i = 0; i < nb; i++){
                        nouveau = init_elt();
                        ajout_tete_v2(&premier, nouveau);
                    }
                    parcourir(premier);     // Affichage pour voir le bon fonctionnement
                    supprimer_debut(&premier);
                    parcourir(premier);
                }


                break;

            case 5: // Supprimer un maillon d'une valeur donnee
                nb =  1 + rand() % 20;
                if(premier != NULL){
                    detruire_liste(&premier);
                    for(i = 0; i < nb; i++){
                        nouveau = init_elt();
                        ajout_tete_v2(&premier, nouveau);
                    }
                    parcourir(premier);     // Affichage pour voir le bon fonctionnement
                    critere_supp_un2(&premier, 0);
                    parcourir(premier);

                }else{
                    for(i = 0; i < nb; i++){
                        nouveau = init_elt();
                        ajout_tete_v2(&premier, nouveau);
                    }
                    parcourir(premier);     // Affichage pour voir le bon fonctionnement
                    critere_supp_un2(&premier, 0);
                    parcourir(premier);
                }

                break;

            case 6: // detruire liste
                premier = init_elt();
                parcourir(premier);
                nouveau = init_elt();
                inserer2(&premier, nouveau);
                parcourir(premier);
                if(premier != NULL){
                    detruire_liste(&premier);
                }
                parcourir(premier);

                break;

            case 7: // Sauver liste
                nb =  1 + rand() % 20;
                if(premier != NULL){
                    detruire_liste(&premier);
                    for(i = 0; i < nb; i++){
                        nouveau = init_elt();
                        ajout_tete_v2(&premier, nouveau);
                        sauver_liste(premier);
                    }
                    parcourir(premier);     // Affichage pour voir le bon fonctionnement
                }else{
                    for(i = 0; i < nb; i++){
                        nouveau = init_elt();
                        ajout_tete_v2(&premier, nouveau);
                    }
                    parcourir(premier);     // Affichage pour voir le bon fonctionnement
                    sauver_liste(premier);
                }
                break;

            case 8: // Charger liste
                premier = load_liste();
                parcourir(premier);

                break;

            default:

                break;
        }

    }

    return 0;
}