//
// Created by Pascal Vigneau on 23/11/2022.
//

#include <stdio.h>
int value = 5;

int main(){
    int *p = &value;
    fflush(stdin); printf("%d\n", *p); return 0;
}