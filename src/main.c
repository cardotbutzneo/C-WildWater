#include "main.h"
int main(int argc, char* argsv[])
{
    if (argc !=2) exit(0);
    if (!argsv) return 1;
    pAVL avl = NULL;
    lireUsineFichier("usine",&avl);
    printf("lecture réussie\n");
    switch (recherche_i(avl,"NM000000T")){ // exemple de recherche de noeud
        case 0:
            printf("Id trouvé\n");
            break;
        default:
            printf("Id non trouvé\n");
            break;
    }
    libererAVL(avl);
    printf("Mémoire libérée\n");
    return 0;
}
