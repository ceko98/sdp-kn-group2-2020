#include <iostream>
#include <vector>
#include <queue>

using std::cin;
using std::cout;
using std::queue;
using std::vector;

class Graph
{
private:
    int numberOfVertecies;
    vector<int> *graph;
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

int Graph::shortestBetween(int start, int end)
{
    queue<int> q;
    q.push(start);
    used[start] = true;
    q.push(-1); // delimiter

    int levelCount = 0;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        if (curr == end) {
            return levelCount;
        }

        if (curr == -1)
        {
            if (q.empty())
            {
                return levelCount;
            }
            q.push(-1);
            levelCount++;
        }
        else
        {
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

    return levelCount;
}

void Graph::printLevels(int start)
{
    queue<int> q;
    q.push(start);
    used[start] = true;
    q.push(-1); // delimiter

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        if (curr == -1)
        {
            cout << "\n";
            if (q.empty())
            {
                return;
            }
            q.push(-1);
        }
        else
        {
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
}

int Graph::longestBetween(int start, int end)
{
    if (start == end)
    {
        return 1;
    }

    used[start] = true;
    int maxLength = 0;
    for (int i = 0; i < graph[start].size(); i++)
    {
        if (!used[graph[start][i]])
        {
            int pathLength = longestBetween(graph[start][i], end);
            maxLength = std::max(maxLength, pathLength);
        }
    }
    used[start] = false;

    return maxLength == 0 ? 0 : maxLength + 1;
}

bool Graph::isConnected()
{
    this->bfsPrint(0);
    cout << "\n";
    for (int i = 0; i < numberOfVertecies; i++)
    {
        if (!used[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    Graph g;
    cout << "\n";
    g.dfsPrint(0);
    g.clearUsed();

    cout << "\n";
    g.clearUsed();
    g.bfsPrint(0);

    cout << "\n";
    g.clearUsed();
    cout << g.shortestBetween(0, 0) << "\n";

    cout << "\n";
    g.clearUsed();
    g.printLevels(0);

    cout << "\n";
    g.clearUsed();
    cout << g.longestBetween(0, 2) - 1 << "\n";

    cout << "\n";
    g.clearUsed();
    cout << g.isConnected() << "\n";

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

7
7
0 3
0 1
1 2
1 3
3 4
3 5
4 5

*/