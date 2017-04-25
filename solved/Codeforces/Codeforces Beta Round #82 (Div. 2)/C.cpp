// http://codeforces.com/contest/106/problem/C

using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

struct entry{
  int a, b, c, d;
};

int dp[1001][11];

int go(vector<entry> &a, int n, int id) {
  if (n <= 0) return 0;
  if (id >= a.size()) return 0;
  if (dp[n][id] != -1) return dp[n][id];
  int best = go(a, n, id + 1);
  int dough = a[id].c, stuffing = a[id].b, profit = a[id].d;
  while (dough <= n && stuffing <= a[id].a) {
    best = max(best, profit + go(a, n - dough, id + 1));
    stuffing += a[id].b;
    dough += a[id].c;
    profit += a[id].d;
  }
  return dp[n][id] = best;
}

void solve(int n, int m, int c0, int d0) {
  vector<entry> a(m);
  for (auto &i : a)
    cin >> i.a >> i.b >> i.c >> i.d;
  entry add;
  add.a = add.b = 0;
  add.c = c0; add.d = d0;
  a.push_back(add);
  memset(dp, -1, sizeof dp);
  cout << go(a, n, 0) << endl;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, m, c, d;
  while (cin >> n >> m >> c >> d) {
    solve(n, m, c, d);
  }
  return 0;
}
