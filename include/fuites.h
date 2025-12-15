#define FUITES_H

#include "main.h"
// Arbre K-aire
typedef struct Enfant {
    struct Troncon* noeud;
    struct Enfant* suivant;
} Enfant;

typedef struct Troncon {
    char *id;
    double volume;
    double fuite;
    int nb_enfants;
    Enfant *enfants;
} Troncon;

// Glossaire
typedef struct Glossaire {
    char *id;
    Troncon* adresse;
    int eq;
    struct Glossaire* fd;
    struct Glossaire* fg;
} Glossaire;

typedef struct Glossaire* pGlossaire;


