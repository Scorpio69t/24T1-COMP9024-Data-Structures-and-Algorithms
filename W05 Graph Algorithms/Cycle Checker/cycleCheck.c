#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Graph.h"

bool hasCycle(Graph g);
bool dfsCycleCheck(Graph g, int v, int visited[], int prev);

int components(Graph g, int componentOf[]);
void dfsComponent(Graph g, int v, int id, int componentOf[]);

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
    if (hasCycle(g)) {
        printf("The graph has a cycle.\n");
    } else {
        printf("The graph is acyclic.\n");
    }
    freeGraph(g);
    return 0;
}

bool hasCycle(Graph g) {
    // Need to do a dfsCycleCheck for each component of the graph
    int num_vertices = numOfVertices(g);

    // Set up component history
    int *componentOf = malloc(num_vertices * sizeof(int));
    assert(componentOf != NULL);
    int num_components = components(g, componentOf);

    // Set up visited history 
    int *visited = malloc(num_vertices * sizeof(int));
    assert(visited != NULL);

    for (int a = 0; a < num_vertices; a++) {
        visited[a] = -1;
    }
    
    bool result = false;
    
    for (int i = 0; i < num_components; i++) {
        for (int j = 0; j < num_vertices; j++) {
            if (componentOf[j] == i) {
                // printf("----------Checking component #%d----------\n", i);
                result = dfsCycleCheck(g, j, visited, j);
                if (result == true) {
                    return result;
                }
                break;
            }
        }
        
    }

    free(visited);
    free(componentOf);
    return result;
}

bool dfsCycleCheck(Graph g, int v, int visited[], int prev) {
    int num_vertices = numOfVertices(g);

    // Mark v as visited
    // printf("Marking %d as visitied\n", v);
    visited[v] = prev;

    // for (int i = 0; i < num_vertices; i++) {
    //     printf("[%d]-", i);
    // }
    // printf("\n");
    // for (int i = 0; i < num_vertices; i++) {
    //     printf("[%d]-", visited[i]);
    // }
    // printf("\n");
    

    // for each (v,w)edges(G) do:
        for (int i = 0; i < num_vertices; i++) {
            if (i != v && i != prev) {
                // printf("Checking Edge: %d -- %d", v, i);
                if (adjacent(g, i, v)) { // if i is an edge of v
                    // if w has been visited, return true
                    // printf(" --> This is an edge!\n");
                    if (visited[i] != -1) {
                        // printf("Vertex %d has been visited before\n", i);
                        return true;
                    } else {
                        // printf("----------------------------\n");
                        if (dfsCycleCheck(g, i, visited, v)) {
                            return true;
                        }
                    }
                } else {
                    // printf("\n"); // Not an edge
                }
            }
        }
    return false;
}

int components(Graph g, int componentOf[]) {
    int num_vertices = numOfVertices(g);    
    int v;
    for (v = 0; v < num_vertices; v++) {
        componentOf[v] = -1;
    }
    int compID = 0;
    for (v = 0; v < num_vertices; v++) {
        if (componentOf[v] == -1) {
            dfsComponent(g, v, compID, componentOf);
            compID++;
        }
    }

    // printf("Number of components = %d\n", compID);
    // for (v = 0; v < num_vertices; v++) {
    //     printf("[%d]", v);
    // }
    // printf("\n");
    // for (v = 0; v < num_vertices; v++) {
    //     printf("[%d]", componentOf[v]);
    // }
    // printf("\n");
    return compID;
}

void dfsComponent(Graph g, int v, int id, int componentOf[]) {
    int num_vertices = numOfVertices(g);
    componentOf[v] = id;
    for (int i = 0; i <  num_vertices; i++) {
        if (adjacent(g,v,i)) {
            if (componentOf[i] == -1) {
                dfsComponent(g,i,id, componentOf);
            }
        }
    }
}


// scp cycleCheck.c z5114919@login.cse.unsw.edu.au:~/9024/pracs/prac_5