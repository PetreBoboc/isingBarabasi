#include <stdio.h>
#include <stdlib.h>

int degreeDistribution(double* deg, int n)
{
    
    FILE* ddx;
    ddx = fopen("ddx.txt","w");
    
    FILE* ddy;
    ddy = fopen("ddy.txt","w");

    for(int k = 0; k < n; k++)
    {
        fprintf(ddx, "%d \n", k+1);

        double counter = 0;

        for (int i = 0; i < n; i++)
        { 
            if(deg[i] == k+1) { counter++; }
        }

        double probability = counter / n;

        fprintf(ddy, "%lf \n", probability);

    }

}