#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "isingTools.h"

int main()
{
    srand(time(NULL)); // seed reset

    int n = 0 , m = 0;

    printf("Number of vertices = ");
    scanf("%i", &n);
    printf("Number of edges (mean) = ");
    scanf("%i", &m);

    generateNetwork(n, m);

    double j = 0;

    printf("J = ");
    scanf("%lf", &j);

    ising(j);

}