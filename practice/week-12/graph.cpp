#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::vector;

class Graph
{
private:
    int numberOfVertecies;
    vector<int> * graph;
    bool * used;
public:
    Graph();
    ~Graph();
    void init();
    void clear();
    void dfsPrint(int start);
    void bfsPrint(int start);
};

Graph::Graph()
{
    init();
}

Graph::~Graph()
{
    clear();
}

void Graph::init()
{
    cin >> numberOfVertecies;
    graph = new vector<int>[numberOfVertecies];
    used = new bool[numberOfVertecies];
    
    int numberOfEdges;
    cin >> numberOfEdges;

    for (int i = 0; i < numberOfEdges; i++)
    {
        int n, m;
        cin >> n >> m;
        graph[n].push_back(m);
        graph[m].push_back(n);
    }
}

void Graph::clear()
{
    delete [] graph;
    delete [] used;
}

void Graph::dfsPrint(int start)
{
    used[start] = true;
    cout << start << " ";
    
    for (int i = 0; i < graph[start].size(); i++)
    {
        if (!used[ graph[start][i] ]) {
            dfsPrint(graph[start][i]);
        }
    }
}

void Graph::bfsPrint(int start)
{
    
}

int main()
{
    Graph g;
    cout << "\n\n";
    g.dfsPrint(0);
    return 0;
}

/*

6
7
0 3
0 1
1 2
1 3
3 4
3 5
4 5

*/