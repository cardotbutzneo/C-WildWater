#include "main.h"
#include "arbres.h"
#include "histo.h"
#include <string.h>
#include <time.h>
  

void printErreur(const char *msg) {
    if (!msg) return;
    time_t t = time(NULL);
    struct tm *date = localtime(&t);
    char champ_date[32];
    strftime(champ_date, sizeof(champ_date), "%Y-%m-%d %H:%M:%S", date);

    fprintf(stderr, "[%s] Erreur : %s\n", champ_date, msg);
}

// made by chatgpt (j'ai compris !)
// Fonction utilitaire pour trouver l'index de la valeur extrême dans le tableau
int indexExtreme(pUsine* tab, int n, int max, int critere) {
    int idx = 0;

    for (int i = 1; i < n; i++) {
        unsigned long va, vb;

        switch (critere) {
            case 0: va = tab[i]->capacite;    vb = tab[idx]->capacite;    break;
            case 1: va = tab[i]->v_capte;     vb = tab[idx]->v_capte;     break;
            case 2: va = tab[i]->v_traite;    vb = tab[idx]->v_traite;    break;
        }

        if ((max && va < vb) || (!max && va > vb))
            idx = i;
    }
    return idx;
}

void remplirTopN(pAVL avl, pUsine* top, int n, int *cmp, char *critere, int max) {
    if (!avl) return;

    remplirTopN(avl->fg, top, n, cmp, critere, max);

    int crit = (strcmp(critere, "capacite") == 0) ? 0 :
               (strcmp(critere, "v_capte") == 0) ? 1 :
               (strcmp(critere, "v_traite") == 0) ? 2 : -1;

    unsigned long val =
        (crit == 0) ? avl->usine->capacite :
        (crit == 1) ? avl->usine->v_capte :
                       avl->usine->v_traite;

    // Si on n’a pas encore rempli
    if (*cmp < n) {
        top[*cmp] = avl->usine;
        (*cmp)++;
    }
    else {
        int idx = indexExtreme(top, n, max, crit);

        unsigned long vref =
            (crit == 0) ? top[idx]->capacite :
            (crit == 1) ? top[idx]->v_capte :
                           top[idx]->v_traite;

        if ((max && val > vref) || (!max && val < vref)) {
            top[idx] = avl->usine;
        }
    }

    remplirTopN(avl->fd, top, n, cmp, critere, max);
}

pUsine* nUsinesOptimise(pAVL avl, int n, char *critere, int max, int *taille) {
    if (!avl || n <= 0) return NULL;

    pUsine *top = malloc(sizeof(pUsine) * n);
    int count = 0;

    remplirTopN(avl, top, n, &count, critere, max);
    *taille = count;

    return top;
}

int trieDict(const void* a, const void* b) {

    const Usine* ua = *(const Usine**)a;
    const Usine* ub = *(const Usine**)b;

    unsigned long sa = 0;
    unsigned long sb = 0;

    switch (critere_trie_global) {
        case CAPACITE:
            sa = ua->capacite;
            sb = ub->capacite;
            break;
        case V_CAPTE:
            sa = ua->v_capte;
            sb = ub->v_capte;
            break;
        case V_TRAITE:
            sa = ua->v_traite;
            sb = ub->v_traite;
            break;
        case SOMME:
            sa = ua->capacite + ua->v_capte + ua->v_traite;
            sb = ub->capacite + ub->v_capte + ub->v_traite;
            break;
    }

    return (sa > sb) - (sa < sb);

}





