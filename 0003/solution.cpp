using namespace std;

#include <iostream>

long largest_prime_factor(long i){
  long f = 0;

  while(i % 2 == 0){
    i /= 2;
    f = 2;
  }

  for(long p = 3; i != 1; p += 2){
    while(i % p == 0){
      i /= p;
      f = p;
    }
  }

  return f;
}

int main(){
  cout << largest_prime_factor(600851475143L) << endl;
}
