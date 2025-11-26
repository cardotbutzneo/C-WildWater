#!/bin/bash

verifDependance() {
    local args=("gnuplot")

    for cmd in "${args[@]}"; do
        if ! command -v "$cmd" &> /dev/null; then
            printf "Erreur : La dépendance <$cmd> n'est pas installée. Veuillez l'installer et réessayer." >&2
            printf "Pour compilez sans les dépendances ajoutez '--force'."
            printf "Exemple : ./launch.sh [arg1] [arg2] --force -> compilation sans dépendance."
            printf "Attention ! : Certaine fonctionalité ne seront pas présentes."
            return 1
        fi
    done
    return 0
}