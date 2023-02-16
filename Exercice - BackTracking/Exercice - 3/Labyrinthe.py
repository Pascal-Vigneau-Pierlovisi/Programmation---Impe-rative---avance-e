#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Oct 18 11:25:14 2022

@author: pascalvigneau
"""

import numpy as np

Labyrinthe = np.loadtxt('Labyrinthe.txt', dtype=int)

xa = len(Labyrinthe[0]) - 1
ya = len(Labyrinthe[:, 0]) - 1
trouve = False


def acceptable(Labyrinthe, x, y):
    if x == -1 or y == -1:
        return False
    if x == len(Labyrinthe[0]) or y == len(Labyrinthe[:][0]):
        return False
    if Labyrinthe[x, y] == 0:
        return True


def trouver_sortie(Labyrinth, x, y):
    global xa, ya, trouve
    if x == xa and y == ya:
        trouve = True
        return
    for e in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
        xn = x + e[0]
        yn = y + e[1]
        if acceptable(Labyrinthe, xn, yn):
            Labyrinth[x, y] = 1
            trouver_sortie(Labyrinth, xn, yn)
            if trouve == True:
                return
            Labyrinth[x, y] = 0


if __name__ == '__main__':
    trouver_sortie(Labyrinthe, 0, 0)
    print(Labyrinthe)
