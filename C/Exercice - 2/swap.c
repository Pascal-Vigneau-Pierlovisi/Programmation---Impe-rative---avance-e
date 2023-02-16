#include <stdio.h>

void swap_int(int *pt_1, int *pt_2){
    int *temp = pt_1;
    printf("%d", *temp);
    pt_1 = pt_2;
    printf("%d", *pt_1);

}

int main() {
    int a = 10;
    int b = 20;

    int *pointeur_1 = &a;
    int *pointeur_2 = &b;

    swap_int(pointeur_1, pointeur_2);

    //printf("Valeurs de A : %d | Valeur de B : %d", *pointeur_1, *pointeur_2);



}
