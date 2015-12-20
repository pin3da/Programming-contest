using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

int N;
const int inf = (1 << 30);

const int MN = 5001;
int dp[MN][MN];
int seen[MN][MN];

int ti;
int go(vector<int> &p, int n, int acc) {
  if (n == 0) return 0;
  if (seen[n][acc] == ti) return dp[n][acc];
  seen[n][acc] = ti;

  int best = -inf;
  for (int i = 0; i < p.size(); ++i) {
    if (n - acc - p[i] >= 0)
      best = max(best, go(p, n - acc - p[i], acc + p[i]) + p[i]);
  }
  return  dp[n][acc] = best;
}

void solve() {
  cin >> N;
  int m; cin >> m;
  vector<int> p(m);
  for (auto &i : p) cin >> i;
  int ans = go(p, N, 0);
  if (ans < 0)
    cout << -1 << endl;
  else
    cout << ans << endl;
  ti++;
}

int main() {
  int n;
  ti = 1;
  while (cin >> n) {
    for (int i = 0; i < n; ++i)
      solve();
  }
  return 0;
}
