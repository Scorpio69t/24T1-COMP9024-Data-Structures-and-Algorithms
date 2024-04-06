// kevinngx - z5114919@ad.unsw.edu.au
// scp graph.c z5114919@login.cse.unsw.edu.au:~/9024/assignment
// scp makefile testGraph.c list.c list.h graph.c graph.h z5114919@login.cse.unsw.edu.au:~/9024/test_assignment_files
// scp crawler.c list.c graph.c z5114919@login.cse.unsw.edu.au:~/9024/assignment

#include "graph.h"
#include "pagerank.h"
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
    // If there are no edges, then we do nothing
    if (edges == NULL)
    {
        return;
    }

    Edge *curr = edges;
    Edge *prev = NULL;

    // Loop through the list of edges and remove each node
    while (curr->next != NULL)
    {
        prev = curr;
        curr = curr->next;
        free(prev->destination);
        free(prev);
    }

    // Remove the final node
    free(curr);
}

bool vertex_has_edge(Edge *edge_list, string destination)
{
    // printf("Checking if this vertex contains [%s]\n", destination);

    if (edge_list == NULL || edge_list->destination == NULL)
    {
        // printf("Edge list is NULL\n");
        return false;
    }

    Edge *curr_edge = NULL;
    curr_edge = edge_list;

    while (curr_edge->next != NULL)
    {
        if (strcmp(curr_edge->destination, destination) == 0)
        {
            return true;
        }
        curr_edge = curr_edge->next;
    }

    if (strcmp(curr_edge->destination, destination) == 0)
    {
        return true;
    }

    return false;
}

/***************************** GRAPH INTERFACE ******************************/

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

void show_vertex_edges(Edge *edge_list, FILE *f, string label, list ignore_list)
{
    if (edge_list == NULL)
        return;
    Edge *curr_edge = edge_list;
    while (curr_edge->next != NULL)
    {
        // for all edges linked to the vertex
        if (list_contains(ignore_list, curr_edge->destination) == false)
        {
            if (f != NULL)
            {
                fprintf(f, "%s %s %zu\n", label, curr_edge->destination, curr_edge->weight);
            }
            else
            {
                printf("%s %s %zu\n", label, curr_edge->destination, curr_edge->weight);
            }
        }
        curr_edge = curr_edge->next;
    }
    // repeat for last element
    if (list_contains(ignore_list, curr_edge->destination) == false)
    {
        if (f != NULL)
        {
            fprintf(f, "%s %s %zu\n", label, curr_edge->destination, curr_edge->weight);
        }
        else
        {
            printf("%s %s %zu\n", label, curr_edge->destination, curr_edge->weight);
        }
    }
}

void graph_show(graph g, FILE *f, list ignore_list)
{
    if (g == NULL || ignore_list == NULL)
        return;

    // Print out vertices
    Vertex *curr_vertex = g->vertices_head;
    if (curr_vertex == NULL)
        return;

    while (curr_vertex->next != NULL)
    {
        // For all vertexes
        if (list_contains(ignore_list, curr_vertex->label) == false)
        {
            if (f != NULL)
            {
                fprintf(f, "%s\n", curr_vertex->label);
            }
            else
            {
                printf("%s\n", curr_vertex->label);
            }
        }
        curr_vertex = curr_vertex->next;
    }
    // One more time for the last one
    if (list_contains(ignore_list, curr_vertex->label) == false)
    {
        if (f != NULL)
        {
            fprintf(f, "%s\n", curr_vertex->label);
        }
        else
        {
            printf("%s\n", curr_vertex->label);
        }
    }

    // Print out edges
    curr_vertex = g->vertices_head;
    while (curr_vertex->next != NULL)
    {
        if (list_contains(ignore_list, curr_vertex->label) == false)
        {
            show_vertex_edges(curr_vertex->edges, f, curr_vertex->label, ignore_list);
        }

        curr_vertex = curr_vertex->next;
    }
    if (list_contains(ignore_list, curr_vertex->label) == false)
    {
        show_vertex_edges(curr_vertex->edges, f, curr_vertex->label, ignore_list);
    }
}

