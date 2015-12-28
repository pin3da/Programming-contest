using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

struct entry{
  int p, w;
};

const int MN = 1000 + 10;
int dp[MN][33];

int go(vector<entry> &a, int i, int w) {
  if (i == a.size() || w <= 0) return 0;
  int best = 0;
  if (dp[i][w] != -1) return dp[i][w];
  if (a[i].w <= w) best = a[i].p + go(a, i + 1, w - a[i].w);
  return dp[i][w] = max(best, go(a, i + 1, w));
}

void solve() {
  int n;
  cin >> n;
  vector<entry> a(n);
  for (auto &i : a) cin >> i.p >> i.w;
  int g; cin >> g;
  vector<int> p(g);
  long long ans = 0;
  memset(dp, -1, sizeof dp);
  for (auto &i : p) {
    cin >> i;
    ans += go(a, 0, i);
  }
  cout << ans << endl;
}


int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  cin >> n;
  while (n--) solve();
  return 0;
}
