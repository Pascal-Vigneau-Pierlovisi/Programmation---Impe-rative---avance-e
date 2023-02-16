//
// Created by Pascal Vigneau on 30/11/2022.
//

//Link section
#include "header/fourmi.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

//Definition section
#define MAX_X = 401
#define MAX_Y = 401

//Main function
int main(int argc, char const *argv[])
{
    srand(time(NULL));
    ant a1 = init();
    read_p(a1);
    ant* pt = &a1;
    move(pt);
    read_p(a1);
}

ant init(){
    ant antA={rand() % 401, rand() % 201, -5 + rand() % 11, -5 + rand() % 11, rand() % 254 + 1, (char)(65 + rand() % 26)};
    return antA;
}

void move(ant * a){
    (*a).x = (*a).x + (*a).dx;
    (*a).y = (*a).y + (*a).dy;
}

void read_p(ant a){
    printf("x : %d | y : %d | dx : %d | dy : %d | color : %d | name %c \n", a.x, a.y, a.dx, a.dy, a.color, a.name);
}