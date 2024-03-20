#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Graph.h"
// #include "Graph.c"

void degreeOfVertices(Graph g);
void threeCliquesInGraph(Graph g);
void graphDensity(Graph g);

int main()
{
    
    int v = 0;
    int edge_from = 0;
    int edge_to = 0;
    Edge *e = malloc(sizeof(Edge));
    assert(e != NULL);

    printf("Enter the number of vertices: ");
    while (scanf("%d", &v) != 1);
    // printf("Number of vertices is %d. Creating graph...\n", *v);
    Graph g = newGraph(v);
    
    printf("Enter an edge (from): ");

    while (scanf("%d", &edge_from) == 1) // Scanf returns 1 when we get a successful result
    {
        printf("Enter an edge (to): ");
        if (scanf("%d", &edge_to) == 1) {
            // printf("Adding edge: %d-->%d\n", edge_from, edge_to);
            e->v = edge_from;
            e->w = edge_to;
            insertEdge(g, *e);

            printf("Enter an edge (from): ");
        } else {
            break;
        }
    }

    printf("Done.\n");
    // showGraph(g);
    degreeOfVertices(g);
    threeCliquesInGraph(g);
    graphDensity(g);
    freeGraph(g);
    return 0;
}

// this is O(V+E)
void degreeOfVertices(Graph g) {
    assert(g != NULL);
    int num_adjacent = 0;
    int num_vertices = numOfVertices(g);

    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            if (j != i && adjacent(g, i, j)) {
                num_adjacent++;
            }
        }
        printf("Degree of node %d: %d\n", i, num_adjacent);
        num_adjacent = 0;
    }
}

void threeCliquesInGraph(Graph g) {
    printf("3-cliques:\n");
    assert(g != NULL);
    int num_vertices = numOfVertices(g);
    int neighbors[num_vertices];

    // reset neighbors
    for (int a = 0; a < num_vertices; a++) {
        neighbors[a] = -1;
    }

    for (int i = 0; i < num_vertices; i++) {
        // populate the array of neighbours
        for (int j = 0; j < num_vertices; j++) {
            if (j != i && adjacent(g, i, j)) {
                // adjacent vertices
                neighbors[j] = 1;
            }
        }

        // loop through neighbors
        for (int j = i; j < num_vertices; j++) {
            if (neighbors[j] == 1) {
                for (int k = j; k < num_vertices; k++) {
                    if (neighbors[k] == 1 && adjacent(g, j, k)) {
                        printf("%d-%d-%d\n", i, j, k);
                    }
                }
            }
        }

        // reset neighbors
        for (int b = 0; b < num_vertices; b++) {
            neighbors[b] = -1;
        }
    }
}

void graphDensity(Graph g) {
    assert(g != NULL);
    double num_edges = 0;
    double num_vertices = numOfVertices(g);

    // count number of vertices
    for (int i = 0; i < num_vertices; i++) {
        for (int j = i; j < num_vertices; j++) {
            if (j != i && adjacent(g, i, j)) {
                num_edges++;
            }
        }
    }

    double density = (2*num_edges) / (num_vertices * num_vertices);
    printf("Density: %.3f", density);

}

// scp graphAnalyser.c z5114919@login.cse.unsw.edu.au:~/9024/pracs/prac_5