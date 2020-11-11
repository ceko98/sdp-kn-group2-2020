#include <iostream>

template<class T>
class List {
public:
  struct Node {
    T data;
    Node *next;
  };

private:
  Node *first;

public:
  List();
  ~List();

  void insetAtStart(T data);
  void print();
  void at(T data, int position);
  void sort();
  Node* getFirst();
  List<T>& unionList(List<T>& list);
  void difference(List<T>& list);
  void setCyclic();
  bool detectCycle();
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

template<class T>
void List<T>::sort() {
  Node *newFirst = nullptr;
  Node *tmpFirst = this->first;
  Node *newFirstCurr = nullptr;

  while (tmpFirst != nullptr) {
    Node *curr = tmpFirst;
    Node *prev = nullptr;

    Node *currMin = curr, *prevMin = prev;
    while (curr != nullptr) {
      if (currMin->data > curr->data) {
        currMin = curr;
        prevMin = prev;
      }
      prev = curr;
      curr = curr->next;
    }

    if (newFirst == nullptr) {
      newFirst = currMin;
      newFirstCurr = newFirst;
    } else {
      newFirstCurr->next = currMin;
      newFirstCurr = newFirstCurr->next;
    }
    
    if (currMin == tmpFirst) {
      tmpFirst = tmpFirst->next;
    } else {
      prevMin->next = prevMin->next->next;
    }
  }

  this->first = newFirst;
}

template<class T>
typename List<T>::Node * List<T>::getFirst() {
  return this->first;
} 

template<class T>
List<T>& List<T>::unionList(List<T>& list) {
  List<T>::Node *secondFirst = list.getFirst();
}

template<class T>
void List<T>::difference(List<T>& list) {
  Node *secondCurr = list.getFirst();;

  while (secondCurr != nullptr) {
    Node *firstCurr = this->first;
    Node *firstPrev = nullptr;

    while (firstCurr != nullptr) {
      if (secondCurr->data == firstCurr->data) {
        if (firstCurr == this->first) {
          this->first = this->first->next;
        } else {
          firstPrev->next = firstCurr->next;
        }

        delete firstCurr;
        firstCurr = firstPrev->next;
      }

      firstPrev = firstCurr;
      firstCurr = firstCurr->next;
    }

    secondCurr = secondCurr->next;
  }
}

template<class T>
void List<T>::setCyclic() {
  Node *a1 = new Node();
  Node *a2 = new Node();
  Node *a3 = new Node();
  Node *a4 = new Node();

  a1->next = a2;
  a2->next = a3;
  a3->next = a4;
  a4->next = a2;

  a1->data = 4;
  a2->data = 1;
  a3->data = 7;
  a4->data = 10;

  this->first = a1;
}

template<class T>
bool List<T>::detectCycle() {
  Node *curr1 = this->first;
  Node *curr2 = this->first;

  while (curr2 != nullptr)
  {
    curr1 = curr1->next;
    curr2 = curr2->next;
    if (curr2->next) {
      curr2 = curr2->next;
    }
    //           v
    // 1 -> 2 -> 3 -> nullptr -> segmetation fault
    if (curr1 == curr2) {
      return true;
    }
  }
  return false;
}

int main() {
  List<int> list;
  List<int> list2;

  list.insetAtStart(7);
  list.insetAtStart(4);
  list.insetAtStart(1);
  list.insetAtStart(10);
  list.print();
  std::cout << std::endl;
  // list.sort();
  // list.print();
  // std::cout << std::endl;

  list2.insetAtStart(1);
  list2.insetAtStart(5);

  list.difference(list2);
  list.print();
  std::cout << std::endl;

  List<int> cyclic;
  cyclic.setCyclic();
  // cyclic.print();
  std::cout << cyclic.detectCycle() << std::endl;

  q.front() // position (1,1)
  int numberOfPositions = 3;
  while (/**/)
    q.push(/*new position*/);


  return 0;
}

/*
          v1      v2
  |10| -> |7| -> |1| -> |4| -|
            ^----         <---

  newFirst
*/