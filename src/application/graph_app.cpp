#include<iostream>
#include<Graph.h>
int main()
{
  Graph l_Grph;
  l_Grph.addEdge( 0, 1);
  l_Grph.addEdge( 0, 1);
  l_Grph.addEdge( 0, 4);
  l_Grph.addEdge( 1, 2);
  l_Grph.addEdge( 1, 3);
  l_Grph.addEdge( 1, 4);
  l_Grph.addEdge( 2, 3);
  l_Grph.addEdge( 3, 4);
  l_Grph.printGraph();
  l_Grph.doBFT(1);
  return 0;
} 
