#include <iostream>

int main() {
  int prev1 = 1;
  int prev2 = 2;
  int next = prev1 + prev2;
  int sum = 2;
  while (next <= 4000000) {
    if (next % 2 == 0) {
      sum += next;
    }
    prev1 = prev2;
    prev2 = next;
    next = prev1 + prev2;
  }
  std::cout << sum << std::endl;
}
