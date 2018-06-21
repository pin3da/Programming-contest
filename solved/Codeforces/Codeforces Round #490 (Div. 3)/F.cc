#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {  cerr << " " << (h);  debug_out(t...); }
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

int dp[501][5001];

int Go(vector<int>& c, vector<int>& f, vector<int>& h, int i, int j, const int K) {
  if ((i >= (int)f.size()) || (j >= (int) c.size()))
    return 0;

  if (dp[i][j] != -1)
    return dp[i][j];

  int curr = 0;
  int best = max(
      Go(c, f, h, i + 1, j, K),
      Go(c, f, h, i, j + 1, K)
  );
  for (int k = 0; k < K && j + k < int(c.size()); k++) {
    if (f[i] == c[j + k])
      curr++;
    best = max(best, h[curr] + Go(c, f, h, i + 1, j + k + 1, K));
  }
  return dp[i][j] = best;
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#endif

  int n, k;
  cin >> n >> k;
  vector<int> c(n * k);
  for (auto &it : c)
    cin >> it;

  vector<int> f(n);
  for (auto &it : f)
    cin >> it;

  vector<int> h(k + 1);
  for (int i = 1; i <= k; i++)
    cin >> h[i];

  sort(c.begin(), c.end());
  sort(f.begin(), f.end());

  memset(dp, -1, sizeof dp);

  cout << Go(c, f, h, 0, 0, k) << endl;


  return 0;
}

