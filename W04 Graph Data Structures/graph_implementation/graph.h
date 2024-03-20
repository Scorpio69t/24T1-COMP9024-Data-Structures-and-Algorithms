// graph representation is hidden
typedef struct GraphRep *Graph;

// vertices denoted by integers 0..N-1
typedef int Vertex;

// edges are pairs of vertices (end-points)
typedef struct Edge { Vertex v; Vertex w; } Edge;

// operations on graphs
Graph newGraph(int V);                 // new graph with V vertices
int   numOfVertices(Graph);            // get number of vertices in a graph
void  insertEdge(Graph, Edge);
void  removeEdge(Graph, Edge);
bool  adjacent(Graph, Vertex, Vertex); /* is there an edge
                                          between two vertices */
void  showGraph(Graph);                // print all edges in a graph
void  freeGraph(Graph);