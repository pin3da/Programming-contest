// http://codeforces.com/contest/408/problem/A

#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n) {
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    long long best = 1LL << 40;
    for (auto &i : a) {
      long long cur = 15 * i;
      int tp;
      for (int j = 0; j < i; ++j) {
        cin >> tp;
        cur += tp * 5;
      }
      best = min(best, cur);
    }
    cout << best << endl;
  }

  return 0;
}
