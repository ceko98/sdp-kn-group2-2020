#include <iostream>
#include <stack>

void printStack(std::stack<int> &s) {
  while (!s.empty()) {
    std::cout << s.top() << " ";
    s.pop();
  }
}

std::stack<int> copyStack(std::stack<int> &original) {
  std::stack<int> result;
  std::stack<int> helper;

  while (!original.empty()) {
    helper.push(original.top());
    original.pop();
  }

  while (!helper.empty()) {
    result.push(helper.top());
    original.push(helper.top());
    helper.pop();
  }

  return result;
}

bool correctBrackets(const char *str) {
  std::stack<char> open;

  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
      open.push(str[i]);
    } else {
      if (open.empty()) {
        return 0;
      }
      if (str[i] == ')' && open.top() != '(' ||
          str[i] == ']' && open.top() != '[' ||
          str[i] == '}' && open.top() != '{'
      ) {
        return 0;
      } else {
        open.pop();
      }
    }
  }

  return open.empty();
}

int main() {

  std::stack<int> s;

  s.push(1);  // |4|
  s.push(2);  // |3|
  s.push(3);  // |2|
  s.push(4);  // |1|
  
  // std::cout << s.top() << std::endl;  // 4
  // s.pop();

  // std::stack<int> tmp = copyStack(s);

  // printStack(tmp);
  // std::cout << std::endl;
  // printStack(s);
  char str[20] = "(([]){})";
  // correctBrackets(str);
  std::cout << correctBrackets("(([]){}))") << std::endl;

  return 0;
}