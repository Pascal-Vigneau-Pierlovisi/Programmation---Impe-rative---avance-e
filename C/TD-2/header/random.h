//
// Created by Pascal Vigneau on 30/11/2022.
//

#ifndef TD_2_RANDOM_H
#define TD_2_RANDOM_H

#endif //TD_2_RANDOM_H

// Fonction qui génère un nombre entier aléatoire selon la plage maximum du générateur aléatoire.
int randomMax();

// Fonction qui génère un nombre entier aléatoire compris entre 0 et une valeur "seuil haut" passée en
//paramètre.
int randomA(int nbMax);

//Fonction qui génère un nombre entier aléatoire entier compris entre deux bornes "seuil bas" et une valeur
//"seuil haut" passées en paramètres.
int randomB(int nbMin, int nbMax);

//Fonction qui génère un nombre réel aléatoire compris entre 0 et 1.
float randomOne();

//Fonction qui génère un nombre réel aléatoire à deux décimales compris entre deux bornes "seuil bas" et
//une valeur "seuil haut".
float randomNumber(float nbMin, float nbMax);

