/*
ID: aircode1
TASK: beads
LANG: C++11                 
*/
#include <bits/stdc++.h>

using namespace std;

int main() {

  ifstream fin("beads.in");
  ofstream fout("beads.out");
  
  int N; fin >> N;
  string necklace; fin >> necklace;
  necklace += necklace;
  int ans = 0;
  
  for (int i = 0; i < N*2; i++){
    char left=' ',right=' ';
    int lc=i-1, rc=i;
    int count = 0;
    while (lc > 0){
      if (left != ' ' && (necklace[lc] != left && necklace[lc] != 'w'))
	break;
      if (necklace[lc] != 'w')
	left = necklace[lc];
      count++;
      lc--;
    }
    while (rc < N*2){
      if (right != ' ' && (necklace[rc] != right && necklace[rc] != 'w'))
	break;
      if (necklace[rc] != 'w')
	right = necklace[rc];
      count++;
      rc++;
    }

    if (count > ans){
      ans = count;
    }
  }

  if (ans > N)
    ans = N;
  
  fout << ans << endl;
  
  return 0;
}
