#include "graph.h"

void FMIGraph::addNode(int index)
{
    if (index < 0)
    {
        return;
    }

    if (index >= nodes.size())
    {
        nodes.resize(index + 1);
    }
}

void FMIGraph::removeNode(int index)
{
    if (index < 0 || index >= nodes.size())
    {
        return;
    }

    Node& toRemove = nodes[index];
    // Node: std::vector<int> siblingIndeces;
    // interate siblings and remove node from their sibling lists
    
    for (int i : toRemove.siblingIndeces)
    {
        removeSibling(i, index);
    }

    toRemove.siblingIndeces.clear();
}


void FMIGraph::addEdge(int from, int to)
{
    addNode(from);
    addNode(to);

    for (int i : nodes[from].siblingIndeces)
    {
        if (i == to)
        {
            return;
        }
    }

    nodes[from].siblingIndeces.push_back(to);
    nodes[to].siblingIndeces.push_back(from);
}

void FMIGraph::removeSibling(int from, int to)
{
    if (from < 0 || from >= nodes.size() ||
        to < 0 || to >= nodes.size())
    {
        return;
    }

    Node& removeFrom = nodes[from];

    for (auto it = removeFrom.siblingIndeces.begin(); it != removeFrom.siblingIndeces.end(); ++it)
    {
        if (*it == to)
        {
            removeFrom.siblingIndeces.erase(it);
            break;
        }
    }
}

void FMIGraph::removeEdge(int from, int to)
{
    removeSibling(from, to);
    removeSibling(to, from);
}