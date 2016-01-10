#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

using namespace std;

int next_int() {
  string buff;
  getline(cin, buff);
  return atoi(buff.c_str());
}

int K;

const int inf = 1 << 30;

int dp[111][3][111][11];
int seen[111][3][111][11];
int timestamp = 1;

int go(vector<vector<int>> &g, int node, int col, int ch, int k) {
  if (ch >= g[node].size()) {
    if (k == 0)
      return col;
    else
      return -inf;
  }
  if (seen[node][col][ch][k] >= timestamp)
    return dp[node][col][ch][k];
  seen[node][col][ch][k] = timestamp;
  if (col == 0) { // black
    int op1 = go(g, g[node][ch], 0, 0, 0);
    if (op1 >= 0)
      op1 += go(g, node, col, ch + 1, 0);

    int op2 = go(g, g[node][ch], 1, 0, K - 1);
    if (op2 >= 0)
      op2 += go(g, node, col, ch + 1, 0);
    return dp[node][col][ch][k] = max(op1, op2);
  } else { // white
    int op1 = -inf;
    if (k > 0) {
      op1 = go(g, g[node][ch], 0, 0, 0);
      if (op1 >= 0)
        op1 += go(g, node, col, ch + 1, k - 1);
    }
    int op2 = go(g, g[node][ch], 1, 0, K);
    if (op2 >= 0)
      op2 += go(g, node, col, ch + 1, k);
    return dp[node][col][ch][k] = max(op1, op2);
  }
}

void solve() {
  int n, k, t;
  string line;
  getline(cin, line);
  stringstream vega(line);
  vega >> n >> k;
  K = k;
  vector<vector<int>> g(n);
  for (int i = 0; i < n; ++i) {
    getline(cin, line);
    stringstream ss(line);
    while (ss >> t) {
      t--;
      if (t >= 0)
        g[i].push_back(t);
    }
  }
  int op1 = go(g, 0, 0, 0, 0),
      op2 = go(g, 0, 1, 0, K);
  cout << max(op1, max(op2, 0)) << endl;
  timestamp++;
}

int main() {
  int tc = next_int();
  while (tc--) solve();
  return 0;
}
