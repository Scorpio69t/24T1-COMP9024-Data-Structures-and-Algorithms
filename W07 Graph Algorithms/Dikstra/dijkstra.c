// Starting code for Dijkstra's algorithm ... COMP9024 24T1

#include <stdio.h>
#include <stdbool.h>
#include "PQueue.h"

#define VERY_HIGH_VALUE 999999

void showArray(int array[], int n) {
    for (int i = 0; i < n; i++) {
        printf("[%d]-", array[i]);
    }
    printf("\n");
}

void showfullPath(Vertex s, Vertex current, int pred[]) {
    if (current != s) {
        showfullPath(s, pred[current], pred);
    } 
    // Print Paths
    if (current == s) {
        printf("%d", current);
    } else {
        printf("-%d", current);
    }
}

void showPaths(Vertex s, int dist[], int pred[], int nV) {
    for (int i = 0; i < nV; i++) {
        if (dist[i] == VERY_HIGH_VALUE) {
            printf("%d: no path\n", i);
        } else {
            printf("%d: distance = %d, shortest path: ", i, dist[i]);
            if (i == s) {
                printf("%d\n", s);
            } else {
                showfullPath(s, pred[i], pred);
                printf("-%d\n", i);
            }
        }
    }
}

void dijkstraSSSP(Graph g, Vertex source)
{
    int dist[MAX_NODES];
    int pred[MAX_NODES];
    bool vSet[MAX_NODES]; // vSet[v] = true <=> v has not been processed
    int s;

    PQueueInit();
    int nV = numOfVertices(g);
    for (s = 0; s < nV; s++)
    {
        joinPQueue(s);
        dist[s] = VERY_HIGH_VALUE; // initialise dist[] to all ∞, except dist[source]=0
        pred[s] = -1;              // initialise pred[] to all -1
        vSet[s] = true;            // vSet=all vertices of G
    }
    dist[source] = 0; // initialise dist[] to all ∞, except dist[source]=0

    /* NEEDS TO BE COMPLETED */

    // // Show Graph
    // printf("Source Node: %d\n", source);
    // showGraph(g);

    int weight;

    // populate vSet with direct edges to source s
    dist[source] = 0;
    pred[source] = source;
    for (int i = 0; i < nV; i++)
    {
        weight = adjacent(g, source, i);
        if (weight != 0)
        {
            // printf("Adding to vSet: [%d]\n", i);
            joinPQueue(i);
            dist[i] = weight;
            pred[i] = source;
        }
    }

    Vertex min_vertex;
    int path_dist;

    while (!PQueueIsEmpty()) // while vSet≠∅ do
    {
        min_vertex = leavePQueue(dist); // find s∈vSet with minimum dist[s]
        if (vSet[min_vertex] == false) continue;
        // printf("Analyzing vertex: [%d]\n", min_vertex);

        for (int i = 0; i < nV; i++)
        { // for each (s,t,w)∈edges(G) do
            weight = adjacent(g, min_vertex, i);
            path_dist = weight + dist[min_vertex];
            // printf("Path Dist for [%d]--[%d] is %d (from src is %d)\n", min_vertex, i, path_dist, dist[i]);
            if (weight != 0 && path_dist < dist[i])
            { // relax along (s,t,w)
                // printf("-----RELAXING HERE-----\n");
                joinPQueue(i);
                dist[i] = weight + dist[min_vertex];
                pred[i] = min_vertex;
            }                         // end for
            vSet[min_vertex] = false; // vSet=vSet\{s}
        }                             // end while
    }

    showPaths(source, dist, pred, nV);
}

void reverseEdge(Edge *e)
{
    Vertex temp = e->v;
    e->v = e->w;
    e->w = temp;
}

int main(void)
{
    Edge e;
    int n, source;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    Graph g = newGraph(n);

    printf("Enter the source node: ");
    scanf("%d", &source);

    printf("Enter an edge (from): ");
    while (scanf("%d", &e.v) == 1)
    {
        printf("Enter an edge (to): ");
        scanf("%d", &e.w);
        printf("Enter the weight: ");
        scanf("%d", &e.weight);
        insertEdge(g, e);
        reverseEdge(&e); // ensure to add edge in both directions
        insertEdge(g, e);
        printf("Enter an edge (from): ");
    }
    printf("Done.\n");

    dijkstraSSSP(g, source);
    freeGraph(g);
    return 0;
}

// 4 0 0 1 42 0 2 25 1 2 14 done

// scp dijkstra.c z5114919@login.cse.unsw.edu.au:~/9024/pracs/prac_7