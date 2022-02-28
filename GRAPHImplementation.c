#include <stdio.h>
#include "GRAPHInterface.h"



/* This code is a slightly changed version of the code of Chapter 11
of the book
"Data Structures and Program Design in C" by
R. Kruse, C. L. Tondo and B. Leung */



/* global variable visited */
Boolean visited[MAXVERTEX];


/* Traverse: recursive traversal of a graph
   Pre: v is a vertex of graph G.
   Post: The depth first traversal has been completed for v and for all vertices adjacent to v.
   Uses: Traverse recursively */
void Traverse(Graph G, Vertex v)
{
  Vertex w;
  Edge *curedge;

  visited[v]=TRUE;

  curedge=G.firstedge[v];      /* curedge is a pointer to the first edge (v,_) of V */
  while (curedge){
    w = curedge -> endpoint;        /* w is a successor of v and (v,w) is the current edge */
    if (!visited[w])
      Traverse(G, w);
    curedge=curedge->nextedge;  /*curedge is a pointer to the next edge (v,_) of V */
  }
}

/* GraphIsCyclic: test for cyclicity
   Pre: The graph G has been created.
   Post: Determine if the graph G is cyclic or not.
   Uses: Function Traverse produces the recursive depth-first order */
Boolean GraphIsCyclic(Graph G)
{

  Vertex v;

  for (v=0; v < G.n; v++)
    visited[v]=FALSE;
  for (v=0; v < G.n; v++) {
    if (!visited[v])
      Traverse(G, v);
    else                      /* Back edge is encountered during dfs so the graph is cyclic */
      return TRUE;
  }
  return FALSE;
}

/* PrintElement: prints the value of its parameter x */
void PrintElement(Vertex x)
{
  printf("%d\n", x);
}
