#ifndef BF_ITERATOR_H_
#define BF_ITERATOR_H_

#include <vector>
#include "queue.h"
#include "graph.h"

// wrap - обвивам
// wrapper - обвивка

struct BFIterator
{
private:
    const FMIGraph* graph;
    int currentIndex;
    FMIQueue<int> nextIndeces;
    std::vector<bool> metIndeces;

public:
    BFIterator(const FMIGraph* parent, int index);

    int operator*() { return currentIndex; }

    BFIterator& operator++();

    bool operator==(const BFIterator& other)
    {
        return graph == other.graph && currentIndex == other.currentIndex;
    }

    bool operator!=(const BFIterator& other)
    {
        return !(*this == other);
    }
};

#endif // BF_ITERATOR_H_