#include <stdio.h>
#include "stdlib.h"
#include <time.h>

typedef struct maillon_int {
    int val;
    struct maillon_int* next;
}maillon_in;

// Initialiser un élément
maillon_in* init_element(){

    maillon_in *Nouveau;

    Nouveau = NULL;

    Nouveau = (maillon_in*)malloc(sizeof(maillon_in));

    Nouveau->val = rand();

    Nouveau->next = NULL;

    return Nouveau;

}

void insert_head_elt(maillon_in ** head_lst){
    maillon_in* new_elem = init_element();
    new_elem->next= *head_lst;
    *head_lst = new_elem;
}

void afficherListe(maillon_in * liste)
{
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    maillon_in actuel = *liste;

    while (actuel.next != NULL)
    {
        printf("%d -> ", actuel.val);
        actuel = *actuel.next;
    }
    printf("NULL\n");
}

int main(){
    srand(time(NULL));
    maillon_in* lst_head;
    maillon_in *premier=NULL;
    premier = init_element();
    for(int i = 0; i < 10; i++){
        insert_head_elt(&premier);
        afficherListe(premier);
    }
    free(premier);
    return 0;

}