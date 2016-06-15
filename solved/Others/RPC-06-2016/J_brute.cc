#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

const int MN = 1377;

double dp[MN][MN];
int seen[MN][MN];
int T;

double go2(vector<int> &p, int &mask, int i, int q) {
  if (i >= p.size()) {
    int t = __builtin_popcount(mask);
    return 2 * q > t;
  }

  if ((mask >> i) & 1) {
    return (go2(p, mask, i + 1, q + 1) * (p[i] / 100.0) )
      + (go2(p, mask, i + 1, q) * ((100.0 - p[i])/ 100.0));
  } else {
    return go2(p, mask, i + 1, q);
  }
}


int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  int n;
  cout << fixed << setprecision(5);
  while (cin >> n) {
    int c, best = 0;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
      cin >> c;
      best = max(best, c);
      p[i] = c;
    }

    double ans2 = 0;
    int mask2 = 0;
    vector<double> t(n + 1);
    for (int i = 0; i < (1 << n); ++i) {
      if (__builtin_popcount(i) & 1) {
        double cur = go2(p, i, 0, 0);
        if (cur > ans2) {
          ans2 = cur;
          mask2 = i;
        }
        int ss = __builtin_popcount(i);
        t[ss] = max(t[ss], cur);
      }
    }

    for (int i = 1; i <= n; i += 2)
      cout << t[i] << endl;
    cout << ans2 << " " << mask2 << endl;
  }
  return 0;
}
// 0.968576
