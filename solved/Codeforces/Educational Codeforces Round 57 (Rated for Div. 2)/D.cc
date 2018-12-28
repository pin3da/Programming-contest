#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {
  cerr << " " << (h);
  debug_out(t...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

const long long inf = 998244353LL * 100001LL + 10LL;

string T = "hard";

const long long MN = 100005;
long long dp[MN][5];

long long go(string &line, vector<int> &a, int id, int h) {
  assert(h < 4);
  if (id >= int(line.size())) {
    return 0;
  }
  if (dp[id][h] != -1) {
    return dp[id][h];
  }

  long long ans = inf;
  if (line[id] != T[h]) { // no need to remove
    ans = go(line, a, id + 1, h);
  } else {
    ans = go(line, a, id + 1, h) + a[id]; // reset
    if (h < 3) {
      ans = min(ans, go(line, a, id + 1, h + 1));
    }
  }
  return dp[id][h] = ans;
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#define endl '\n'
#endif
  int n;
  cin >> n;
  string line;
  cin >> line;
  vector<int> a(n);
  for (auto &it : a) cin >> it;
  memset(dp, -1, sizeof dp);
  cout << go(line, a, 0, 0) << endl;
  return 0;
}
