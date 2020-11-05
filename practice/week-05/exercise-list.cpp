#include <iostream>

template<class T>
class List {
private:
  struct Node {
    T data;
    Node *next;
  };

  Node *first;

public:
  List();
  ~List();

  void insetAtStart(T data);
  void print();
  void at(T data, int position);
};

template<class T>
List<T>::List() : first(nullptr) { }

template<class T>
List<T>::~List() {
  List<T>::Node *curr = this->first;
  while (curr != nullptr) {
    List<T>::Node *tmp = curr;
    curr = curr->next;
    delete tmp;
  }
}

template<class T>
void List<T>::insetAtStart(T data) {
  List<T>::Node *newNode = new List<T>::Node();
  newNode->data = data;
  
  if (this->first == nullptr) {
    this->first = newNode;
    return;
  }

  newNode->next = this->first;
  this->first = newNode;
}


template<class T>
void List<T>::print() {
  List<T>::Node *curr = this->first;
  while (curr != nullptr) {
    std::cout << curr->data << " ";
    curr = curr->next;
  }
}

template<class T>
void List<T>::at(T data, int position) {
  List<T>::Node *newNode = new Node();
  newNode->data = data;

  if(position == 0) {
    this->insetAtStart(data);
    return;
  }

  List<T>::Node *curr = first;
  while (curr->next != nullptr && position != 1) {
    curr = curr->next;
    position--;
  }
  
  newNode->next = curr->next;
  curr->next = newNode;
}

int main() {
  List<int> list;

  list.insetAtStart(3);
  list.insetAtStart(2);
  list.insetAtStart(1);
  
  return 0;
}