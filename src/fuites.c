#include "../include/main.h"
#include "../include/fuites.h"
#include <string.h>

/*
pGlossaire creerGlossaire(const char* id, Troncon* adresse){ {
    if (adresse == NULL || id == NULL){ {
        return NULL;
    }
    pGlossaire nouveau = malloc(sizeof(Glossaire));
    if (nouveau == NULL){
        printf("Erreur d'allocation de mémoire");
        exit(1);
    }
    nouveau->id=strdup(id);
    nouveau->adresse=adresse;
    nouveau->fg=NULL;
    nouveau->fd=NULL;
    nouveau->eq=0;
    return nouveau;
}

pGlossaire rotationGauche(pGlossaire a){
    pGlossaire pivot = a->fd;
    int eq_a = a->eq, eq_p = pivot->eq;
    a->fd = pivot->fg;
    pivot->fg = a;
    if (eq_p>0) {
        a->eq = eq_a-eq_p-1;
    } else {
        a->eq = eq_a-0-1; 
    }
    int x = eq_a-2;
    int y = eq_a+eq_p-2;
    int z = eq_p-2;
    if (x <= y && x <= z){
        eq_p = x;
    } else if (y <= x && y <= z) {
    eq_p = y;
    } else if (z <= x && z <= y) {
        eq_p = z;
    }
    return pivot;
}

pGlossaire rotationDroite(pGlossaire a){
 pGlossaire pivot = a->fg;
 int eq_a = a->eq, eq_p = pivot->eq;
 a->fg = pivot->fd;
 pivot->fd = a;
 if (eq_p<0) {
   a->eq = eq_a-eq_p+1;
 } else {
    a->eq = eq_a-0+1; 
 }
 int x = eq_a-2;
 int y = eq_a+eq_p-2;
 int z = eq_p-2;
 if (x >= y && x >= z){
    eq_p = x;
 } else if (y >= x && y >= z) {
    eq_p = y;
 } else if (z >= x && z >= y) {
    eq_p = z;
 }
 return pivot;
}
 pGlossaire doubleRotationGauche(pGlossaire a){
   a->fd = rotationDroite(a->fd);
   return rotationGauche(a);
 }

pGlossaire doubleRotationDroite(pGlossaire a){
   a->fg = rotationGauche(a->fg);
   return rotationDroite(a);
 }

pGlossaire equilibrerGlossaire(pGlossaire a) {
    if (a->eq >= 2) {
        if (a->fd->eq >= 0) {
           return rotationGauche(a); 
        } else {
            return doubleRotationGauche(a); 
        }
    } else if (a->eq <= -2) {
        if (a->fg->eq <= 0) {
            return rotationDroite(a); 
        } else {
            return doubleRotationDroite(a);
        }
    }
    return a; 
}

pGlossaire insertionGlossaire(pGlossaire a, Troncon* adresse, const char* id, int *h){
    if (a == NULL){
        *h=1;
        return creerGlossaire(id, adresse);
    }
    if (strcmp(id, a->id) < 0){
        a->fg=insertionGlossaire(a->fg, adresse, id, h);
        *h=-*h;
    }
    else if (strcmp(id, a->id) > 0){
        a->fd=insertionGlossaire(a->fd, adresse, id, h);
    } else {
        *h=0;
        return a;
    }
    if(*h != 0){
        a->eq += *h;
        a=equilibrerGlossaire(a);
        if(a->eq == 0){
            *h=0;
        } else {
            *h=1;
        }
    }
    return a;
}

void libererGlossaire(pGlossaire a){
    if(a == NULL){
       return;
    }
    if(a->fd != NULL){
       libererGlossaire(a->fd);
    }
    if(a->fg != NULL){
       libererGlossaire(a->fg);
    }
    free(a->adresse);
    free(a->id);
    free(a); 
}

Troncon* rechercheGlossaire(pGlossaire a, const char* id) {
    if (!a || !id){
        return NULL;
    }
    int comparateur = strcmp(id,a->id);
    if (comparateur == 0){
        return a->adresse;
    }
    if (comparateur < 0){
        return rechercheGlossaire(a->fg,id);
    }
    else {
        return rechercheGlossaire(a->fd,id);
    }
    return NULL;
}

Troncon* creerTroncon(const char *id, double fuite){
    Troncon* nouveau = malloc(sizeof(Troncon));
    if (nouveau == NULL){
        printf("Erreur d'allocation de mémoire");
        exit(1);
    }
    nouveau->id = strdup(id);
    nouveau->fuite = fuite;
    nouveau->volume = 0.0;
    nouveau->nb_enfants = 0;
    nouveau->enfants = NULL;
    return nouveau;
}
*/
