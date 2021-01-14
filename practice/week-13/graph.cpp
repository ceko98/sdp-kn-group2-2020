#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using std::cin;
using std::cout;
using std::queue;
using std::vector;

class Graph
{
private:
    int numberOfVertecies;
    vector<int> *graph;
    vector<int> *weights;
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
    void findPathDfs(int start, int end);
    void findShortestPathBfs(int start, int end);
    void dijkstra(int start, int end);
};

Graph::Graph(bool weighted = false)
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
    weights = new vector<int>[numberOfVertecies];
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

        if (weighted)
        {
            cin >> w;
            weights[n].push_back(w);
            weights[m].push_back(w);
        }
    }
}

void Graph::clear()
{
    delete[] graph;
    delete[] weights;
    delete[] used;
    delete[] prev;
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

void Graph::findPathDfs(int curr, int end)
{
    used[curr] = true;
    if (curr == end)
    {
        std::vector<int> path;
        int i = curr;
        while (i != -1)
        {
            path.push_back(i);
            i = prev[i];
        }

        std::reverse(path.begin(), path.end());
        for (auto i : path)
        {
            cout << i << " ";
        }
        cout << std::endl;

        return;
    }

    for (int i = 0; i < graph[curr].size(); i++)
    {
        int sibling = graph[curr][i];
        if (!used[sibling])
        {
            prev[sibling] = curr;
            findPathDfs(sibling, end);
        }
    }
}

void Graph::findShortestPathBfs(int start, int end)
{
    queue<int> q;
    q.push(start);
    used[start] = true;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        if (curr == end)
        {
            std::vector<int> path;
            int i = curr;
            while (i != -1)
            {
                path.push_back(i);
                i = prev[i];
            }
            std::reverse(path.begin(), path.end());
            for (auto i : path)
            {
                cout << i << " ";
            }
            cout << std::endl;

            return;
        }

        for (int i = 0; i < graph[curr].size(); i++)
        {
            int sibling = graph[curr][i];
            if (!used[sibling])
            {
                prev[sibling] = curr;
                q.push(sibling);
                used[sibling] = true;
            }
        }
    }
}

void Graph::dijkstra(int start, int end)
{
    const int kinf_of_infinity = ~(1 << 31);
    int *cost = new int[numberOfVertecies];
    std::set<int> s;
    used[start] = true;

    for (int i = 0; i < numberOfVertecies; i++)
    {
        cost[i] = kinf_of_infinity;
        s.insert(i);
    }
    cost[start] = 0;

    while (!s.empty())
    {
        int curr = *s.begin();
        for (auto i : s)
        {
            if (cost[i] < cost[curr])
            {
                curr = i;
            }
        }

        s.erase(curr);
        used[curr] = true;

        for (int i = 0; i < graph[curr].size(); i++)
        {
            int sibling = graph[curr][i];
            int weightFromStartToI = cost[curr] + weights[curr][i];
            if (!used[sibling] && weightFromStartToI < cost[sibling])
            {
                cost[sibling] = weightFromStartToI;
                prev[sibling] = curr;
            }
        }
    }

    cout << cost[end] << "\n";
    std::vector<int> path;
    int i = end;
    while (i != -1)
    {
        path.push_back(i);
        i = prev[i];
    }

    std::reverse(path.begin(), path.end());
    for (auto i : path)
    {
        cout << i << " ";
    }
    cout << std::endl;

    delete[] cost;
}

int main()
{
    Graph g(true);
    cout << "\n";
    // g.findPathDfs(0, 5);
    // g.clearUsed();
    // g.findShortestPathBfs(0, 5);
    // g.clearUsed();
    g.dijkstra(5, 1);

    return 0;
}

/*
7
9
0 1 1
0 3 4
0 4 1
1 4 3
2 3 5
2 4 3
2 5 3
4 6 1
5 6 10

0 -> 1 2 3

0 -> 4 6 10

cost = [0, 1, i, 4, 1, i, i]
used = [t, t, _, _, _, _, _]

cost[1] = 1
1 -> 4 = 3
? 1 + 3 < cost[4] = 1;
if yes -> cost[4] = 1 + 3
*/