#include "../include/main.h"
#include "../include/histo.h"
#include "../include/fonction.h"
#include <string.h>



void recuperersource(char* sauvegarde, char* ligne) {

    char* token = strtok(ligne, ";");
    int i = 0;

    while (token) {
        if (i == 1) {       // deuxième champ
            strcpy(sauvegarde, token);
            return;
        }
        printf("token : %s\n", token);
        token = strtok(NULL, ";");
        i++;
    }
}

/*
int main() {
    char sauvegarde[64];   // un vrai buffer
    char ligne[] = "-;Source #HC900000Q;Unit #NM000000T;2956;0.915";  

    recuperersource(sauvegarde, ligne);
    printf("buffer : %s\n",sauvegarde);

    return 0;
}
*/