using namespace std;

#include <iostream>

bool isSolution(int n){
  for(int i = 2; i < 20; i++)
    if(n % i != 0)
      return false;
  return true;
}

int main(){
  int i = 20;
  while(!isSolution(i)) i+=20;
  cout << i << endl;
}
