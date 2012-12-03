using namespace std;

#include <iostream>
#include <vector>

int chainLength(long n){
  if(n == 1) return 1;
  return (n%2 == 0 ? chainLength(n/2) : chainLength(3*n+1)) + 1;
}

int main(){
  long longest = 0, argLongest = -1;
  for(int i = 1000000-1; i > 1; i--){
    int chainLen = chainLength(i);
    if(chainLen > longest){
      longest = chainLen;
      argLongest = i;
    }
  }
  cout << argLongest << endl;
}
