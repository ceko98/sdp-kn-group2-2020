#include "bfiterator.h"

BFIterator::BFIterator(const FMIGraph* parent, int index)
    : graph(parent),
    currentIndex(index),
    metIndeces(graph->nodes.size())
{
    for (int i = 0; i < metIndeces.size(); ++i)
    {
        metIndeces[i] = false;
    }

    if (currentIndex >= 0 && currentIndex < metIndeces.size())
    {
        metIndeces[currentIndex] = true;
    }
}

BFIterator& BFIterator::operator++()
{
    // std::cout << "Current node: " << currentIndex << "\n";
    const typename FMIGraph::Node& currentNode = graph->getNode(currentIndex);

    const std::vector<int>& siblingIndeces = currentNode.getSiblingIndeces();
    for (int i : siblingIndeces)
    {
        if (!metIndeces[i])
        {
            // std::cout << "Adding sibling " << i << "\n";
            nextIndeces.push_back(i);
            metIndeces[i] = true;
        }
    }

    if (nextIndeces.empty())
    {
        currentIndex = -1;
    }
    else
    {
        currentIndex = nextIndeces.peek();
        // std::cout << "Next index " << currentIndex << "\n";
        nextIndeces.pop();
    }

    return *this;
}
