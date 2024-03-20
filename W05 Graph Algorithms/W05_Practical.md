
# Graph Properties

Write pseudocode for *computing
* the degree of each vertex
* all 3-cliques (i.e. cliques of 3 nodes, "triangles")
* and the density

of an undirected graph g with n vertices
    
    # number of edges connected to a graph
    computeVertexDegree(g):
        input: graph g
        output: degree

        for i=0 .. V-1 
            check_edges(g[i])
        end for