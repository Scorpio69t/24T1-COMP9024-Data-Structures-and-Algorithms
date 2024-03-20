## Representing Graphs
Three ways of representing graphs
1. Array of Edges
2. Adjacency Matrix
3. Adjacency List

Abstract Data Type (ADT)
* newGraph(V)
* insertEdge(g, (v,w))
* removeEdge(g, (v,w))
* show(g)

### 1. Array of Edges

1.1 Creating a new graph - O(1)

    newGraph(V):
        Input number of nodes V
        Output new empty graph

        g.nV = V // #vertices
        g.ne = 0 // #edges
        allocate enough memory for g.edges[]
        return g

1.2 Inserting an Edge - O(1)

    insertEdge(g, (v,w))
        Input graph g, edge (v,w)
        g.edges[g.nE] = (v,w)
        g.nE = g.nE + 1

1.3 Removing an Edge - O(E)

    removeEdge(g, (v,w))
        Input graph g, edge (v,w)

        i = 0
        while (v,w) != g.edges[i] do
            i = i + 1
        end while
        g.edges[i] = g.edges[g.nE-1]
        g.nE = g.nE - 1

1.4 Showing all edges - O(E)

    show(g)
    Input graph g
        for all i=0 to g.nE-1 do
            print g.edges[i]
        end for

### 2. Adjacency Matrix

A|0|1|2|3|
-|-|-|-|-|
0|0|1|2|3|
1|0|1|2|3|
2|0|1|2|3|
3|0|1|2|3|

2.1 Graph Initialisation - O(V^2)

    newGraph(V):
        Input number of nodes V
        Output new empty graph

        g.nV = V
        g.nE = 0
        allocate memory for g.edges[][]
        for all i,j = 0 .. V-1 do
            g.edges[i][j] = 0
        end for
        return g

2.2 Edge Insertion - O(1)

    insertEdge(g, (v,w)):
    Input graph g, edge (v,w)

    if g.edges[v][w] = 0 then
        g.edges[v][w] = 1
        g.edges[w][v] = 1 
        g.nE = g.nE + 1
    end if

2.3 Edge Removal - O(1)

    removeEdge(g, (v,w)):
    Input graph g, edge (v,w)

    g.edges[]
    if g.edges[v][w] != 0 then
        g.edges[v][w] = 0
        g.edges[w][v] = 0
        g.nE = g.nE - 1
    end if

2.4 Show Graph - O(V^2)

    show(g):
        Input graph g
        for all i = 0 to g.nV-2 do
            for all j = i+1 to g.nV-1 do
                if g.edges[i][j] then
                    print i-j
                end if
            end for
        end for


### 3. Adjacency List
* A[0] = <1, 3>
* A[1] = <0, 3>
* A[2] = <3>
* A[3] = <0, 1, 2>

3.1 Graph Initialisation - O(V)
    
    newGraph(V):
        Input number of nodes V
        Output graph g

        g.nV = V
        g.nE = 0
        allocate memory for g.edges[]
        for all i = 0.. V -1 do
            g.edges[i] = NULL
        end for
        return g

3.2 Edge Insertion - O(1)

    insertEdge(g, (v,w)):
        input graph g, edge (v,w)
        
        insertLL(g.edges[v],w)
        insertLL(g.edges[w],v)
        g.nE = g.nE+1

3.3 Edge Removal - O(V)

    removeEdge(g, (v,w)):
        Input graph g, edge (v,w)
        deleteLL(g.edges[v],w)
        deleteLL(g.edges[w],v)
        g.nE = g.nE-1

## Graph ADT


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
