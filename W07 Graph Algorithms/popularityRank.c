#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "WGraph.h"

typedef struct node_popularity
{
    int vertex;
    double popularity;
} node_popularity;

void popularityCheck(Graph g, int num_vertices);
double inDegree(int **edges, int v, int num_vertices);
double outDegree(int **edges, int v, int num_vertices);
void insertionSort(node_popularity nodes[], int n);
void show_popularity(node_popularity nodes[], int n);

int main()
{
    int v = 0;
    int edge_from = 0;
    int edge_to = 0;
    Edge *e = malloc(sizeof(Edge));
    assert(e != NULL);
    e->weight = 1;

    printf("Enter the number of vertices: ");
    while (scanf("%d", &v) != 1)
        ;
    // printf("Number of vertices is %d. Creating graph...\n", *v);
    Graph g = newGraph(v);

    printf("Enter an edge (from): ");

    while (scanf("%d", &edge_from) == 1) // Scanf returns 1 when we get a successful result
    {
        printf("Enter an edge (to): ");
        if (scanf("%d", &edge_to) == 1)
        {
            e->v = edge_from;
            e->w = edge_to;
            // printf("Adding edge: %d-->%d\n", e->v, e->w);
            insertEdge(g, *e);

            printf("Enter an edge (from): ");
        }
        else
        {
            break;
        }
    }
    printf("Done.\n\n");

    // printf("Showing Graph\n");
    // showGraph(g);
    popularityCheck(g, v);
    freeGraph(g);
    return 0;
}

void popularityCheck(Graph g, int num_vertices)
{
    // create a matrix: 0 --> n

    int **edges = malloc(num_vertices * sizeof(int *));
    assert(edges != NULL);
    for (int i = 0; i < num_vertices; i++)
    {
        edges[i] = malloc(num_vertices * sizeof(int));
    }
    int weight;

    // Initialising edges

    for (int i = 0; i < num_vertices; i++)
    {
        for (int j = 0; j < num_vertices; j++)
        {
            edges[i][j] = 0;
        }
    }

    // printf("Populating Matrix\n");
    for (int i = 0; i < num_vertices; i++)
    {
        for (int j = 0; j < num_vertices; j++)
        {
            weight = adjacent(g, i, j);
            // printf("Checking edge: [%d]->[%d]\n", i, j);
            // printf("Weight = %d\n", weight);
            if (weight != 0)
            {
                // printf("Adding edge: [%d]->[%d]\n", i, j);
                edges[i][j] = 1;
            }
        }
    }

    // Verifying our matrix
    // printf("Checking Edges\n");
    // printf("%d\n", edges[0][0]);
    // for (int i = 0; i < num_vertices; i++) {
    //     for (int j = 0; j < num_vertices; j++) {
    //         printf("[%d]", edges[i][j]);
    //     }
    //     printf("\n");
    // }

    double inD;
    double outD;
    node_popularity nodes[num_vertices];

    for (int v = 0; v < num_vertices; v++)
    {
        // printf("Checking for vertex: [%d]\n", v);
        inD = inDegree(edges, v, num_vertices);
        outD = outDegree(edges, v, num_vertices);

        // printf("%d %.2f\n", v, (float) inD/outD);
        node_popularity new_node;
        new_node.vertex = v;
        new_node.popularity = inD / outD;
        nodes[v] = new_node;
    }

    // printf("Before Sorting\n");
    // show_popularity(nodes, num_vertices);

    insertionSort(nodes, num_vertices);

    // printf("After Sorting\n");
    printf("Popularity ranking:\n");
    show_popularity(nodes, num_vertices);

    // free
    for (int i = 0; i < num_vertices; i++)
    {
        free(edges[i]);
    }
    free(edges);
}

double inDegree(int **edges, int v, int num_vertices)
{
    double inD = 0.0;
    for (int i = 0; i < num_vertices; i++)
    {
        // printf("[%d][%d] = %d: \n", i, v, edges[i][v]);
        if (edges[i][v] == 1)
        {
            inD++;
        }
    }

    // printf("In Degree = %.1f\n", inD);
    return inD;
}

double outDegree(int **edges, int v, int num_vertices)
{
    double outD = 0.0;
    for (int i = 0; i < num_vertices; i++)
    {
        // printf("[%d][%d] = %d: \n", v, i, edges[v][i]);
        if (edges[v][i] == 1)
        {
            outD++;
        }
    }

    if (outD == 0)
        outD = 0.5;
    // printf("Out Degree = %.1f\n", outD);
    return outD;
}

void insertionSort(node_popularity nodes[], int n)
{
    int i;
    for (i = 1; i < n; i++)
    {
        // ... (Rest of the code remains the same) ...
        node_popularity element = nodes[i];
        // printf("Current Element: V:%d P:%.1f\n", element.vertex, element.popularity);

        int j = i - 1;

        while (j >= 0 && nodes[j].popularity < element.popularity)
        { // Change '<' to '>'
            nodes[j + 1] = nodes[j];
            j--;
        }

        nodes[j + 1] = element;

        // printf("--- Node is now --- \n");
        // show_popularity(nodes, n);
    }
}

void show_popularity(node_popularity nodes[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d %.1f\n", nodes[i].vertex, nodes[i].popularity);
    }
}

// 6 0 1 1 5 3 5 5 0 5 2 5 3 5 4 5 1 done
// scp popularityRank.c z5114919@login.cse.unsw.edu.au:~/9024/pracs/prac_7
