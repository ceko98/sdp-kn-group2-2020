#include <iostream>
#include <vector>
#include <queue>
#include <set>

using std::cin;
using std::cout;
using std::queue;
using std::vector;

class Graph
{
private:
    int numberOfVertecies;
    vector<int> *graph;
    vector<int> *cost;
    int *prev;
    bool *used;

public:
    Graph();
    ~Graph();
    void init();
    void clear();
    void clearUsed();
    void dfsPrint(int start);
    void bfsPrint(int start);
    int shortestBetween(int start, int end);
    void printLevels(int start);
    int longestBetween(int start, int end);
    bool isConnected();
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
    cost = new vector<int>[numberOfVertecies];
    used = new bool[numberOfVertecies];
    prev = new int[numberOfVertecies];

    for (int i = 0; i < numberOfVertecies; i++)
    {
        prev[i] = -1;
    }

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
    delete[] graph;
    delete[] used;
}

void Graph::clearUsed()
{
    for (int i = 0; i < numberOfVertecies; i++)
    {
        used[i] = false;
    }
}

void Graph::dfsPrint(int start)
{
    used[start] = true;
    cout << start << " ";

    for (int i = 0; i < graph[start].size(); i++)
    {
        if (!used[graph[start][i]])
        {
            dfsPrint(graph[start][i]);
        }
    }
}

void Graph::bfsPrint(int start)
{
    queue<int> q;
    q.push(start);
    used[start] = true;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        cout << curr << " ";
        for (int i = 0; i < graph[curr].size(); i++)
        {
            if (!used[graph[curr][i]])
            {
                q.push(graph[curr][i]);
                used[graph[curr][i]] = true;
            }
        }
    }
}

int main()
{
    Graph g();
    cout << "\n";

    return 0;
}

/*

*/