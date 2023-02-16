#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Oct 18 11:15:57 2022

@author: pascalvigneau
"""

import numpy as np
import math

Reseau = np.loadtxt('Reseaux.txt')
fp = open('Reseaux.txt', 'r')
line = fp.readline()
sommets = line[1:].split()
fp.close()

PCC=[]; km_min=math.inf
Depart = 0; Arrive = 5
Chemin = [] ; Chemin.append(Depart) ; km = 0

def acceptable(Chemin, km, ei, e):
    global PCC, km_min, Reseau
    if e in Chemin:
        return False
    if Reseau[ei, e]==0:
        return False
    if(km+Reseau[ei, e])>km_min:
        return False
    return True

def Plus_court_chemin(Chemin, km, ei):
    global pcc, km_min, Reseau, Arrive
    if ei == Arrive:
        if km < km_min:
            km_min = km
            pcc = Chemin.copy()
            print(pcc, Chemin)
            return
    for e in range(len(Reseau)):
        if acceptable(Chemin, km, ei, e):
            Chemin.append(e)
            km +=Reseau[ei, e]
            Plus_court_chemin(Chemin, km, e)
            del Chemin[-1]
            km -= Reseau[ei, e]

Plus_court_chemin(Chemin, km, 0)
