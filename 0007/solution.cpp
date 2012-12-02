using namespace std;

#include <vector>
#include <iostream>

int main(){
  vector<int> primes;
  primes.push_back(2);
  for(int i = 3; i < 10000000; i += 2){
    bool isPrime = true;
    for(int j = 0; j < primes.size(); j++){
      if(i % primes[j] == 0)
        isPrime = false;
    }
    if(isPrime)
      primes.push_back(i);
    if(primes.size() == 10001){
      cout << primes[primes.size()-1];
      break;
    }
  }
}
