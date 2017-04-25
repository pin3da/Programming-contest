// http://codeforces.com/contest/495/problem/A

using namespace std;
#include <bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false); cin.tie(NULL);
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

int main() { ___
  vector<int> val = {2, 7, 2, 3, 3, 4, 2, 5, 1, 2};
  string n;
  while (cin >> n)
    cout << val[n[0] - '0'] * val[n[1] - '0'] << endl;
  return 0;
}