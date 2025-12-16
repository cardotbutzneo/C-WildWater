#define FUITES_H

#include "main.h"
// Arbre K-aire
typedef struct enfant {
    struct Troncon* noeud;
    struct enfant* suivant;
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
int traitement_ligne_fuite(const char* buffer,char* parent_type, char* parent_id,char* enfant_type, char* enfant_id,char* service_type, char* service_id,char* dash, double* fuite);

