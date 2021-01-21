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
    Graph(bool weighted);
    ~Graph();
    void init(bool weighted);
    void clear();
    void clearUsed();
    void dfsPrint(int start);
    void bfsPrint(int start);
    int shortestBetween(int start, int end);
    void printLevels(int start);
    int longestBetween(int start, int end);
    bool isConnected();
    void dijkstra(int start, int end);
    void dfsPath(int start, int end);
    void dfsPathWrap(int start, int end);

};

Graph::Graph(bool weighted)
{
    init(weighted);
}

Graph::~Graph()
{
    clear();
}

void Graph::init(bool weighted)
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
        int n, m, w;
        cin >> n >> m;
        graph[n].push_back(m);
        graph[m].push_back(n);
        if (weighted) {
            cin >> w;
            cost[m].push_back(w);
            cost[n].push_back(w);
        }
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
    for (int i = 0; i < numberOfVertecies; i++)
    {
        prev[i] = -1;
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


void Graph::dijkstra(int start, int end) {
    const int kind_of_infinity = ~(1 << 31); // should return max positive int value
    std::set<int> s;
    used[start] = true;

    int *pathWigths = new int[numberOfVertecies];
    for (int i = 0; i < numberOfVertecies; i++)
    {
        pathWigths[i] = kind_of_infinity;
        s.insert(i);
    }
    pathWigths[start] = 0;

    while (!s.empty())
    {
        int curr = *s.begin();
        for (auto i : s)
        {
            if (pathWigths[curr] > pathWigths[i]) {
                curr = i;
            }
        }
        s.erase(curr);
        
        used[curr] = true;

        for (int i = 0; i < graph[curr].size(); i++)
        {
            int subling = graph[curr][i];
            int fromStartToI = pathWigths[curr] + cost[curr][i];
            if (!used[subling] && fromStartToI < pathWigths[subling])
            {
                pathWigths[subling] = fromStartToI;
                prev[subling] = curr;
            }
        }
    }

    cout << "asdf" << pathWigths[end] << "\n";

    int curr = end;
    while (curr != -1)
    {
        cout << curr << " ";
        curr = prev[curr];
    }
}

void Graph::dfsPath(int start, int end) {
    used[start] = true;
    if (start == end) {
        int curr = end;
        while (curr != -1)
        {
            cout << curr << " ";
            curr = prev[curr];
        }
        return;
    }
    // cout << start << " ";

    for (int i = 0; i < graph[start].size(); i++)
    {
        if (!used[graph[start][i]])
        {
            prev[graph[start][i]] = start;
            dfsPath(graph[start][i], end);
        }
    }
}

void Graph::dfsPathWrap(int start, int end) {

}

int main()
{
    Graph g(true);
    cout << "\n";
    g.dijkstra(1, 5);
    // g.dfsPath(1,5);

    return 0;
}

/*

7
9
0 1 1
0 4 1
0 3 4
1 4 3
2 5 3
3 2 3
4 2 3
4 6 1
6 5 10

*/