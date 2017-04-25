// http://codeforces.com/contest/482/problem/A

using namespace std;
#include <bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

int main() { ___

  int k, n;
  cin >> n >> k;

  int r = k + 1, l = 1;
  vector<int> t(n + 1, 0);
  while (l < r) {
    cout << l << " " << r << " ";
    t[r] = t[l] = 1;
    l++;
    r--;
  }

  for (int i = 1; i <= n; ++i)
    if (!t[i])
      cout << i << " ";

  cout << endl;


  return 0;
}