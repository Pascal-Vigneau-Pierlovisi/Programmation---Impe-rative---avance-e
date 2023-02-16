#include <stdio.h>

typedef struct coord
{
    int x, y;
}Coord;

void modif(Coord *pt)
{
    (*pt).x++;
    if((*pt).x > 1000){
        (*pt).x = 0;
    }
}



int main() {
    Coord p={1001,20};
    printf("p.x=%d, p.y=%d\n", p.x, p.y);
    Coord* pt = &p;
    modif(pt);
    printf("p.x=%d, p.y=%d\n", p.x, p.y);
    return 0;
}
