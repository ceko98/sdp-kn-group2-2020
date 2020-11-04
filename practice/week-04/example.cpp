#include <iostream>
#include <stack>

using namespace std;

bool isOper(char c) {
  return c == '+' || c == '-' || c == '*' || c == '/';
}

int apply(char op, int left, int right) {
  switch (op)
  {
  case '+': return left + right;
  case '*': return left * right;
  case '-': return left - right;
  case '/': return left / right;
  default: return 0;
  }
}

int main() {
  std::stack<char> s_op;
  std::stack<int> s_num;

  const char * exp = "++47+1**231";   //+(11)+1*61
  int oprandsCount = 0;

  for (int i = 0; exp[i] != '\0'; i++)
  {
    std::cout << exp[i] << " ";
    if (isOper(exp[i])) {
      s_op.push(exp[i]);
      oprandsCount = 0;
    } else {
      s_num.push(exp[i] - '0');
      oprandsCount++;
    }

    if (oprandsCount == 2) {
      int left = s_num.top();
      s_num.pop();
      int right = s_num.top();
      s_num.pop();
      char oper = s_op.top();
      s_op.pop();
      int newVal = apply(oper, left, right);
      cout << endl << newVal << endl;
      s_num.push(newVal);
      oprandsCount = 0;
    }
  }

  while(!s_op.empty()) {
    int left = s_num.top();
    s_num.pop();
    int right = s_num.top();
    s_num.pop();
    char oper = s_op.top();
    s_op.pop();
    int newVal = apply(oper, left, right);
    s_num.push(newVal);
  }

  std::cout << std::endl << s_num.top(); 

  return 0;
}