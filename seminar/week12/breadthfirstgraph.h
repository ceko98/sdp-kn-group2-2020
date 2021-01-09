#ifndef BREADTH_FIRST_GRAPH_H_
#define BREADTH_FIRST_GRAPH_H_

#include "graph.h"
#include "bfiterator.h"

class BreadthFirstGraph
{
public:
    BreadthFirstGraph(const FMIGraph* ptr, int beginIndex) : graph(ptr), startIdx(beginIndex) {}

    BFIterator begin()  { return BFIterator(graph, startIdx); }
    BFIterator end()    { return BFIterator(graph, -1); }

private:
    const FMIGraph* graph;
    int startIdx;
};

#endif // BREADTH_FIRST_GRAPH_H_