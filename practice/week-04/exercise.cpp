#include <iostream>
#include <queue>
#include <stack>

void printQueue(std::queue<int>& q) {
  for (int i = 0; i < q.size(); i++) {
    int elem = q.front();
    std::cout << elem << " ";
    q.push(elem);
    q.pop();
  }
}

int minElem(std::queue<int>& q) {
  int min = q.front();
    for (int i = 0; i < q.size(); i++) {
        
        int elem = q.front();
        if(min > q.front())
        {
            min = q.front();
        }
        q.push(elem);
        q.pop();
    }
    return min;
}

void filterOdd(std::queue<int>& q) {
  int size = q.size();
  for (int i = 0; i < size; i++) {
    int elem = q.front();
    if (elem % 2 == 0) {
      q.push(elem);
    }
    q.pop();
  }
  // TO DO
}

std::queue<int>& mergeSorted(std::queue<int>& q1, std::queue<int>& q2)
{
	int steps = q1.size() + q2.size();
	std::queue<int>* result = new std::queue<int>();
	
	for (int i = 0; i < steps; i++)
	{
		if (q1.empty() || q2.empty())
		{
      if (!q2.empty()) {
			  result->push(q2.front());
			  q2.pop();
      }

      if (!q1.empty()) {
			  result->push(q1.front());
			  q1.pop();
      }
		}

		if (q1.front() < q2.front())
		{
			result->push(q1.front());
			q1.pop();
		}
		else
		{
			result->push(q2.front());
			q2.pop();
		}
	}

	return *result;
}


std::queue<int>& mergeSorted2(std::queue<int>& q1, std::queue<int>& q2)
{
	std::queue<int>* result = new std::queue<int>();

  while (!q1.empty() && !q2.empty()) {
		if (q1.front() < q2.front())
		{
			result->push(q1.front());
			q1.pop();
		}
		else
		{
			result->push(q2.front());
			q2.pop();
		}
  }

  while (!q1.empty()) {
			result->push(q1.front());
			q1.pop();
  }

  while (!q2.empty()) {
			result->push(q2.front());
			q2.pop();
  }
	return *result;
}

void reverse(std::queue<int>& q) {
  std::stack<int> st;
  while (!q.empty()) {
      st.push(q.front());
      q.pop();
  }

  while (!st.empty()) {
    q.push(st.top());
    st.pop();
  }
}

int sequenceNth(int num, int n) {
    // 4 8 9.....

    std::queue<int> q;
    q.push(num);

    while (--n) {
        // if(!--n) {
        //     return q.front() + 1;
        // }
        q.push(q.front()+1);
        q.push(q.front()*2);
        q.pop();
    }

    return q.front();    
}

int binaryNumbers(int n) {
  /*
  // "0"
  // "1"
  "1" + "0" = "10"
  "1" + "1" = "11"
  "11" + "0" = "110"
  "11" + "1" = "111"
  */

  std::string str1, str2;
  std::string str3 = str1 + str2;
  // TO DO
  return 0;
}

class Queue
{
  private:
    std::stack<int> stack1; // nullprt -> 1 -> 2 -> 3
    std::stack<int> stack2; // 3 -> 2 -> 1
  public:
    void pop();
    void push(int a);
    int front();
};


int main() {
  std::queue<int> q;
  q.push(1);
  q.push(2);
  q.push(4);
  q.push(4);
  q.push(11);

  printQueue(q);
  std::cout << std::endl << minElem(q) << std::endl;
  std::cout << std::endl;
  // filterOdd(q);
  // printQueue(q);
  std::cout << std::endl;

  std::queue<int> q2;
  q2.push(1);
  q2.push(2);
  q2.push(3);
  q2.push(4);
  q2.push(5);

  std::queue<int> merge_result = mergeSorted2(q, q2);
  printQueue(merge_result);
  std::cout << std::endl;

  reverse(merge_result);
  printQueue(merge_result);

  return 0;
}

/*
  top
  pop
  push

  |5| -> |4| -> |3| -> |2| -> |1|
   ^       ^
  back     front


  |11| -> |10| -> |4| -> |4| -> |3|
   ^                              ^
  back                            front

  |3| -> |3| -> |2| -> |1|

  1 2 3 3
        ^ top

  O(n) + O(n.log n) = O(n.log n)
*/