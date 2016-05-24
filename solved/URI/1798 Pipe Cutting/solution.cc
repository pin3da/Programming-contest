#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

struct st {
  int len, cost;
};

int dp[2002][1001];

int go(vector<st> &a, int t, int id) {
  if (id >= a.size()) return 0;
  if (t <= 0) return 0;
  if (dp[t][id] != -1) return dp[t][id];
  int best = go(a, t, id + 1);
  if (t >= a[id].len)
    best = max(best, go(a, t - a[id].len, id) + a[id].cost);
  return dp[t][id] = best;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, t;
  while (cin >> n >> t) {
    vector<st> a(n);
    for (auto &i : a) cin >> i.len >> i.cost;
    memset(dp, -1, sizeof dp);
    cout << go(a, t, 0) << endl;
  }

  return 0;
}
