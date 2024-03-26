// You have been provided with a file graph.h. Examine the file carefully. It provides the interface for an ADT that will provide Graph functionality. The graph is both weighted and directed.

// Your task is to implement the functions prototyped in the graph.h header file within graph.c.

// You must create the file graph.c to implement this ADT.
// You must use an adjacency list representation, but the exact representation is up to you.
// You must use string (char *) data to label the vertices.
// You must allocate memory dynamically.
// You must not modify the graph.h file.
// You must not modify the function prototypes declared in the graph.h file.
// You may add utility functions to the graph.c file.
// You may use the string.h library, and other standard libraries from the weekly exercises.
// You may reuse code previously submitted for weekly assessments and provided in the lectures.
// You should write programs that use your ADT to test and debug your code.
// You should use valgrind to verify that your ADT does not leak memory.
// See graph.h for more information about each function that you are required to implement.

#include "graph.h"
#include "list.h"
#include "string.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

// Our vertexes here are strings, each with a list of edges
typedef struct Vertex
{
    string label;
    struct Edge *edges;
    struct Vertex *next;
} Vertex;

// Each edge has a destination and weight (do not need source)
typedef struct Edge
{
    string destination;
    size_t weight;
    struct Edge *next;
} Edge;

// Adjacency List Representation
typedef struct Graph_Repr
{
    Vertex *vertices_head;
    // int nV; // Lectures had these but not sure if we need
    // int nE; // For counts, we can just loop through the adjacency lists
} Graph_Repr;

/***************************** HELPER FUNCTIONS ******************************/

void edge_list_destroy(Edge *edges)
{
    if (edges == NULL)
    {
        return;
    }

    Edge *curr = edges;
    Edge *prev = NULL;

    while (curr->next != NULL)
    {
        prev = curr;
        curr = curr->next;
        free(prev);
    }
    free(curr);
}

bool vertex_has_edge(Edge *edge_list, string destination) {
    printf("Checking if this vertex contains [%s]\n", destination);

    if (edge_list == NULL || edge_list->destination == NULL) {
        printf("Checkpoint A\n");
        return false;
    }

    Edge *curr_edge = edge_list;

    while (curr_edge->next != NULL) {
        printf("Edge found -->[%s]\n", curr_edge->destination);
        if (curr_edge->destination == destination) {
            printf("Checkpoint B\n");
            return true;
        }
        curr_edge = curr_edge->next;
    }
    

    if (curr_edge->destination == destination) {
        return true;
        printf("Checkpoint C\n");
    }
    
    return false;
}

/***************************** GENERAL INTERFACE ******************************/

graph graph_create(void)
{
    // Allocate memory for the list
    graph g = malloc(sizeof(Graph_Repr));
    assert(g != NULL);

    g->vertices_head = NULL;

    // Assign default values
    // g->nV = 0;
    // g->nE = 0;

    return g;
}

void graph_destroy(graph g)
{
    if (g == NULL || g->vertices_head == NULL)
    {
        return;
    }

    Vertex *curr = g->vertices_head;
    Vertex *prev = NULL;
    while (curr->next != NULL)
    {
        prev = curr;
        curr = curr->next;
        edge_list_destroy(curr->edges);
        free(prev);
    }
    free(curr);
}

void graph_show(graph, FILE *, list);

void graph_add_vertex(graph g, string s)
{
    // Return if we are given NULLS
    if (g == NULL || s == NULL)
        return;

    // Only add new vertex if it is not currently in the list
    if (!graph_has_vertex(g, s))
    {
        printf("Adding Vertex : %s\n", s);
        Vertex *newVertex = malloc(sizeof(Vertex));
        newVertex->edges = malloc(sizeof(Edge));
        newVertex->edges = NULL;
        newVertex->label = s;
        newVertex->next = g->vertices_head;
        g->vertices_head = newVertex;
    }
}

bool graph_has_vertex(graph g, string s)
{
    // If graph is empty, then return false
    if (g == NULL || g->vertices_head == NULL || s == NULL)
        return false;

    // Check all vartex in g->vertices if vertex-> label is equal to the string
    Vertex *curr = g->vertices_head;

    // Check all elements
    while (curr->next != NULL)
    {
        if (strcmp(curr->label, s) == 0)
            return true;
        curr = curr->next;
    }

    // Final element
    if (strcmp(curr->label, s) == 0)
    {
        return true;
    }
    
    return false;
}

size_t graph_vertices_count(graph g) {
    if (g == NULL || g->vertices_head == NULL)
        return 0;

    Vertex *curr = g->vertices_head;
    int count = 1;
    
    while (curr->next != NULL)
    {
        count++;
        curr = curr->next;
    }
    return count;
}

void graph_add_edge(graph g, string source, string destination, size_t weight) {
    // If any inputs are NULL, do nothing
    if (g == NULL || g->vertices_head == NULL || source == NULL || destination == NULL) return;

    // If graph already has this edge, do nothing
    if (graph_has_edge(g, source, destination)) return;

    printf("Adding edge: [%s]--%zu-->[%s]", source, weight, destination);

    Vertex *curr_vertex = g->vertices_head;
    while (curr_vertex->next != NULL) {
        // We enqueue a new edge IF the graph does not yet have this edge
        if (curr_vertex->label == source) {
            Edge *newEdge = malloc(sizeof(Edge));
            newEdge->destination = destination;
            newEdge->next = curr_vertex->edges;
            curr_vertex->edges = newEdge;   
        }
    }
}

bool graph_has_edge(graph g, string source, string destination) {
    // If any inputs are NULL, do nothing
    if (g == NULL || g->vertices_head == NULL || source == NULL || destination == NULL) false;

    printf("Checking if graph already contains [%s]-->[%s]\n", source, destination);

    // If the source or destination are not vertices on the graph, return false
    if (!graph_has_vertex(g, source) || !graph_has_vertex(g, destination)) false;

    printf("Graph contains source [%s]\n", source);
    printf("Graph contains vertex [%s]\n", destination);

    Vertex *curr_vertex = g->vertices_head;
    while (curr_vertex->next != NULL) {
        printf("Checking [%s]\n", curr_vertex->label);
        if (curr_vertex->label == source) {
            return vertex_has_edge(curr_vertex->edges, destination);
        }
        curr_vertex = curr_vertex->next;
    }

    printf("Checking final\n");
    return vertex_has_edge(curr_vertex->edges, destination);
}


void graph_set_edge(graph, string, string, size_t);

size_t graph_get_edge(graph, string, string);

size_t graph_edges_count(graph, string);

// bool validV(graph g, Vertex x) {
//     printf("%s\n", g->edges[0][0]);
//     return true;
// }

// bool adjacent(graph g, Vertex x, Vertex y) {
//     assert(g != NULL && validV(g,x));
//     return list_contains(g->edges[x], y);
// }

// scp graph.c z5114919@login.cse.unsw.edu.au:~/9024/assignment