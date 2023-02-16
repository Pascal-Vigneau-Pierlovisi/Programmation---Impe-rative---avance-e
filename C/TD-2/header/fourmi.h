//
// Created by Pascal Vigneau on 30/11/2022.
//

#ifndef TD_2_FOURMI_H
#define TD_2_FOURMI_H

#endif //TD_2_FOURMI_H

typedef struct{
    int x;
    int y;
    int dx;
    int dy;
    int color;
    char name;
}ant;

ant init();

void move(ant* a);

void read_p(ant a);

