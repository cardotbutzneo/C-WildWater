# Configuration du graphique
set title "Histogramme des données"
set xlabel "Valeurs"
set ylabel "Fréquence"
set boxwidth 0.8  # Largeur des barres de l'histogramme
set style fill solid  # Remplit les barres avec une couleur

data_file = (exists("ARG1") ? ARG1 : )

# Configuration du terminal et du fichier de sortie
set terminal png
set output "gnuplot/graphique/histogramme.png"

# Tracé de l'histogramme
plot "gnuplot/data/max.csv" using 1:(1) smooth frequency with boxes title "Histogramme"
