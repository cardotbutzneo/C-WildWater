gnuplot  # Lance l'interface interactive de gnuplot
gnuplot script.gp  # Exécute un script gnuplot
gnuplot -c script.gp arg1 arg2  # Exécute un script avec des arguments

set title "Mon Titre"  # Définit le titre du graphique
set xlabel "Axe X"    # Définit le label de l'axe X
set ylabel "Axe Y"    # Définit le label de l'axe Y
set grid              # Affiche une grille
unset grid            # Masque la grille

set terminal png      # Définit le format de sortie comme PNG
set output "graphique.png"  # Définit le fichier de sortie
set terminal pdf      # Définit le format de sortie comme PDF
set output "graphique.pdf"

plot sin(x)            # Trace la fonction sin(x)
plot "data.csv" using 1:2 with points  # Trace les données du fichier data.csv
plot x**2 with lines  # Trace x² avec des lignes

with lines       # Trace avec des lignes
with points      # Trace avec des points
with linespoints # Trace avec des lignes et des points
with boxes       # Trace avec des barres (histogramme)
with impulses    # Trace avec des impulsions

set boxwidth 0.8        # Définit la largeur des barres
set style fill solid    # Remplit les barres
plot "data.txt" using 1:(1) smooth frequency with boxes  # Trace un histogramme

set style line 1 lc rgb "red" lt 1 lw 2  # Définit la couleur, le type et la largeur de la ligne
set style fill solid rgb "blue"          # Remplit les barres en bleu

plot sin(x) title "sin(x)"  # Ajoute une légende
set key top right           # Place la légende en haut à droite
set key off                 # Désactive la légende

set xrange [0:10]   # Définit la plage de l'axe X
set yrange [0:1]    # Définit la plage de l'axe Y
set logscale x      # Utilise une échelle logarithmique pour l'axe X
set logscale y      # Utilise une échelle logarithmique pour l'axe Y

plot sin(x), cos(x)  # Trace plusieurs fonctions
plot "data1.csv" using 1:2 with points, "data2.csv" using 1:2 with lines

set datafile separator ";"  # Définit le séparateur de colonnes
plot "data.csv" using 1:2   # Utilise la première colonne pour X et la deuxième pour Y

# Dans un script gnuplot (script.gp)
title = exists("ARG1") ? ARG1 : "Titre par défaut"
plot x title title

gnuplot -c script.gp "Mon Titre"  # Passe un argument au script

set terminal png
set output "graphique.png"
replot  # Régénère le graphique
set output  # Réinitialise la sortie (retour au terminal par défaut)

# Configuration du graphique
set title "Exemple de tracé"
set xlabel "X"
set ylabel "Y"
set grid

# Configuration de la sortie
set terminal png
set output "graphique.png"

# Tracé des données
plot sin(x) with lines title "sin(x)", \
     cos(x) with lines title "cos(x)"


