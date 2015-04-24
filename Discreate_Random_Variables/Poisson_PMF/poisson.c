#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "../lib/probability.h"



/*
 * Poisson Distribution.
 * p[k] = exp(- L) * (L^k / k!)
 *
 */
int main(int argc, const char *argv[])
{

    double pk;



    int tcolumn = 20;
    int trow = 50;
    int k = 20;

    double *lambda = (double *)malloc(tcolumn * sizeof(double));
    double *pklist = (double *)malloc(tcolumn * trow * sizeof(double));

    // fill lambda values
    for (int i = 0; i < tcolumn; i++) {
        *(lambda + i) = i + 1;
    }



    for(int row = 0; row < trow; row++) {
        for(int col = 0; col < tcolumn; col++) {
            pk = exp(- *(lambda + col)) * (pow(*(lambda + col), row) / factorial(row));
            *(pklist + (row * tcolumn) + col) = pk;
        }
    }


    for(int row = 0; row < trow; row++) {
        for(int col = 0; col < tcolumn; col++) {
            printf(" %.20lf ", *(pklist + (row * tcolumn) + col));
        }
        printf("\n");
    }





    return 0;
}
