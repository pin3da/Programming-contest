#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

bool check_row(vector<char> &l) {
  int n = l.size();
  for (int i = 0; i < n; i++) {
    if (l[i] != l[0]) return false;
  }
  return true;
}

bool check_1(vector<vector<char>> &g, int n, int m) {
  if (n % 3) return false;
  int len = n / 3;
  set<char> seen;
  int ok = true;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < len; j++) {
      ok &= check_row(g[i * len + j]);
      if (j) {
        ok &= g[i * len + j - 1][0] == g[i * len + j][0];
      }
    }
    seen.insert(g[i * len][0]);
  }
  return ok && seen.size() == 3;
}

bool check_col(vector<vector<char>> &g, int n, int m, int col) {
  for (int i = 0; i < n; i++) {
    if (g[i][col] != g[0][col]) return false;
  }
  return true;
}

bool check_2(vector<vector<char>> &g, int n, int m) {
  if (m % 3) return false;
  int len = m / 3;
  set<char> seen;
  int ok = true;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < len; j++) {
      ok &= check_col(g, n, m, i * len + j);
      if (j) {
        ok &= g[0][i * len + j - 1] == g[0][i * len + j];
      }
    }
    seen.insert(g[0][i * len]);
  }
  return ok && seen.size() == 3;
}



int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n, m;
  cin >> n >> m;
  vector<vector<char>> g(n, vector<char> (m));
  for (auto &i : g) for (auto &j : i) cin >> j;

  int ok = check_1(g, n, m) || check_2(g, n, m);
  puts(ok ? "YES" : "NO");
  return 0;
}
