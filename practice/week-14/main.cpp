#include <iostream>
#include <vector>
#include <pair>

using namespace std;

struct Node
{
    double data;
    Node *left, *right, *mid;
    Node(double data, Node *left = nullptr, Node *right = nullptr, Node *mid = nullptr)
        : data(data), left(left), right(right), mid(mid) {};
};

bool insert(Node *&root, double data, double R)
{
    if (root == nullptr) {
        root = new Node(data);
        return true;
    }

    if (data == root->data) {
        return false;
    }

    if (data < root->data * (1 - R))
    {
        return insert(root->left, data, R);
    }
    if (data > root->data * (1 + R))
    {
        return insert(root->right, data, R);
    }

    return insert(root->mid, data, R);
}

void printTree(Node * root)
{
    if (root == nullptr)
    {
        return;
    }
    
    printTree(root->left);
    cout << root->data << " ";
    printTree(root->mid);
    printTree(root->right);
}

class Graph
{
private:
    const static int MAX_SIZE = 100;
    vector<pair<int, int>> graph[MAX_SIZE];
    vector<int> weights[MAX_SIZE];

public:
    void init() {
        int edges;
        cin >> edges;
        for (int i = 0; i < edges; i++)
        {
            int a, b, w;
            cin >> a >> b >> w;
            graph[a].push_back({b, w});
            graph[b].push_back({a, w}); // undirected
            
            // wigths alternative
            // weights[a].push_back(w);
            // weights[b].push_back(w);
        }
    }
};


int main()
{
    Node * root = nullptr;

    insert(root, 100, 0.5);
    insert(root, 50, 0.4);  // 50 < 100 * (1 - 0.4) 
    insert(root, 108, 0.6);
    insert(root, 150, 0.4);

    printTree(root);
    cout <<  endl;
    cout << root->data << endl;
    cout << root->left->data;

    return 0;
}