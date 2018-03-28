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

typedef vector<vector<int>> mat;

void cp(mat &all, mat &temp, int x, int y) {
  int len = temp.size();
  for (int i = 0; i < len; i++) {
    for (int j = 0; j < len; j++) {
      all[x + i][y + j] = temp[i][j];
    }
  }
}

void fill(mat &all, int val) {
  for (auto &it : all)
    for (auto &cur : it) cur = val;
}

int compute(const mat &g, mat &all, int start) {
  int n = g.size(), m = g[0].size();

  int ans = start;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      ans += ((g[i][j] == 1) && (all[i][j] == 0));
    }
  }
  return ans;
}

void dbg(mat a) {
  for (auto it : a) {
    for (auto i : it)
      cerr << i << " ";
    cerr << endl;
  }
  cerr << endl;
}

void solve() {
  int n, m, k;
  read(n, m, k);
  mat g(n, vector<int>(m));
  read(g);
  mat base(k, vector<int>(k, 0));
  mat all(n, vector<int>(m));
  int start = 0;
  for (auto row : g) for (auto cell : row) start += (cell == 0);
  int best = start;
  for (int i = 0; i + k <= n; i++) {
    for (int j = 0; j + k <= m; j++) {
      for (int x = 0; x + k <= n; x++) {
        for (int y = 0; y + k <= m; y++) {
          fill(all, 1);
          cp(all, base, i, j);
          cp(all, base, x, y);
          best = max(best, compute(g, all, start));
        }
      }
    }
  }
  cout << best << endl;
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

