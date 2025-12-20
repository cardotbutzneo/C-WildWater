#ifndef FONCTION_H
#define FONCTION_H
#include "main.h"
#include "histo.h"
#define MAX_CMP 5

void printErreur(const char *format);
int trieDict(const void* a, const void* b);
pUsine* nUsinesOptimise(pAVL avl, int n, char *critere, int max, int *taille);
void remplirAVL(pAVL* avl);
void lireFichier(pAVL* avl);
void trim(char* str); // made by chatpgt
void ecrireUsine(pUsine *dict, int taille, char destination[64], int type);

#endif