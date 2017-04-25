// http://codeforces.com/contest/41/problem/B

#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

void solve(int n, int m) {
  vector<int> a(n);

  for (auto &i : a) cin >> i;

  int best = m;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      best = max(best, (m / a[i]) * a[j] + (m % a[i]));
    }
  }
  cout << best << endl;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, m; while (cin >> n >> m) solve(n, m);
  return 0;
}
