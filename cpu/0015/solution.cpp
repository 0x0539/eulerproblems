using namespace std;

#include <iostream>
#include <vector>

// we assume 2 sets of size l, though the concept can be generalized
long multisetPermutations(long l){
  vector<int> numeratorTerms;
  vector<int> denominatorTerms;

  long numerator = l+l;

  for(int i = 2; i <= numerator; i++){
    numeratorTerms.push_back(i);
  }
  for(int i = 2; i <= l; i++){
    denominatorTerms.push_back(i);
    denominatorTerms.push_back(i);
  }

  bool worked = false;

  // this loop cancels out terms in the permutation fraction, probably suboptimally
  do{
    worked = false;
    for(int i = numeratorTerms.size() - 1; i >= 0; i--){
      for(int j = denominatorTerms.size() - 1; j >= 0; j--){
        int n = numeratorTerms[i], d = denominatorTerms[j];
        if(n % d == 0 && d > 1){
          numeratorTerms[i] /= d;
          denominatorTerms[j] = 1;
          worked = true;
        }
      }
    }
  }while(worked);
  
  long n = 1, d = 1;

  for(int i = 0; i < numeratorTerms.size(); i++)
    n *= numeratorTerms[i];

  for(int i = 0; i < denominatorTerms.size(); i++)
    d *= denominatorTerms[i];

  cout << n << ", " << d << endl;

  return n / d;
}

int main(){
  cout << multisetPermutations(20) << endl;
}
