using namespace std;
#include <bits/stdc++.h>
#define endl '\n'

long long dp[60][333];
long long go(int i, int rem, vector<vector<pair<int, int> > > &data) {
  if (i == data.size())
    return 0;

  if (rem == 0)
    return 0;

  if (dp[i][rem] != -1)
    return dp[i][rem];

  long long ans = 0;
  for (int j = 0; j < data[i].size(); ++j) {
    ans = max(ans, min(data[i][j].second, rem) * data[i][j].first +
                    go(i + 1, rem - min(data[i][j].second, rem), data));
  }
  return dp[i][rem] = ans;
}

void solve(int n, int w) {
  vector<vector<pair<int, int> > > data(w + 1);

  for (int i = 0; i < w + 1; ++i) {
    int t; cin >> t;
    data[i].resize(t);
    for (int j = 0; j < t; ++j)
      cin >> data[i][j].first;
    for (int j = 0; j < t; ++j)
      cin >> data[i][j].second;
  }

  memset(dp, -1, sizeof dp);

  long long best = go(0, n, data);
  long long best_w = best;

  for (int j = 0; j < data[0].size(); ++j) {
    long long tmp = min(data[0][j].second, n) * data[0][j].first + go(1, n - min(data[0][j].second, n), data);
    if (tmp == best) {
      best_w = min<long long>(best_w,  data[0][j].first);
    }
  }


  cout << best << endl << best_w << endl;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, w;
  while (cin >> n >> w) {
    solve(n, w);
  }
  return 0;
}
