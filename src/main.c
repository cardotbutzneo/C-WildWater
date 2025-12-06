#include "main.h"
int main(int argc, char* argsv[])
{
    Token_liste* valeurs = NULL;
    valeurs = ouvrir_fichier(argsv[1]);
    Token_liste *temp = valeurs;
    while (temp){
        printf("type : %s\n",temp->token);
        temp = temp->suivant;
    }
    
    return 0;
}
