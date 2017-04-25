// http://codeforces.com/contest/6/problem/C

#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n;
  while (cin >> n) {
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    int i = 0, j = n - 1;
    vector<int> used(n);
    while (i < j) {
      used[i] = 1, used[j] = 2;
      int t = min(a[i], a[j]);
      a[i] -= t;
      a[j] -= t;
      if (a[i] == 0) i++;
      if (a[j] == 0) j--;
    }
    if (i == j) {
      if (used[i] <= 1) i++;
      else j--;
    }
    cout << i << ' ' << n - j - 1 << endl;
  }
  return 0;
}
