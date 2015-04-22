#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../lib/probability.h"


/*
 * Calculate the geometric probability distribution
 *  p[k] = (1 - p)^(k-1) * p
 *
 */
int main(int argc, const char *argv[])
{

    double p = 0.1;
    int k = 50;

    for (int i = 1; i < k; i++) {
        double pk = pow((1 - p), (i - 1)) * p;
        printf("%d %lf\n", i, pk);
    }



    return 0;
}
