// http://codeforces.com/contest/389/problem/C

using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for (typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define For(i,n) for (int i = 0; i < (n); ++i)
#define D(x) cout<<#x " = "<<(x)<<endl
#define MN 111

int strength[MN];
int n;

int valid(int index, int q) {

  for (int i = index; i < n and i <= index + q; ++i) {
    if (strength[i] < (index + q - i - 1))
      return 0;
  }
  return 1;
}

int possible(int piles) {

  int ind = 0;
  while (ind < n and strength[ind] == 0) ind++;
  if (piles < ind) return 0;

  vector<int> tmp(piles);
  int i = 0;
  while (i < n) {
    int change = 0;
    For (k, piles) {
      if (tmp[k] <= strength[i]) {
        tmp[k]++;
        i++;
        change = 1;
        break;
      }
    }
    if (!change)
      return false;
  }

  return true;

}

int main() { ___

  cin>>n;
  For (i, n)
    cin>>strength[i];

  sort(strength, strength + n);


  For (piles, n+1)
    if (possible(piles)){
      cout<<piles<<endl;
      return 0;
    }
  return 0;
}