#!/bin/bash

verifDependance(){
    #verification des dépendances
    args=("gnuplot")

    for cmd in "${args[@]}";do
        if ! command -v "$cmd" &> /dev/null;then
            echo "La dépendance <"$cmd"> n'est pas installée. Veuillez l'installer et réessayer." >&2
            exit 1
        fi
    done
}


