// http://codeforces.com/contest/617/problem/C

#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;
long long d(long long x, long long y) {
  return x * x + y * y;
}

void solve(int n) {
  long long x1, y1, x2, y2;
  vector<long long> x(n), y(n);
  cin >> x1 >> y1 >> x2 >> y2;
  vector<long long> dt(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i];
    dt[i] = d(x[i] - x1, y[i] - y1);
  }

  dt.emplace_back(0);
  long long ans = 1LL << 60;
  for (int i = 0; i < dt.size(); ++i) {
    long long r1 = dt[i], r2 = 0;
    for (int j = 0; j < n; ++j) {
      if (d(x[j] - x1, y[j] - y1) > r1) {
        r2 = max(r2, d(x[j] - x2, y[j] - y2));
      }
    }
    ans = min(ans, r1 + r2);
  }
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  int n;
  while (cin >> n)
    solve(n);

  return 0;
}
