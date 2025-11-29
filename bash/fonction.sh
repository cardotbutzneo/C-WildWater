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

BarreDeProgression() {
    local cmp=0
    local bar=""
    if [[ -z "$1" ]];then
        local max=10 # valeur arbitraire
    else 
        local max="$1"  # Nombre total d'étapes en s
    fi
    while [ $cmp -le $max ]; do
        # Ajoute un "#" à la barre à chaque itération
        bar="${bar}#"
        # Affiche la barre sur la même ligne
        printf "\rChargement : [%s%s] %d%%" "$bar" "$(printf '%*s' $((max - cmp)) | tr ' ' '-')" $((cmp * 100 / max))
        sleep 1
        ((cmp++))
    done
    # Saut de ligne à la fin
    echo
    return 0
}

afifchageInit(){
    echo "Adding extra memory RAM for better performence"
    BarreDeProgression 15
    if [[ "$?" -eq 0 ]];then
        echo "Donne..."
        echo "1Tb memory RAM was add to your pc..."
    else
        echo "Failed of the test, you're sucks"
    fi
    echo "Downloading quantum chip for better performence"
    BarreDeProgression 5
    if [[ "$?" -eq 0 ]];then
        echo "Donne..."
    else
        echo "Quatum chips cannot be download..."
        echo "Exit..."
    fi
    echo "Working with Chatpgt..."
    BarreDeProgression 10
    if [[ "$?" -eq 0 ]];then
        echo "Donne..."
    else 
        echo "We detect a probem with Chatgpt, retry later"
    fi
    echo
    echo
    echo "Go outside touching grass, lol player 🐒 🐒"
}

afficherErreur(){
    if [ -z "$1" ];then
        echo "missing arugment in printError" >> 
}