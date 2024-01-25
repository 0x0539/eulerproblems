using namespace std;

#include <iostream>

int main(){
  int sumOfSquares = 0;
  int squareOfSum = 0;
  for(int i = 1; i <= 100; i++){
    squareOfSum += i;
    sumOfSquares += i*i;
  }
  cout << (squareOfSum * squareOfSum) - sumOfSquares << endl;
}
