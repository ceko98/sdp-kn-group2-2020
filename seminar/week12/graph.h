#ifndef FMI_GRAPH_H_
#define FMI_GRAPH_H_

#include <vector>
#include <iostream>
#include "queue.h"

// Графи
// G(V, E), V - върхове на граф, E - множество от ребра
// 1 начин: матрица на съседство
// 2 начин: списък от върхове и списъци от ребра (списъци от съседи)

// неориентиран граф
// върховете да са номерирани от 1 до n
class FMIGraph
{
public:
    FMIGraph(int n = 0) : nodes(n) {}
    FMIGraph(const FMIGraph&) = default;
    FMIGraph& operator=(const FMIGraph&) = default;

    void addNode(int index);
    void removeNode(int index);

    void addEdge(int from, int to);
    void removeEdge(int from, int to);

private:
    void removeSibling(int from, int to);

    struct Node
    {
        std::vector<int> siblingIndeces;

        const std::vector<int>& getSiblingIndeces() const
        {
            return siblingIndeces;
        }
    };

    std::vector<Node> nodes;
    const Node& getNode(int index) const
    {
        return nodes[index];
    }

    friend class BreadthFirstGraph;
    friend struct BFIterator;
};

#endif // FMI_GRAPH_H_