#include <iostream>

class BinTree {
public:
    struct Node {
        int data;
        Node * left;
        Node * right;
        Node(int newData, Node * left = nullptr, Node * right = nullptr)
            : data(newData), left(left), right(right) {}
    };

    BinTree() : root(nullptr) {};
    void add(int element, const char * path) {  // "LRRL"
        if (this->root == nullptr) {
            root = new Node(element);
            return;
        }
        Node * curr = this->root;

        while(path[1]) {
            if (path[0] == 'L') {
                curr = curr->left;
            }
            if (path[0] == 'R') {
                curr = curr->right;
            }
            path++;
        }

        if(path[0] == 'L' && curr->left == nullptr) {
            curr->left = new Node(element);
        } else if(path[0] == 'R' && curr->right == nullptr) {
            curr->right = new Node(element);
        }
    }

    void print() {
        this->printHelper(this->root);
    }

private:
    Node * root;
    void printHelper(Node * node) {
        if (node == nullptr) {
            return;
        }

        std::cout << node->data << " ";
        printHelper(node->left);
        printHelper(node->right);
    }
};

int main() {
    BinTree t;
    t.add(1, "");
    t.add(2, "L");
    t.add(3, "R");
    t.add(4, "LL");

    t.print();

    return 0;
}