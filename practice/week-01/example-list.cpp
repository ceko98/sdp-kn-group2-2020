#include <iostream>

template<class T>
struct Node {
  T data;
  Node<T>* next;
  Node<T>* previous;

  Node(T vlaue) {
    this->data = vlaue;
    this->next = nullptr;
    this->previous = nullptr;
  }
};

template<class T>
class DDList {
private:
  Node<T>* first;

public:
  DDList() {
    this->first = nullptr;
  };

  void add(T value, int position) {
    if (this->first == nullptr) {
      this->first = new Node<T>(value);
      first->next = nullptr;
      first->previous = nullptr;
      return;
    }

    Node<T> *curr = this->first;
    while(position != 0 && curr->next != nullptr) {
      curr = curr->next;
      position--;
    }

    Node<T> *tmp = curr->next;
    Node<T> *newNode = new Node<T>(value);

    curr->next = newNode;
    newNode->previous = curr;

    newNode->next = tmp;
    if (tmp != nullptr) {
      tmp->previous = newNode;
    }
    // !! nullptr->next
  }

  void print() {
    if (this->first == nullptr) {
      return;
    }

    Node<T> *curr = first;
    while (curr != nullptr) {
      std::cout << curr->data << " ";
      curr = curr->next;
    }
    std::cout << std::endl;
  }
};

int main() {
  DDList<int> list;

  list.add(2, 1);
  list.print();
  list.add(1, 2);
  list.print();


  return 0;
}