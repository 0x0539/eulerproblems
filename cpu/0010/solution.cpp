using namespace std;

#include <vector>
#include <iostream>

#include "string.h"

int main(){
  vector<char> primes(2000000, 0);

  long sum = 0;

  for(long i = 2; i < 2000000; i++){
    if(primes[i] == 0){
      sum += i;
      for(long j = 2; i*j < 2000000; j++)
        primes[i*j] = 1;
    }
  }

  cout << sum << endl;
}
