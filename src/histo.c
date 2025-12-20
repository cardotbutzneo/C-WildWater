#include "../include/main.h"
#include "../include/histo.h"
#include "../include/fonction.h"
#include <string.h>

char* extraireID(const char* texte) {
    const char* pos = strchr(texte, '#');
    if (!pos) return NULL;
    pos++; // après '#'

    const char* fin = pos;
    while (*fin && *fin != ' ' && *fin != ';' && *fin != '\n' && *fin != '\r') fin++;

    size_t taille = fin - pos;
    char* id = malloc(taille+1);
    memcpy(id, pos, taille);
    id[taille] = '\0';
    return id;
}

void recuperersource(char* sauvegarde[5], char* ligne) {
    char* temp = strdup(ligne);   // duplique la ligne pour que strtok puisse la modifier
    char* token = strtok(temp, ";");
    int i = 0;

    while (token && i < 5) {
        sauvegarde[i] = strdup(token);   // alloue et copie la chaîne
        token = strtok(NULL, ";");
        i++;
    }

    free(temp);
}

pAVL ajouterAVLUsine(pAVL avl,pUsine usine){
    int h=0;
    avl = insertionAVL(avl,usine,&h);
    return avl;
}
