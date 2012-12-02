using namespace std;

#include <iostream>

int main(){
  int i = 1, j = 1, k = 0, sum = 0;
  while(j < 4000000){
    if(j % 2 == 0)
      sum += j;
    k = i + j;
    i = j;
    j = k;
  }
  std::cout << sum << std::endl;
}
