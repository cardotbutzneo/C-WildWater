#include "main.h"
int main(int argc, char* argsv[])
{
    if (argc !=2) exit(0);
    if (!argsv) return 1;
    pAVL avl = NULL;
    printf("Lecture en cours...\n");
    lireUsineFichier("usine",&avl); // lit tout le fichier des sources et l'ajoute à l'avl
    lireUsineFichier("source",&avl);
    printf("lecture réussie\n");
    switch (recherche_i(avl,"NM000000T")){ // exemple de recherche de noeud
        case 0:
            printf("Id trouvé\n");
            break;
        default:
            printf("Id non trouvé\n");
            break;
    }
    afficherAVL(avl);
    libererAVL(avl);
    printf("Mémoire libérée\n");
    return 0;
}
