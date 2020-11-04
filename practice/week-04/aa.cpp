#include <iostream>

using namespace std;

int main() {
  int a = 11;

  for (int i = 31; i >= 0; i--) {
    cout << (a >> i) & 1;
  }

  return 0;
}