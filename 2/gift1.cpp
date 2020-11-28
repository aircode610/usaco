/*
ID: aircode1
TASK: gift1
LANG: C++11                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main() {
  
  ifstream fin("gift1.in");
  ofstream fout("gift1.out");

  int NP;
  fin >> NP;

  map<string, int> accounts;
  string list[NP];

  for (int i = 0; i < NP; i++){
    string name;
    fin >> name;

    accounts[name] = 0;
    list[i] = name;
  }

  for (int i = 1; i <= NP + 1; i++){
    string gifter;
    fin >> gifter;
    
    int amount, num;
    fin >> amount >> num;

    if (amount == 0 || num == 0){
      continue;
    }
    
    accounts[gifter] -= amount - amount % num;
    
    for (int j = 1; j <= num; j++){
      string rec;
      fin >> rec;

      accounts[rec] += amount / num;
    }
    
  }

  for (int i = 0; i < NP; i++){
    string name = list[i];
    fout << name << " " << accounts[name] << endl;
  } 
  
  return 0;
  
}
