/*
ID: aircode1
TASK: friday
LANG: C++11                 
*/
#include <bits/stdc++.h>

using namespace std;

int fridays[7];

int main() {
  ifstream fin("friday.in");
  ofstream fout("friday.out");
  int N; fin >> N;
  int day = 15;
  fridays[day%7]++;
  for (int year = 1900; year <= 1900+N-1; year++){
    bool isLeap = false;
    if (year % 100 == 0 && year % 400 == 0)
      isLeap = true;
    else if (year % 100 != 0 && year % 4 == 0)
      isLeap = true;
    else
      isLeap = false;
    for (int month = 1; month <= 12; month++){
      int days = 0;
      if (month == 2 && isLeap == true)
	days = 29;
      else if (month == 2 && isLeap == false)
	days = 28;
      else if (month == 9 || month == 4 || month == 6 || month == 11)
	days = 30;
      else
	days = 31;
      day = (days-13) + 13 + day;
      fridays[day%7]++;
    }
  }
  fridays[day%7]--;
  for (int i = 1; i < 7; i++){
    fout << fridays[i] << " ";
  }
  fout << fridays[0] << endl;
}
