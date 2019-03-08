#include <stdio.h>
#include <stdlib.h>

void networkDisplay(int* spin, int** matrix, int n)
{
    int i, j;

    FILE* network;
    network = fopen("network.net","w");

    fprintf(network, "*Vertices %d \n", n);
    for(i = 0; i < n; i++)
    {
        if(spin[i] == -1)
        {
            fprintf(network,"%d %d ic Red \n", i+1, i+1);
        }
        else fprintf(network,"%d %d ic Blue \n", i+1, i+1);   

    }

    fprintf(network, "*edgeslist \n");

    for (int i = 0; i < n; i++)
    for (int j = i+1; j < n; j++)
    {
        if(matrix[i][j] != 0)
        { fprintf(network, "%d %d \n", i+1, j+1); }
    }

}