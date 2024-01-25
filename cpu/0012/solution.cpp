using namespace std;

#include <iostream>
#include <vector>

int numDivisors(int t){
  int divisors = 1;

  for(int i = 2; t > 1; i++){
    int count = 0;
    while(t % i == 0){
      t /= i;
      count++;
    }
    divisors *= count + 1;
  }

  return divisors;
}

int main(){
  long t = 0, i = 1;
  while(numDivisors(t) <= 500){
    t += i;
    i++;
  }
  cout << t << endl;
}
