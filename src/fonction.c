#include "main.h"
#include "arbres.h"
#include "string.h"

void printErrreur(char *format){
    if (!format) return;
    char *buffer;
    snprintf(buffer,strlen(*format),format);
}

void récupérer_max(pAVL avl,Dictionnaire* dict){
    if (!avl) return;
    if (!dict){
    
    }
}