using namespace std;

#include <iostream>

int calc_next_day(int day, int month, int year){
  switch(month){
    case 1:
      if(year % 4 == 0){
        if(year % 100 == 0){
          if(year % 400 == 0){
            return (day + 1) % 29;
          }
          return (day + 1) % 28;
        }
        return (day + 1) % 29;
      }
      return (day + 1) % 28;
    case 0: case 2: case 4: case 6: case 7: case 9: case 11:
      return (day + 1) % 31;
    case 3: case 5: case 8: case 10:
      return (day + 1) % 30;
  }
}

int calc_next_month(int day, int month, int year){
  if(calc_next_day(day, month, year) == 0)
    return (month + 1) % 12;
  return month;
}

int calc_next_year(int day, int month, int year){
  if(month == 11 && calc_next_month(day, month, year) == 0)
    return year + 1;
  return year;
}

int main(){
  int year = 1900;
  int day_of_week = 0; // 0 is monday, 6 is sunday
  int day = 0;
  int month = 0; // 0 is jan, 11 is dec
  int count = 0;
  while(true){
    if(day == 0 && day_of_week == 6 && year >= 1901)
      count++;
    cout << year << ", " << day << ", " << month << endl;
    if(year == 2000 && day == 30 && month == 11)
      break;
    int next_day = calc_next_day(day, month, year);
    int next_month = calc_next_month(day, month, year);
    int next_year = calc_next_year(day, month, year);
    day = next_day;
    month = next_month;
    year = next_year;
    day_of_week = (day_of_week + 1) % 7;
  }
  cout << count << endl;
}

