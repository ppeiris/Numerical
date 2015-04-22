set title "Geometric Distribtion"
set terminal postscript col
set out "geometric.eps"
set grid

plot "geometric.dat" u 2 smooth bezier
