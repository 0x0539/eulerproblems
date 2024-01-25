using namespace std;

#include <iostream>
#include <string>

string countChars(int i){
  if(i == 1000){
    return "onethousand";
  }
  else if(i >= 100){
    string s = countChars(i / 100) + "hundred";
    if(i % 100) s += "and" + countChars(i % 100);
    return s;
  }
  else if(i >= 90){
    return "ninety" + countChars(i % 10);
  }
  else if(i >= 80){
    return "eighty" + countChars(i % 10);
  }
  else if(i >= 70){
    return "seventy" + countChars(i % 10);
  }
  else if(i >= 60){
    return "sixty" + countChars(i % 10);
  }
  else if(i >= 50){
    return "fifty" + countChars(i % 10);
  }
  else if(i >= 40){
    return "forty" + countChars(i % 10);
  }
  else if(i >= 30){
    return "thirty" + countChars(i % 10);
  }
  else if(i >= 20){
    return "twenty" + countChars(i % 10);
  }
  else{
    switch(i){
      case 1: return "one";
      case 2: return "two";
      case 3: return "three";
      case 4: return "four";
      case 5: return "five";
      case 6: return "six";
      case 7: return "seven";
      case 8: return "eight";
      case 9: return "nine";
      case 10: return "ten";
      case 11: return "eleven";
      case 12: return "twelve";
      case 13: return "thirteen";
      case 14: return "fourteen";
      case 15: return "fifteen";
      case 16: return "sixteen";
      case 17: return "seventeen";
      case 18: return "eighteen";
      case 19: return "nineteen";
    }
  }
  return "";
}

int main(){
  string a = "";
  for(int i = 1; i <= 1000; i++)
    a += countChars(i);
  //cout << a << endl;
  cout << a.size() << endl;
}
