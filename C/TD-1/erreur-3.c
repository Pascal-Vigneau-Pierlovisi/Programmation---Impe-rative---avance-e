//
// Created by Pascal Vigneau on 23/11/2022.
//

void main() {
    int *ptr;
    {
        int ch;
        ptr = &ch;
    }

    printf("%d\n", *ptr); }