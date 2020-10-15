#include <iostream>

template<class T>
class List {
  private:
  struct Node
  {
    T data;
    Node *next;
  };

  Node *first;
  
  public:
  List();
  ~List();
  void atBegining(T data);
  void print();
};

template<class T>
List<T>::List() : first(nullptr) { }

template<class T>
List<T>::~List() {
  Node *curr = this->first, *prev = nullptr;
  while(curr != nullptr) {
    prev = curr;
    curr = curr->next;
    delete prev;
  }
}

template<class T>
void List<T>::atBegining(T data) {
  Node *newNode = new Node();
  newNode->data = data;
  newNode->next = this->first;
  this->first = newNode;
}

template<class T>
void List<T>::print() {
  Node *curr = this->first;
  while(curr != nullptr) {
    std::cout << curr->data << " ";
    curr = curr->next;
  }
}