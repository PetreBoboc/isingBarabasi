#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <conio.h>
#include "isingTools.h"

void ising(double j)
{
    int n; // number of vertices
    double mag=0;

    FILE* data;
    data = fopen("data.txt", "r");
    rewind(data);

    FILE* x;
    x = fopen("x.txt", "w");

    FILE* y;
    y = fopen("y.txt", "w");

    fscanf(data, "%d", &n);

    int *matrix[n]; // adjacency matrix (n x n size)
    for (int i = 0; i < n; i++)
        matrix[i] = (int*)malloc(n*sizeof(int));

    double* deg = malloc(n*sizeof(double)); // node degree (n size)

    int* spin = malloc(n*sizeof(int));

    int* neighbors = malloc(n*sizeof(int)); 

    for (int i = 0; i < n; i++)
    { neighbors[i] = 0; }

    for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
    { fscanf(data, "%d", &matrix[i][j]); }

    for (int i = 0; i < n; i++)
    { fscanf(data, "%d", &spin[i]); }

    double R = 0;
    double z = 0;
    double tStop = 0.01;
    double tStart = 20;

    int randSpin = 0;

    while (tStart > tStop)
    {
        for(int ath = 0; ath < n*n; ath++)
        {
            randSpin = rand()%(n)+0;

            for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
            {
                if (matrix[i][j]!=0)
                {
                    neighbors[i] = neighbors[i] + spin[j];
                }
            }

            double deltaE=0;

            for(int i=0; i<n; i++)
            {
                deltaE = deltaE + j*spin[i]*neighbors[i];
            }

            R = exp(-deltaE / (K*tStart));
            z = ((double) rand() / (RAND_MAX));

            if (z < R)
            {
                spin[randSpin] = -spin[randSpin];
            }

            for(int i=0; i<n; i++)
            {
                neighbors[i]=0;
            }

            for(int i=0; i<n; i++)
            {
                mag = mag + spin[i];
            }

            randSpin = 0;

        }

        mag = mag / (n*n);

        fprintf(x, "%f \n", tStart);
        fprintf(y, "%f \n", mag);

        z = 0;
        mag = 0;

        tStart = tStart - 0.1;
    }

    networkDisplay(spin, matrix, n);

    for (int i = 0; i < n; i++)
    for (int j = i+1; j < n; j++)
    {
        if (matrix[i][j] != 0 )
        {
            deg[i]++;
            deg[j]++;
        }
    }

    degreeDistribution(deg, n);

}