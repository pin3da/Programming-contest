using namespace std;
#include <bits/stdc++.h>
#define endl '\n'

const pair<int, int> inf(1e9, 1e9);


template <class T1, class T2>
  pair<T1,T2> operator+ (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return make_pair(lhs.first + rhs.first, lhs.second + rhs.second); }

int first;

void solve(int p, int f, int q) {
  unordered_map<string, int> c;
  string line;
  for (int i = 0; i < p; ++i) {
    cin >> line;
    c[line] = i;
  }

  vector<vector<pair<int, int>>> cost(p, vector<pair<int, int>>(p, inf));
  string b;
  int c1, t1;
  for (int i = 0; i < f; ++i) {
    cin >> line >> b >> c1 >> t1;
    cost[c[line]][c[b]] = min(make_pair(c1, t1), cost[c[line]][c[b]]);
  }
  cin >> line;
  int start = c[line];
  vector<vector<pair<int, int>>> dp(p, vector<pair<int, int>>(p, inf));

  for (int j = 0; j < p; ++j) {
    dp[j][0] = cost[start][j];
  }
  dp[start][0] = make_pair(0, 0);

  for (int k = 1; k < p; ++k) {
    for (int j = 0; j < p; ++j) {
      for (int i = 0; i < p; ++i) {
        if (cost[i][j] < inf) {
          dp[j][k] = min(dp[j][k], dp[i][k - 1] + cost[i][j]);
          dp[j][k] = min(dp[j][k], dp[j][k - 1]);
        }
      }
    }
  }

  if (!first)
    cout << "." << endl;

  first = false;
  for (int i = 0; i < q; ++i) {
    cin >> line >> c1;
    c1 = min(c1, p - 2);
    if (dp[c[line]][c1] < inf)
      cout << dp[c[line]][c1].first << " " <<  dp[c[line]][c1].second << endl;
    else
      cout << "* *" << endl;
  }

}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int p, f, q;
  first = true;
  while (cin >> p >> f >> q) {
    solve(p, f, q);
  }
  return 0;
}
