/*
ID: aircode1
TASK: ride
LANG: C++11                 
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int convert(string str){
  int product = 1;
  for (int i = 0; i < str.size(); i++){
    product *= (int)str[i] - 64;
  }

  return product % 47;
}

int main() {
  
  ifstream fin("ride.in");
  ofstream fout("ride.out");

  string comet, group;
  fin >> comet >> group;
  
  if (convert(comet) == convert(group)){
    fout << "GO" << endl;
  }
  else {
    fout << "STAY" << endl;
  }
  
  return 0;
  
}
