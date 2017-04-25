// http://codeforces.com/contest/631/problem/A

#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n) {
    vector<long long> a(n), b(n);
    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;
    long long best = 0;
    for (int i = 0; i < n; ++i) {
      long long xa = 0, xb = 0;
      for (int j = i; j < n; ++j) {
        xa |= a[j];
        xb |= b[j];
        best = max(best, xa + xb);
      }
    }
    cout << best << endl;
  }
  return 0;
}