/*
void récupérer_max(pAVL avl, Dictionnaire dict[MAX_CMP], int* cmp_max) { // récupère le max dans l'ABR par un parcourt infix inverse
    if (!avl || !dict || !cmp_max || *cmp_max >= MAX_CMP) {
        return; 
    }

    récupérer_max(avl->fd, dict, cmp_max);

    if (*cmp_max < MAX_CMP) {
        dict[*cmp_max].cle = avl->usine->id;
        dict[*cmp_max].valeur = avl->usine->v_traite;
        (*cmp_max)++;
    }
    récupérer_max(avl->fg, dict, cmp_max);
}

void récupérer_min(pAVL avl, Dictionnaire dict[MAX_CMP], int* cmp_min) { // récupère le min dans l'ABR par un parcourt infix 
    if (!avl || !dict || !cmp_min || *cmp_min >= MAX_CMP) {
        return; 
    }
    récupérer_min(avl->fg,dict,cmp_min);

    if (*cmp_min < MAX_CMP) {
        dict[*cmp_min].cle = avl->usine->id;
        dict[*cmp_min].valeur = avl->usine->v_traite;
        (*cmp_min)++;
    }
    récupérer_min(avl->fd, dict, cmp_min);
}

Token_liste* creerToken(const char* valeur){
    if (!valeur) return NULL;

    Token_liste* nouveau = malloc(sizeof(Token_liste));
    if (!nouveau) return NULL;
    nouveau->suivant = NULL;
    strncpy(nouveau->token, valeur, sizeof(nouveau->token));
    nouveau->token[sizeof(nouveau->token)-1] = '\0';
    return nouveau;
}


Token_liste* ouvrir_fichier(const char* nom_fichier){
    char chemin[256];
    snprintf(chemin, sizeof(chemin), "gnuplot/data/%s.dat", nom_fichier);

    FILE *f = fopen(chemin, "r");
    if (!f) {
        printErreur("Erreur lors de l'ouverture du fichier\n");
        return NULL;
    }

    char buffer[256];
    Token_liste* liste = NULL;
    Token_liste* courant = NULL;

    while (fgets(buffer, sizeof(buffer), f)) {

        // enlever le \n
        buffer[strcspn(buffer, "\n")] = '\0';

        Token_liste* nouveau = creerToken(buffer);

        if (!liste) {
            liste = nouveau;
            courant = liste;
        } else {
            courant->suivant = nouveau;
            courant = nouveau;
        }
    }

    fclose(f);
    return liste;
}
*/

void lireFichier(const char* chemin_fichier, pAVL *avl) {
    if (!chemin_fichier) {
        printErreur("Impossible de connaitre l'emplacement du fichier\n");
        return;
    }

    char chemin[256];
    snprintf(chemin, sizeof(chemin), "gnuplot/data/%s.dat", chemin_fichier);
    FILE *f = fopen(chemin, "r");
    if (!f) {
        printErreur("Erreur : Impossible de lire le fichier .dat\n");
        return;
    }

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), f)) {

        trim(buffer); // enlever espaces et \n de la ligne entière

        pUsine usine = malloc(sizeof(Usine));
        if (!usine) { fclose(f); return; }

        char* token = strtok(buffer, ";");
        int i = 0;

        while (token) {
            trim(token); // sécuriser chaque token
            switch (i) {
                case 1: {
                    //char* tmp = extraireID(token);
                    //if (!tmp) break;
                    trim(token);
                    usine->id = strdup(token);
                    //free(tmp);
                    break;
                }
                case 3:
                    usine->capacite = atoi(token);
                    break;
            }
            token = strtok(NULL, ";");
            i++;
        }

        *avl = ajouterAVLUsine(*avl, usine);
    }

    fclose(f);
}

