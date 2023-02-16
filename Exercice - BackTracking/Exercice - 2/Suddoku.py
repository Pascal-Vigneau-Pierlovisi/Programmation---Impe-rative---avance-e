#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Oct 18 11:25:14 2022

@author: pascalvigneau
"""

import numpy as np
import math

Suddoku=np.loadtxt('Suddoku.txt')
Vides = np.where(Suddoku ==0)
trouve = False

def acceptable(Suddoku, x, y, e):
    if e in Suddoku[x]:
        return False
    if e in Suddoku[:,y]:
        return False
    pos_x = (x//3)*3
    pos_y = (y//3)*3
    tab = np.reshape(Suddoku[pos_x : pos_x+3, pos_y : pos_y+3], (9))
    if e in tab:
        return False
    
    return True

def fill_suddoku(Suddoku, Vides, num):
    global trouve
    if num == len(Vides[0]):
        trouve=True ; return
    for e in range(1, 10):
            x = Vides[0][num]
            y = Vides[1][num]
            if acceptable(Suddoku, x, y, e):
                Suddoku[x, y]=e
                fill_suddoku(Suddoku, Vides, num+1)
                if trouve==True:
                    return
                Suddoku[x, y]=0
            
            
if __name__ == '__main__':
    fill_suddoku(Suddoku, Vides, 0)