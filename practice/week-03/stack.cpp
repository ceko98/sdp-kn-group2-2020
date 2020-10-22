#include <iostream>
#include <stack>

void printStack(std::stack<int> &s) {
  while (!s.empty()) {
    std::cout << s.top() << " ";
    s.pop();
  }
}

int main() {

  std::stack<int> s;

  s.push(1);  // |4|
  s.push(2);  // |3| 
  s.push(3);  // |2|
  s.push(4);  // |1|
  
  std::cout << s.top() << std::endl;  // 4
  s.pop();
  // std::cout << s.top() << std::endl;  // 3

  printStack(s);
  return 0;
}