void graph_add_vertex(graph g, string s)
{
    // Return if we are given NULLS
    if (g == NULL || s == NULL)
        return;

    // Only add new vertex if it is not currently in the list
    if (!graph_has_vertex(g, s))
    {
        // printf("Adding Vertex : %s\n", s);
        Vertex *newVertex = malloc(sizeof(Vertex));
        newVertex->edges = malloc(sizeof(Edge));
        newVertex->edges = NULL;
        string input_data = malloc(strlen(s) + 1);
        strcpy(input_data, s);
        newVertex->label = input_data;
        newVertex->next = NULL;

        // Prepend to the list
        // newVertex->next = g->vertices_head;
        // g->vertices_head = newVertex;

        if (g->vertices_head == NULL)
        {
            // Add the new Vertex as the head of ther vertices list
            g->vertices_head = newVertex;
            return;
        }
        else
        {
            // Append to the end
            Vertex *curr = g->vertices_head;
            while (curr->next != NULL)
            {
                curr = curr->next;
            }
            curr->next = newVertex;
        }
    }
}

bool graph_has_vertex(graph g, string s)
{
    // If graph is empty, then return false
    if (g == NULL || g->vertices_head == NULL || s == NULL)
        return false;

    // Check all vartex in g->vertices if vertex-> label is equal to the string
    // Adding additional here to account for uninitialised pointer error
    Vertex *curr = NULL;
    curr = g->vertices_head;
    if (curr == NULL)
        return false;

    // printf("Checking labels on graph for vertex: [%s]\n", s);
    graph_show(g, NULL, NULL);

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

size_t graph_vertices_count(graph g)
{
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

void graph_add_edge(graph g, string source, string destination, size_t weight)
{
    // If any inputs are NULL, do nothing
    if (g == NULL || g->vertices_head == NULL || source == NULL || destination == NULL)
        return;

    // printf("Attempting to add edge: [%s]--%zu-->[%s]\n", source, weight, destination);

    // If graph already has this edge, do nothing
    // printf("Checking if the graph already has edge\n");
    if (graph_has_edge(g, source, destination))
    {
        // printf("Graph already has edge");
        return;
    }

    if (!graph_has_vertex(g, source))
    {
        graph_add_vertex(g, source);
    }

    if (!graph_has_vertex(g, destination))
    {
        graph_add_vertex(g, destination);
    }

    // printf("Attempting to add edge: \n");
    Vertex *curr_vertex = g->vertices_head;
    Edge *newEdge = malloc(sizeof(Edge));
    string dest = malloc(strlen(destination) + 1);
    strcpy(dest, destination);
    newEdge->destination = dest;
    newEdge->weight = weight;
    newEdge->next = NULL;

    while (curr_vertex->next != NULL)
    {
        // We enqueue a new edge IF the graph does not yet have this edge
        if (strcmp(curr_vertex->label, source) == 0)
        {
            if (curr_vertex->edges == NULL)
            {
                curr_vertex->edges = newEdge;
            }
            else
            {
                Edge *curr_edge = curr_vertex->edges;
                while (curr_edge->next != NULL)
                {
                    curr_edge = curr_edge->next;
                }
                curr_edge->next = newEdge;
            }
            // printf("[%s]-%zu->[%s] Succesfully added!\n", source, weight, destination);
        }
        curr_vertex = curr_vertex->next;
    }

    // Add for final element
    if (strcmp(curr_vertex->label, source) == 0)
    {
        {
            if (curr_vertex->edges == NULL)
            {
                curr_vertex->edges = newEdge;
            }
            else
            {
                Edge *curr_edge = curr_vertex->edges;
                while (curr_edge->next != NULL)
                {
                    curr_edge = curr_edge->next;
                }
                curr_edge->next = newEdge;
            }
            // printf("[%s]-%zu->[%s] Succesfully added!\n", source, weight, destination);
        }
    }
}

bool graph_has_edge(graph g, string source, string destination)
{
    // If any inputs are NULL, do nothing
    if (g == NULL || g->vertices_head == NULL || source == NULL || destination == NULL)
        false;

    // printf("Checking if graph already contains [%s]-->[%s]\n", source, destination);

    // If the source or destination are not vertices on the graph, return false
    if (!graph_has_vertex(g, source) || !graph_has_vertex(g, destination))
        return false;

    Vertex *curr_vertex = g->vertices_head;
    while (curr_vertex->next != NULL)
    {
        if (strcmp(curr_vertex->label, source) == 0)
        {
            // Check if source has edge connecting to the destination
            return vertex_has_edge(curr_vertex->edges, destination);
        }
        curr_vertex = curr_vertex->next;
    }

    return vertex_has_edge(curr_vertex->edges, destination);
}

void vertex_set_edge(Edge *edge_list, string destination, size_t weight)
{
    if (edge_list == NULL)
        return;
    Edge *curr_edge = edge_list;
    while (curr_edge->next != NULL)
    {
        if (strcmp(curr_edge->destination, destination) == 0)
        {
            curr_edge->weight = weight;
            return;
        }
        curr_edge = curr_edge->next;
    }

    if (strcmp(curr_edge->destination, destination) == 0)
    {
        curr_edge->weight = weight;
        return;
    }
}

void graph_set_edge(graph g, string source, string destination, size_t weight)
{
    if (g == NULL || g->vertices_head == NULL || source == NULL || destination == NULL)
        return;

    // If the source or destination are not vertices on the graph, return false
    if (!graph_has_vertex(g, source) || !graph_has_vertex(g, destination))
        return;

    // Loop until we find the source vertex and then set the edge
    Vertex *curr_vertex = g->vertices_head;
    while (curr_vertex->next != NULL)
    {
        if (strcmp(curr_vertex->label, source) == 0)
        {
            // Check if source has edge connecting to the destination
            vertex_set_edge(curr_vertex->edges, destination, weight);
            return;
        }
        curr_vertex = curr_vertex->next;
    }

    vertex_set_edge(curr_vertex->edges, destination, weight);
}

size_t vertex_get_edge(Edge *edge_list, string destination)
{
    if (edge_list == NULL)
        return 0;

    Edge *curr_edge = edge_list;
    while (curr_edge->next != NULL)
    {
        if (strcmp(curr_edge->destination, destination) == 0)
        {
            return curr_edge->weight;
        }
        curr_edge = curr_edge->next;
    }

    if (strcmp(curr_edge->destination, destination) == 0)
    {
        return curr_edge->weight;
    }
    return 0;
}

size_t graph_get_edge(graph g, string source, string destination)
{
    if (g == NULL || g->vertices_head == NULL || source == NULL || destination == NULL)
        return 0;

    // If the source or destination are not vertices on the graph, return 0
    if (!graph_has_vertex(g, source) || !graph_has_vertex(g, destination))
        return 0;

    // Loop until we find the source vertex and then set the edge
    Vertex *curr_vertex = g->vertices_head;
    while (curr_vertex->next != NULL)
    {
        if (strcmp(curr_vertex->label, source) == 0)
        {
            // Check if source has edge connecting to the destination
            return vertex_get_edge(curr_vertex->edges, destination);
        }
        curr_vertex = curr_vertex->next;
    }

    return vertex_get_edge(curr_vertex->edges, destination);
}

size_t vertex_edge_count(Edge *edge_list)
{

    if (edge_list == NULL)
        return 0;

    Edge *curr_edge = edge_list;
    size_t count = 1;

    while (curr_edge->next != NULL)
    {
        count++;
        curr_edge = curr_edge->next;
    }

    return count;
}

size_t graph_edges_count(graph g, string source)
{
    if (g == NULL || g->vertices_head == NULL || source == NULL)
        return 0;

    // If the source vertex is not on the graph, return 0
    if (!graph_has_vertex(g, source))
        return 0;

    Vertex *curr_vertex = g->vertices_head;
    while (curr_vertex->next != NULL)
    {
        if (strcmp(curr_vertex->label, source) == 0)
        {
            // Check if source has edge connecting to the destination
            return vertex_edge_count(curr_vertex->edges);
        }
        curr_vertex = curr_vertex->next;
    }

    return vertex_edge_count(curr_vertex->edges);
}

