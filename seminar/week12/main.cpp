#include <iostream>
#include "graph.h"
#include "breadthfirstgraph.h"

int main()
{
    FMIGraph myGraph(5);
    myGraph.addEdge(1, 2);
    myGraph.addEdge(1, 3);
    myGraph.addEdge(1, 5);
    myGraph.addEdge(2, 3);
    myGraph.addEdge(3, 4);
    myGraph.addEdge(3, 5);
    myGraph.addEdge(4, 5);

    BreadthFirstGraph bfg(&myGraph, 2);
    for (auto i : bfg)
    {
        std::cout << i << " ";
    }

    std::cout << "\n";
    return 0;
}