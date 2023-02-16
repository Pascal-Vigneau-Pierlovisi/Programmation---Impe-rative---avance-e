#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Nov 16 10:40:57 2022

@author: pascalvigneau
"""

import numpy as np
import random as rd
import math


class CSP():
    def __init__(self, file_name):
        filin = open(file_name, "r") 
        self.Pays = filin.readline().split() ; self.size = len(self.Pays)
        self.Contraintes = np.zeros((self.size,self.size), dtype=int)
        self.Domaine = [] ; self.Variables = []
        lines = filin.readlines() ; filin.close()
        for line in lines:
            frontieres = line.split() ; indx = self.Pays.index(frontieres[0])
            indFrontaliers = [self.Pays.index(s) for s in frontieres[1:]]
            for indy in indFrontaliers : self.Contraintes[indx,indy]=1
            self.Domaine.append(["Rouge", "Bleu", "Vert", "Jaune"])
            self.Variables.append("")
            
    def MRV(self):
        nonAffecte = [s for s in range(self.size) if self.Variables[s]==""]
        if len(nonAffecte)==0 : return [], True
        minMRV = min([len(self.Domaine[s]) for s in nonAffecte])
        MRVs = [s for s in nonAffecte if len(self.Domaine[s])==minMRV]
        if len(MRVs)==1 : return MRVs, False
        Degrees = []
        for s in MRVs:
            Degrees.append( sum(self.Contraintes[s][x] for x in range(self.size) if self.Variables[x]=="")) 
        DHs = [ MRVs[s] for s in range(len(MRVs)) if Degrees[s]==max(Degrees) ]
        return DHs, False
    
    def nextValue(self, indS):
        minValide = []
        NAffs = [s for s in range(self.size) if self.Contraintes[indS, s]!=0 and self.Variables[s]==""]
        if len(NAffs)==0 : return self.Domaine[indS]
        for v in self.Domaine[indS] : minVal = math.inf
        for s in NAffs:
            val = len(self.Domaine[s])
            if v in self.Domaine[s] : val -=1
            if val < minVal : minVal = val
            minValide.append(minVal)
        valeursValides = self.Domaine[indS][:]
        while (0 in minValide) : pos = minValide.index(0) ; del minValide[pos] ; del valeursValides[pos]
        valeursTries = [X for Y, X in sorted(zip(minValide,valeursValides), reverse=True)]
        return valeursTries 
            
europe = CSP("Europe.txt")
Termine = False

def backtracking_search():
    global europe, termine
    listeVariables, Termine = europe.MRV()
    if Termine==True : return
    S = rd.choice(listeVariables)
    listeValeurs = europe.nextValue(S)
    for V in listeValeurs:
        europe.Variables[S]=V
        domainesModifies = [x for x in range(europe.size) if europe.Contraintes[S,x]!=0 and 
		europe.Variables[x]=="" and V in europe.Domaine[x]]
        for indS in domainesModifies:
            indV = europe.Domaine[indS].index(V)
            del europe.Domaine[indS][indV]
        backtracking_search()
        if (Termine==True) : return
        for indS in domainesModifies:
            europe.Domaine[indS].append(V)
        europe.Variables[S]=""

backtracking_search()