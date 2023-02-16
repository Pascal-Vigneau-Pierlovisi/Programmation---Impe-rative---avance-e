//
// Created by Pascal Vigneau on 23/11/2022.
//

#include <stdio.h>
#include <stdlib.h>

#define NB 100
int* fonctionX(){
    int tab[NB] = { 0 }; //...
    return tab;
}
int main(){
    int* t = fonctionX();
    for (int i = 0; i < NB; i++){
        t[i] = rand() % 100;
        printf("t[%d]=%d\n", i, t[i]);
    }
    return 0; }