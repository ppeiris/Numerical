#include <stdio.h>
#include <stdlib.h>
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

int main(int argc, const char *argv[])
{

    double M = 50.0;
    double p = 0.5;
    int k = 50;
    double tp = 0.0;
    for (int i = 0; i < k; ++i) {
        double binoC = binomialCoeff(M, i);
        double pk = binoC * pow(p, i) * pow(1-p, M-i);
        tp += pk;
        printf("%d %.50lf\n", i, pk);
    }
    return 0;
}
