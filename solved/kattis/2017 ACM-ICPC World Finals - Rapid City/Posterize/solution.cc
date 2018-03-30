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

struct pixel {
  long long val, frec;
  pixel () {}
  void read() {
    cin >> val >> frec;
  }
  bool operator < (const pixel &o) const {
    return val < o.val;
  }
};

const long long inf = numeric_limits<long long>::max() / 2;

long long memo[260][260];
long long cost(vector<pixel> &all, int b, int e) {

  if (memo[b][e] == -1) {
    long long total = 0, frec = 0;
    for (int i = b; i <= e; i++) {
      total += all[i].val * all[i].frec;
      frec += all[i].frec;
    }

    long long center = total / frec;
    long long cost = inf;
    for (int delta = -1; delta < 2; delta++) {
      long long v = center + delta;

      long long cur = 0;
      for (int i = b; i <= e; i++) {
        cur += (all[i].val - v) * (all[i].val - v) * all[i].frec;
      }
      cost = min(cost, cur);
    }
    memo[b][e] = cost;
  }

  return memo[b][e];
}

void solve() {
  int n, K;
  cin >> n >> K;
  vector<pixel> all(n);
  for (auto &it : all) it.read();
  sort(all.begin(), all.end());

  memset(memo, -1, sizeof memo);

  vector<vector<long long>> dp(n + 1, vector<long long> (K + 1));

  for (int i = 0; i < n; i++)
    dp[i][0] = inf;

  for (int i = n - 1; i >= 0; i--) {
    for (int k = 1; k <= K; k++) {
      dp[i][k] = inf;
      for (int j = i; j < n; j++) {
        if (dp[j + 1][k - 1] != inf) {
          dp[i][k] = min(dp[i][k], cost(all, i, j) + dp[j + 1][k - 1]);
        }
      }
    }
  }

  cout << dp[0][K] << endl;
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

