#include "main.h"
int main(int argc, char* argsv[])
{
    if (argc !=2) exit(0);
    printErreur("hello");
    Token_liste* valeurs = NULL;
    valeurs = ouvrir_fichier(argsv[1]);
    Token_liste *temp = valeurs;
    while (temp){
        printf("type : %s\n",temp->token);
        temp = temp->suivant;
    }
    libérer_token(valeurs);
    printf("Mémoire libérée\n");
     pAVL arbre = NULL;
    int h = 0;
    temp = valeurs;
    while (temp) {
        pUsine u = malloc(sizeof(Usine));
        if (!u) { perror("malloc"); exit(EXIT_FAILURE); }
         u->capacite = 0;
        u->v_capte  = 0;
        u->v_traite = 0;
        arbre = insertionAVL(arbre, u, &h);
        temp = temp->suivant;
    }
    return 0;
}
