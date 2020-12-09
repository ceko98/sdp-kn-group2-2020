#include <iostream>
#include <queue>
#include <stack>

template<class T>
class List {
public:
  struct Node {
    T data;
    Node *next;

    Node(T data) : data(data), next(nullptr) {

    }
  };

private:
  Node *first;

public:
  List();
  ~List();

  void insetAtStart(T data);
  void print();
  void at(T data, int position);
  void append(List<T>& other); // this->list = l1,  other = l2
  Node * getFirst() {
      return this->first;
  };
    T reduce(T(*operation)(T, T), T defaultValue);
    void shuffle();

    void equalStacks();
    void printForStacks();

  Node * copyList();
  bool subdup(int k);
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
  List<T>::Node *newNode = new List<T>::Node(data);
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
    std::cout << std::endl;
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
void List<T>::append(List<T>& other) {
    Node * curr = this->first;
    while (curr->next != nullptr) {
        curr = curr->next;
    }
    curr->next = other.copyList();
}

template<class T>
typename List<T>::Node * List<T>::copyList() {
    Node * newFirst = nullptr;
    Node * curr = this->first;
    Node * curr2 = nullptr;

    while (curr != nullptr) {
        Node * tmp = new Node(curr->data);

        if(newFirst == nullptr) {
            newFirst = tmp;
            curr2 = newFirst;
        } else {
            curr2->next = tmp;
            curr2 = curr2->next;
        }

        curr = curr->next;
    }
    return newFirst;
}

template<class T>
bool List<T>::subdup(int k) {
    if (first == nullptr) {
        return false;
    }
    
    Node * curr = this->first;
    // 1, 2, 3, 4, 1, 2, 5
    // ^           ^
    while (curr->next != nullptr) {
        Node * subcurr = curr->next;

        while (subcurr != nullptr) {
            Node * tmp1 = curr;
            Node * tmp2 = subcurr;
            int counter = k;

            while (tmp1->data == tmp2->data) {
                tmp1 = tmp1->next;
                tmp2 = tmp2->next;
                counter--;
            }
            if (counter == 0) {
                return true;
            }

            subcurr = subcurr->next;
        }

        curr = curr->next;
    }
    return false;
}

template <class T>
std::queue<T> fillQueue(std::stack<T>& stack)
{
	std::queue<T> result;
	int counter = 1;
	std::stack<T> helperStack;

	while (!stack.empty())
	{
		helperStack.push(stack.top());
		stack.pop();
	}

	while (!helperStack.empty())
	{
		if (counter % 2 == 0)
		{
			result.push(helperStack.top());
		}
		
		stack.push(helperStack.top());
		helperStack.pop();
		counter++;
	}

	return result;
}

template <class T>
T List<T>::reduce(T (*operation)(T, T), T defaultValue) {
    Node * curr = first;
    T accum = defaultValue;
    while (curr) {
        accum = operation(accum, curr->data);
        curr = curr->next;
    }
    return accum;
}

template <class T>
void List<T>::shuffle()
{
    Node * curr = first;
    int length = 0;
    while (curr != nullptr)
    {
        length++;
        curr = curr->next;
    }
    
    curr = first;
    for (int i = 0; i < length / 2; i++)
    {
        curr = curr->next;
    }

    Node * tmp = curr->next;
    while (curr->next != nullptr) {
        curr->next = tmp->next;
        tmp->next = first;
        first = tmp;
        tmp = curr->next;
    }
}

// 4 -> 3 -> 1 -> 2 -> nullptr
//-> 4
// 3 ->

template <class T>
int sizeOfStack(std::stack<T> st) {
    int lenght = 0;    
    while (!st.empty())
    {
        lenght++;
        st.pop();
    }
    return lenght;
}

template <>
void List<std::stack<int>>::equalStacks()
{
    int listLength = 0;
    int totalElements = 0;
    Node * curr = first;
    while (curr)
    {
        listLength++;
        totalElements += sizeOfStack(curr->data);
        curr = curr->next;
    }
    int average = totalElements / listLength;
    Node * currWithMore = first;
    Node * currWithLess = first;

    std::cout << average << " " << totalElements << std::endl;

    while (currWithMore && currWithLess)
    {
        while (currWithMore->next != nullptr && sizeOfStack(currWithMore->data) <= average) {
            currWithMore = currWithMore->next;
        }
        while (currWithLess->next != nullptr && sizeOfStack(currWithLess->data) >= average) {
            currWithLess = currWithLess->next;
        }

        int sizeOfMore = sizeOfStack(currWithMore->data);
        int sizeOfLess = sizeOfStack(currWithLess->data);
        
        while (sizeOfMore > average || sizeOfLess < average)
        {
            int elem = (currWithMore->data).top();
            (currWithLess->data).push(elem);
            (currWithMore->data).pop();
            sizeOfLess++;
            sizeOfMore--;
        }
    }   
}

void printStack(std::stack<int> st) {
    while (!st.empty())
    {
        std::cout << st.top() << " ";
        st.pop();
    }
    std::cout << std::endl;
}

template <class T>
void List<T>::printForStacks(){
    Node * curr = first;
    while (curr)
    {
        printStack(curr->data);
        curr = curr->next;
    }
    
}

// зад 2.
/*
template <typename T>
void removedups(Node<T>* first)
{
    if (first == nullptr)
    {
        return;
    }
    
    Node<T>* temp;
    Node<T>* curr = first;

    while (curr->next != nullptr)
    {
        if (curr->data == curr->next->data)
        {
            temp = curr->next->next;
            delete curr->next;
            curr->next = temp;
        }
        else
        {
            curr = curr->next;   
        }
    }
}
*/

// зад 3.
/*
void mirror_helper(node_int*& node, node_int*& last)
{
    if (node == nullptr) return;
    mirror_helper(node->next, last);
    last->next = new node_int {node->value, nullptr};
    last = last->next;
}

void mirror(node_int*& node)
{
    if (node == nullptr) return;
    node_int *temp = node, *last;
    while (temp->next != nullptr) 
    {
        temp = temp->next;
    }
    last = temp;
    mirror_helper(node, last);
}
*/

int add(int a, int b) {
    return a + b;
}

int product(int a, int b) {
    return a * b;
}

int main() {
  List<int> list, list2;

  list.insetAtStart(5);
  list.insetAtStart(2);
  list.insetAtStart(1);
  list.insetAtStart(4);
  list.insetAtStart(3);
  list.insetAtStart(2);
  list.insetAtStart(1);

    std::stack<int> st1;
    std::stack<int> st2;
    std::stack<int> st3;
    std::stack<int> st4;
    List<std::stack<int>> stackList;

    st1.push(5);
    st1.push(4);
    st1.push(3);
    st1.push(2);
    st1.push(1);

    st2.push(7);
    st2.push(6);

    st3.push(11);
    st3.push(10);
    st3.push(9);
    st3.push(8);

    st4.push(12);

    stackList.insetAtStart(st4);
    stackList.insetAtStart(st3);
    stackList.insetAtStart(st2);
    stackList.insetAtStart(st1);

    stackList.printForStacks();
    stackList.equalStacks();
    stackList.printForStacks();

//     auto func = [](int a, int b){ return a + b; };
//   std::cout << list.reduce(func, 1) << std::endl;

// list.print();
// list.shuffle();
// list.print();


//   list2.insetAtStart(2);
//   list2.insetAtStart(2);
//   list2.insetAtStart(2);
//   list2.insetAtStart(2);
//   list2.print();

//   list.append(list2);
    // std::cout << list.subdup(2) << std::endl; 
//   list.print();

  return 0;
}

/*
1, 2, 3, 4, 1, 2, 5
    1 -> 2 -> 3 -> 3 -> 2 -> 1

    1 -> 2 -> 3 -> 3 -> 2 -> 1
    1 -> 2 -> 3 => 3 -> 2 -> 1
*/