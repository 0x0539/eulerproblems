using namespace std;

#include <iostream>

int main(){
  for(int a = 0; a <= 1000; a++){
    for(int b = a; b <= 1000 - a; b++){
      int c = 1000 - a - b;
      if(a*a + b*b == c*c){
        cout << a*b*c << endl;
      }
    }
  }
}
