#ifndef FMI_TREE_H_
#define FMI_TREE_H_

#include <functional>

// Дърво => вид граф
// Граф: G(V, E)
// V - множество, върхове на граф
// E - множество от наредени двойки, ребра на граф
// Път - (a0, a1 ... an), a0 ... an: върхове, (a0, a1) ... (an-1, an): ребра
// Цикъл - път (a0, a1, .... an-1, an, a0)
// Дърво - граф без цикли
// Двоично наредено дърво:
//  - двоично: всеки връх има не повече от 2 наследници
//  - наредено: всички елементи в лявото поддърво на дад. елемент
//              са по-малки от него, всички в дясното поддърво са
//              по-големи от него

template <typename T>
class FMIBinTree
{
public:
    struct Node
    {
        T data;
        Node *left;
        Node *right;
    };
private:
    Node *root;

    Node* copyNode(Node* node);
    void copy(const FMIBinTree& other)
    {
        root = copyNode(other.root);
    }

    void clearNode(Node* node);
    void clear()
    {
        clearNode(root);
        root = nullptr;
    }

    void executeOnNode(Node* node, const std::function<void(const T&)>& functor);
public:
    FMIBinTree() : root(nullptr) {}
    FMIBinTree(const FMIBinTree& other) : root(nullptr)
    {
        copy(other);
    }

    FMIBinTree& operator=(const FMIBinTree& other)
    {
        if (this != &other)
        {
            void copy(const FMIBinTree& other);
            void clear();
        }

        return *this;
    }

    ~FMIBinTree()
    {
        clear();
    }

    // публичен интерфейс
    bool push(const T& data);
    bool erase(const T& data);
    bool contains(const T& data);
    bool empty() { return root == nullptr; }

    void executeInDepth(const std::function<void(const T&)>& functor)
    {
        executeOnNode(root, functor);
    }
};

template <typename T>
typename FMIBinTree<T>::Node* FMIBinTree<T>::copyNode(Node* node)
{
    if (!node)
    {
        return nullptr;
    }

    Node* result = new Node();
    result->data = node->data;
    result->left = copyNode(node->left);
    result->right = copyNode(node->right);

    return result;
}

template <typename T>
void FMIBinTree<T>::clearNode(Node* node)
{
    if (!node)
    {
        return;
    }

    clearNode(node->left);
    clearNode(node->right);
    delete node;
}

template <typename T>
void FMIBinTree<T>::executeOnNode(Node* node, const std::function<void(const T&)>& functor)
{
    if (!node)
    {
        return;
    }

    functor(node->data);
    executeOnNode(node->left, functor);
    executeOnNode(node->right, functor);
}

template <typename T>
bool FMIBinTree<T>::push(const T& data)
{
    Node* newCell = new Node();
    newCell->data = data;
    newCell->left = nullptr;
    newCell->right = nullptr;

    if (!root)
    {
        root = newCell;
        return true;
    }

    Node* tmp = root;
    while (tmp)
    {
        if (tmp->data == data)
        {
            return false;
        }

        if (data < tmp->data)
        {
            if (!tmp->left)
            {
                tmp->left = newCell;
                return true;
            }

            tmp = tmp->left;
        }
        else
        {
            if (!tmp->right)
            {
                tmp->right = newCell;
                return true;
            }

            tmp = tmp->right;
        }
    }

    return false;
}

template <typename T>
bool FMIBinTree<T>::erase(const T& data)
{
    Node** tmp = &root;

    while (*tmp)
    {
        if ((*tmp)->data == data)
        {
            break;
        }
        else if (data < (*tmp)->data)
        {
            tmp = &((*tmp)->left);
        }
        else
        {
            // (Node**) tmp
            // => (Node*) *tmp
            // => (Node*) (*tmp)->right;
            // => (Node**) &(*tmp)->right;
            tmp = &((*tmp)->right);
        }
    }

    if (*tmp == nullptr)
    {
        return false;
    }

    if ((*tmp)->left)
    {
        // търсим най-десния елемент
        Node** childToSwap = &(*tmp)->left;
        while ((*childToSwap)->right)
        {
            childToSwap = &(*childToSwap)->right;
        }

        Node* toDelete = *childToSwap;
        (*tmp)->data = (*childToSwap)->data;
        *childToSwap = (*childToSwap)->left;

        delete toDelete;
        return true;
    }
    else if ((*tmp)->right)
    {
        // търсим най-левия елемент
        Node** childToSwap = &(*tmp)->right;
        while ((*childToSwap)->left)
        {
            childToSwap = &(*childToSwap)->left;
        }

        Node* toDelete = *childToSwap;
        (*tmp)->data = (*childToSwap)->data;
        *childToSwap = (*childToSwap)->right;

        delete toDelete;
        return true;
    }
    else
    {
        delete *tmp;
        *tmp = nullptr;
        return true;
    }
}

template <typename T>
bool FMIBinTree<T>::contains(const T& data)
{
    Node* tmp = root;
    while (tmp)
    {
        if (tmp->data == data)
        {
            return true;
        }

        if (data < tmp->data)
        {
            tmp = tmp->left;
        }
        else
        {
            tmp = tmp->right;
        }
    }

    return false;
}

#endif // FMI_TREE_H_