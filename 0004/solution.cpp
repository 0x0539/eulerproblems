using namespace std;

#include <cmath>
#include <iostream>

int numDigits(int n){
  int digits = 0;
  while(n){ 
    n /= 10; 
    digits++; 
  }
  return digits;
}

int digitAt(int number, int index){
  while(index--) 
    number /= 10;
  return number % 10;
}

bool isPalindrome(int n){
  int digits = numDigits(n);
  for(int i = 0; i < digits/2; i++){
    int l = digitAt(n, i),
        r = digitAt(n, digits-i-1);
    if(l != r)
      return false;
  }
  return true;
}

int main(){
  int largest = 0;
  for(int i = 100; i < 1000; i++){
    for(int j = i; j < 1000; j++){
      int product = i*j;
      if(isPalindrome(product) && product > largest)
        largest = product;
    }
  }
  cout << largest << endl;
}
