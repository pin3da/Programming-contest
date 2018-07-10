#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {
  cerr << " " << (h);
  debug_out(t...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

int dp[212345][4];

int Go(string &n, int id, int m) {
  if (id == int(n.size()))
    return 0;

  if (dp[id][m] != -1) return dp[id][m];

  int M = m;
  m += (n[id] - '0');
  m %= 3;
  int best = Go(n, id + 1, 0) + (m == 0);
  best = max(best, Go(n, id + 1, m));
  return dp[id][M] = best;
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#define endl '\n'
#endif

  string num;
  cin >> num;

  memset(dp, -1, sizeof dp);
  cout << Go(num, 0, 0) << endl;

  return 0;
}
