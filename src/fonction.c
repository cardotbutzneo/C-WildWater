#include "main.h"
#include "arbres.h"
#define MAX_CMP 5


void printErrreur(char *format){
    if (!format) return;
    fprintf(stderr,format);
}

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

    récupérer_min(avl->fg, dict, cmp_min);

    if (*cmp_min < MAX_CMP) {
        dict[*cmp_min].cle = avl->usine->id;
        dict[*cmp_min].valeur = avl->usine->v_traite;
        (*cmp_min)++;
    }

    récupérer_min(avl->fd, dict, cmp_min);
}

int fichier(){
    FILE *f = fopen("log.txt", "w+");
    if (f == NULL) {
        printErrreur("Erreur lors de l'ouverture du fichier log.txt\n");
        return 0;
    }
    fprintf(f, "Erreur lors de l'allocation mémoire\n");
    fclose(f);
}

void ajouterArbreHierarchique(char* id){
    pUsine parent = récupérerParent(id);
    
}