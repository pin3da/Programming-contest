#include<bits/stdc++.h>

#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

const int MN = 1001;
const double inf = 1e18;
const double pi = acos(-1);


const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS){
    return( x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

struct pank {
  long long r, h;
  long long side;
  pank() {}
  pank(int a, int b) : r(a), h(b) {
    side = h * r;
  }
  bool operator < (const pank &o) const {
    if (r == o.r) return h < o.h;
    return r < o.r;
  }
};


long long dp[MN][MN];
double go(vector<pank>& all, int id, int k) {
  if (id == int(all.size())) {
    if (k) return -inf;
    return 0;
  }
  if (k == 0) return 0;
  if (dp[id][k] != -1) return dp[id][k];
  long long best = max(go(all, id + 1, k - 1) + all[id].side, go(all, id + 1, k));
  return dp[id][k] = best;
}

void solve() {
  int n, k;
  cin >> n >> k;
  vector<pank> all(n);
  for (auto &i : all) {
    cin >> i.r >> i.h;
    i.side = i.r * i.h;
  }
  sort(all.rbegin(), all.rend());
  memset(dp, -1, sizeof dp);
  double best = 0;
  for (int i = 0; i < n; ++i) {
    best = max(best,
               2.0 * pi * (go(all, i + 1, k - 1) + all[i].side) + all[i].r * all[i].r * pi);
  }
  printf("%.9lf\n", best);
}

int main() {
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case #%d: ", i + 1);
    solve();
  }
  return 0;
}
