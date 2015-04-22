#include <math.h>


/*
 * Calculate factorial using recursive
 * n!  =  1 x 2 x 3 x 4 x ... x n
 *
 */
double factorial(double x) {
    if (x == 0) {
        return 1;
    }
    return x * factorial(x-1);
}

/*
 * Calculate binomial distribution coefficient
 *
 */
double binomialCoeff(double M, double N) {
     return factorial(M) / (factorial(N) * factorial(M - N));
}
