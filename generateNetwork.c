#include <stdio.h>
#include <stdlib.h>
#include "isingTools.h"

void generateNetwork(int n, int m)
{

    double totalDeg = 0; // initial total degree is 0
    double probability; // probability
    double r = 0; // random number between 0 and 1

    int *matrix[n]; // adjacency matrix (n x n size)
    for (int i = 0; i < n; i++)
        matrix[i] = (int*)malloc(n*sizeof(int));

    double* deg = malloc(n*sizeof(double)); // node degree (n size)

    for(int i = 0; i < n; i++)
    {
        deg[i] = 0; // degree of each node is 0 (initially)
        for(int j = 0; j < n; j++)
        { matrix[i][j] = 0; } // initialize adjaceny matrix (n size)
    }

    for (int i = 0; i < m; i++)
    for (int j = i+1; j < m; j++)
    {
        matrix[i][j] = matrix[j][i] = 1; // create complety graph (size m)
        deg[i]++; // increment node i degree by 1
        deg[j]++; // increment node i degree by 1
    }

    for(int i = 0; i < n; i++)
    {
        totalDeg = totalDeg + deg[i]; // calculate total degree
    }

    int connectedNodes = m; // m connected nodes (with degree > 0 )
    int currentNode = m; // current node is set to m
    int nodeJ = 0;

    do
    {
        do
        {
            nodeJ = rand()%(connectedNodes); // generates a node between 0 and connectedNodes - 1
            probability = deg[nodeJ]/totalDeg; // calculates probability of connection
            double r = ((double) rand()/(RAND_MAX)); 

            if ( r < probability )
            {
                matrix[nodeJ][currentNode] = matrix[currentNode][nodeJ] = 1;
            }

            totalDeg=0;

            for(int i = 0; i <= connectedNodes; i++)
            {
                deg[i] = 0;  // resets every iteration the degree of every node to 0
            }

            for(int i = 0; i <= connectedNodes; i++)
            for(int j = i+1; j <= connectedNodes; j++)
            {
                if(matrix[i][j] != 0)
                {
                    deg[i]++;
                    deg[j]++;
                }
            } // a better way to calculate node degree

            for(int i = 0; i <= connectedNodes; i++)
            {
                totalDeg = totalDeg + deg[i];
            } // calculates total degre

        } while (deg[currentNode] < m); // the degree of node should be at least m

        currentNode = currentNode + 1; // we go to the next node
        connectedNodes = connectedNodes + 1;

    } while(connectedNodes < n); // last node should be node n-1

    int* spin = malloc(n*sizeof(int));

    for (int i = 0; i < n; i++)
    {
        double r = ((double) rand()/(RAND_MAX));
        if (r < 0.5) 
            spin[i] = -1;
        else 
            spin[i] = 1;
    }

    FILE* network;
    network = fopen("data.txt","w");

    fprintf(network, "%d \n", n);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        fprintf(network, "%d ", matrix[i][j]);
        fprintf(network, "\n");
    }

    for(int i = 0; i < n; i++)
    { fprintf(network, "%d ", spin[i]); }

    fclose(network);

}