void remplirAVL(pAVL avl) {
    if (!avl) {
        printErreur("Erreur : AVL non initialisé\n");
        return;
    }

    FILE *f = fopen("gnuplot/data/source.dat", "r");
    if (!f) {
        printErreur("Erreur : impossible d'ouvrir le fichier .dat\n");
        return;
    }

    char buffer[256];

    while (fgets(buffer, sizeof(buffer), f)) {
        trim(buffer); // enlever espaces et \n de la ligne entière

        // Tokens
        char* token = strtok(buffer, ";");
        if (!token) continue; // ignorer ligne vide

        token = strtok(NULL, ";"); // 2e token à ignorer
        if (!token) continue;
        trim(token);

        token = strtok(NULL, ";"); // 3e token : ID de l'usine
        if (!token) continue;
        trim(token);
        /*
        char* id_token = extraireID(token);
        if (!id_token) continue;
        trim(id_token);
        */

        pAVL usineptr = recherche(avl, token);
        //printf("ID de l'usine lu : %s\n",id_token);
        if (!usineptr) {
            //printf("Erreur de mémoire sur %s\n",id_token);
            //free(id_token);
            continue; // passer à la ligne suivante
        }

        token = strtok(NULL, ";"); // volume capté
        if (token) {
            trim(token);
            usineptr->usine->v_capte += atoi(token);
        }

        float v_capte = usineptr->usine->v_capte;
        //printf("volume capté par l'usine : '%s' : %lf\n\n",id_token,atof(token));
        token = strtok(NULL, ";"); // % perte
        if (token) {
            trim(token);
            usineptr->usine->v_traite = v_capte * (1.0 - (atof(token)/100));
        }

        //free(id_token);
    }

    fclose(f);
}

void ecrireUsine(pUsine *dict, int taille, char destination[64], int type){ // (1=max, 0=min)
    if (!dict || taille <= 0) return;
    if (type > 1 || type < 0) return;
    // Fichier par défaut
    if (destination[0] == '\0' && type == 1) {
        strcpy(destination, "gnuplot/data/usine_max.dat");
    }
    else if (destination[0] == '\0' && type == 0){
        strcpy(destination, "gnuplot/data/usine_min.dat");
    }
    
    FILE *f = fopen(destination, "w");
    if (!f) {
        printErreur("Erreur : Impossible d'ouvrir le fichier de destination\n");
        return;
    }

    for (int i = 0; i < taille; i++) { // méthode d'écriture : id;capacite;v_capte;v_traite
        if (dict[i]) if (dict[i]->capacite > 0 && dict[i]->v_capte > 0 && dict[i]->v_traite > 0){
            unsigned long capa = dict[i]->capacite;
            fprintf(f, "%s;%lu;%lu;%lu\n", dict[i]->id, capa,capa - dict[i]->v_capte,capa - dict[i]->v_traite);
        }
    }
    fclose(f);
}


void trim(char* str) {
    if (!str) return;
    // supprime espaces et \n en fin
    size_t len = strlen(str);
    while(len > 0 && (str[len-1]=='\n' || str[len-1]==' ' || str[len-1]=='\r'))
        str[--len] = '\0';
}
/*
void afficherDict(Dictionnaire* dict, int taille){
    for (int i=0;i<taille;i++){
        printf("cle : %s, valeur : %lu\n",dict[i].id,dict[i].valeur);
    }
}

void jolieAffichage(Dictionnaire* dict, int type, int taille, char* critere) {
    if (!dict || !critere || taille <= 0) {
        printf("Erreur : dictionnaire vide ou critère invalide.\n");
        return;
    }

    printf("Affichage des %d usines (%s)\n\n", taille, type ? "max" : "min");

    unsigned long max_val = dict[taille - 1].valeur;

    for (int i = 0; i < taille; i++) {
        float ratio = (float)dict[i].valeur / max_val;
        int blocks = (int)(ratio * 20);  // 20 blocs = barre pleine
        if (i!=0 && i!=taille-1){
            printf(JAUNE"=======================================================\n"RESET);
        }
        printf(VIOLET"critère de trie : %s\n",critere);
        printf(BLEU "Usine %s\n" RESET, dict[i].id);
        printf(ROUGE "  Volume : %lu\n" RESET, dict[i].valeur);

        printf("  Taux de remplissage : [");
        for (int j = 0; j < blocks; j++) printf("#");
        for (int j = blocks; j < 20; j++) printf("-");
        printf("]  "JAUNE"(%.1f%%)\n\n"RESET, ratio * 100);
    }
}
*/