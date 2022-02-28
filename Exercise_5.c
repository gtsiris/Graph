#include <stdio.h>
#include <stdlib.h>
#include "GRAPHInterface.h"



int main(void) {
  Graph *graph = malloc(sizeof(Graph));
  int i;
  graph->n = MAXVERTEX;
  for (i = 0; i < MAXVERTEX; i++) {
    graph->firstedge[i] = malloc(sizeof(Edge));
    graph->firstedge[i]->endpoint = i;
    if (i+1 != MAXVERTEX)
      graph->firstedge[i]->nextedge = graph->firstedge[i+1];
    else
      graph->firstedge[i]->nextedge = graph->firstedge[0];
  }
  if (GraphIsCyclic(*graph))
    printf("Graph is cyclic!\n");
  else
    printf("Graph is acyclic!\n");
  return 0;
}
