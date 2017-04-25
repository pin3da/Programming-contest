// http://codeforces.com/contest/493/problem/D

using namespace std;
#include <bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

int main() { ___
  int n;
  cin >> n;
  cout << ((n & 1) ? "black" : "white\n1 2" ) << endl;
  return 0;
}