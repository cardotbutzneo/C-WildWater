#ifndef HISTO_H
#define HISTO_H

#include "main.h"

typedef struct _token_liste{
    char token[256];
    struct _token_liste* suivant;
}Token_liste;

void recuperersource(char* sauvegarde, char* ligne);

#endif