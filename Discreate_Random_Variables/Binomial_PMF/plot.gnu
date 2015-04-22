set title "Binomial Distribtion"
set terminal postscript col
set out "binomial.eps"
set grid

plot "binomial.dat" u 2 smooth bezier
