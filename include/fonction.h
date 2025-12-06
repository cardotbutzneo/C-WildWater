#ifndef FONCTION_H
#define FONCTION_H
#include "main.h"
#include "histo.h"
#define MAX_CMP 5

void printErrreur(char *format);
void récupérer_max(pAVL avl, Dictionnaire dict[MAX_CMP], int* cmp_max);
void récupérer_max(pAVL avl, Dictionnaire dict[MAX_CMP], int* cmp_max);
Token_liste* ouvrir_fichier(char* nom_fichier);

#endif