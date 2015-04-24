set title "Poisson distribution"
set terminal postscript col
set out "poisson.eps"
set grid

plot "poisson.dat" u 1 smooth bezier title "lambda = 1", \
"poisson.dat" u 2 smooth bezier title "lambda = 2", \
"poisson.dat" u 3 smooth bezier title "lambda = 3", \
"poisson.dat" u 4 smooth bezier  title "lambda = 4" , \
"poisson.dat" u 5 smooth bezier  title "lambda = 5" , \
"poisson.dat" u 6 smooth bezier  title "lambda = 6" , \
"poisson.dat" u 7 smooth bezier  title "lambda = 7" , \
"poisson.dat" u 8 smooth bezier  title "lambda = 8" , \
"poisson.dat" u 9 smooth bezier  title "lambda = 9" , \
"poisson.dat" u 10 smooth bezier  title "lambda = 10" , \
"poisson.dat" u 12 smooth bezier  title "lambda = 11" , \
"poisson.dat" u 13 smooth bezier  title "lambda = 12" , \
"poisson.dat" u 14 smooth bezier  title "lambda = 13" , \
"poisson.dat" u 15 smooth bezier  title "lambda = 14" , \
"poisson.dat" u 16 smooth bezier  title "lambda = 15" , \
"poisson.dat" u 17 smooth bezier  title "lambda = 16" , \
"poisson.dat" u 18 smooth bezier  title "lambda = 17" , \
"poisson.dat" u 19 smooth bezier  title "lambda = 18" , \
"poisson.dat" u 20 smooth bezier  title "lambda = 19"

