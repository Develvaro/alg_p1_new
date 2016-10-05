#!/bin/bash

cat << _end_ | gnuplot
set terminal postscript eps color
set output "grafico.eps"
set key right bottom
set xlabel "Numero de elementos"
set ylabel "Tiempo (ns)"
plot 'Datos.txt' using 1:2 t "Tiempo real" w l
plot 'Datos.txt' using 1:3 t "Tiempo estimado" w l
plot 'Datos.txt' using 1:2 t "Tiempo real" w l, 'Datos.txt' using 1:3 t "Tiempo estimado" w l
_end_
