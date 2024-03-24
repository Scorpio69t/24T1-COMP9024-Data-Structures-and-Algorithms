#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

/// ------------------ for testing only, remove these ------------------

// Our vertexes here are strings, each with a list of edges
typedef struct Vertex {
    string label;
    list edges;
} Vertex;

// Each edge has a destination and weight (do not need source)
typedef struct Edge {
    string destination;
    size_t weight;
} Edge;

// Adjacency List Representation
typedef struct Graph_Repr
{
    list vertices;
    // int nV; // Lectures had these but not sure if we need
    // int nE; // For counts, we can just loop through the adjacency lists
} Graph_Repr;

/// ------------------ for testing only, remove these ------------------

int main()
{
    printf("Hello World, Testing Graphs\n");

    // Test Create
    graph urlGraph = graph_create();

    // Test adding vertices
    graph_has_vertex(urlGraph, "Hello World");
    graph_add_vertex(urlGraph, "URL: INDEX");
    graph_add_vertex(urlGraph, "URL: HOME");
    graph_add_vertex(urlGraph, "URL: PAGE-X");
    graph_add_vertex(urlGraph, "URL: PAGE-Y");
    graph_add_vertex(urlGraph, "URL: PAGE-Z");
    graph_add_vertex(urlGraph, "URL: HOME");


    // Test adding edges
    graph_add_edge(urlGraph, "URL: HOME", "URL: PAGE-X", 10);
    graph_add_edge(urlGraph, "URL: HOME", "URL: PAGE-Y", 10);
    printf("Graphs added!\n");


    // Checking edges exist
    printf("Graph X->Y : %d\n", graph_has_edge(urlGraph, "URL: HOME", "URL: PAGE-X"));
    printf("Graph X->Y : %d\n", graph_has_edge(urlGraph, "URL: HOME", "URL: PAGE-Y"));
    printf("Graph X->Y : %d\n", graph_has_edge(urlGraph, "URL: HOME", "URL: PAGE-Z"));

    // Test showing
    printf("Graph currently contains %zu vertices\n", graph_vertices_count(urlGraph));

    // Test destroying
    graph_destroy(urlGraph);
    printf("Done.\n");

    return 0;
}
