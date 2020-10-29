#include <iostream>
#include <queue>

void printQueue(std::queue<int>& q) {
  for (int i = 0; i < q.size(); i++) {
    int elem = q.front();
    std::cout << elem << " ";
    q.push(elem);
    q.pop();
  }
}

int main() {
  
  std::queue<int> q;
  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);
  q.push(5);

  printQueue(q);

  return 0;
}

/*
  top
  pop
  push

  |5| -> |4| -> |3| -> |2| -> |1|
   ^                           ^
  back                        front
*/