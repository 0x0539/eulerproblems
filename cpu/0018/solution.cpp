// finally! a DP problem

using namespace std;

#include <iostream>
#include <vector>

int main(){

  int mem[15][15] = {
    {75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //0
    {95,64, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //1
    {17,47,82, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //2
    {18,35,87,10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //3
    {20, 4,82,47,65, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //4
    {19, 1,23,75, 3,34, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //5
    {88, 2,77,73, 7,63,67, 0, 0, 0, 0, 0, 0, 0, 0}, //6
    {99,65, 4,28, 6,16,70,92, 0, 0, 0, 0, 0, 0, 0}, //7
    {41,41,26,56,83,40,80,70,33, 0, 0, 0, 0, 0, 0}, //8
    {41,48,72,33,47,32,37,16,94,29, 0, 0, 0, 0, 0}, //9
    {53,71,44,65,25,43,91,52,97,51,14, 0, 0, 0, 0}, //10
    {70,11,33,28,77,73,17,78,39,68,17,57, 0, 0, 0}, //11
    {91,71,52,38,17,14,91,43,58,50,27,29,48, 0, 0}, //12
    {63,66, 4,68,89,53,67,30,73,16,69,87,40,31, 0}, //13
    { 4,62,98,27,23, 9,70,98,73,93,38,53,60, 4,23}  //14
  };

  for(int i = 13; i >= 0; i--){
    for(int j = i; j >= 0; j--){
      int v = mem[i][j],
          l = mem[i+1][j],
          r = mem[i+1][j+1];
      mem[i][j] = v + (l > r ? l : r);
      cout << v << " + max(" << l << ", " << r << ") = " << mem[i][j] << endl;
    }
  }

  cout << mem[0][0] << endl;

}
