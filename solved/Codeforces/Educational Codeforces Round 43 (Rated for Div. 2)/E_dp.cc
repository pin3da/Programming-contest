#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {  cerr << " " << (h);  debug_out(t...); }
void read() {}
template <typename H, typename... T> void read(H &h, T&... t) { cin >> h; read(t...) ;}
template <typename H, typename... T> void read(vector<H> &h, T&... t) { for (auto &i : h) read(i); read(t...) ;}

#ifndef LOCAL
#define endl '\n'
#define debug(...) //
#else
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#endif

const int MN = 3 * 1e5 + 100;
long long h[MN], d[MN];
int n;

long long dp[200][200][200];
long long go(int id, int a, int b) {
  if (id == n) return 0;

  if (dp[id][a][b] != -1) return dp[id][a][b];
  if (b == 0) {
    return d[id] + go(id + 1, a, b);
  }

  long long best = max(d[id] + go(id + 1, a, b), h[id] + go(id + 1, a, b - 1));

  long long cur = 2;
  for (int i = 1; i <= a; i++) {
    best = max(best, h[id] * cur + go(id + 1, a - i, b - 1));
    cur <<= 1;
  }
  return dp[id][a][b] = best;
}

void solve() {
  cin >> n;
  long long a, b;
  cin >> a >> b;
  for (int i = 0; i < n; i++) {
    cin >> h[i] >> d[i];
  }
  memset(dp, -1, sizeof dp);
  cout << go(0, a, b) << endl;
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  //int tc; cin >> tc;
  //while (tc--)
    solve();
  return 0;
}

