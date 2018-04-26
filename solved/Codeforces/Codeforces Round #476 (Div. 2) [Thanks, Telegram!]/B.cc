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

void mark_h(vector<vector<char>> &g, vector<vector<int>> &t, int x, int y, int len) {
  int n = g.size();
  int mark = true;
  if (x + len > n) mark = false;

  for (int i = x; i < n && i - x < len; i++) {
    if (g[i][y] == '#') mark = false;
  }

  if (mark) {
    for (int i = x; i < n && i - x < len; i++)
      t[i][y]++;
  }
}

void mark_v(vector<vector<char>> &g, vector<vector<int>> &t, int x, int y, int len) {
  int n = g.size();
  int mark = true;

  if (y + len > n) mark = false;

  for (int i = y; i < n && i - y < len; i++) {
    if (g[x][i] == '#') mark = false;
  }

  if (mark) {
    for (int i = y; i < n && i - y < len; i++)
      t[x][i]++;
  }
}

void solve() {
  int n, k;
  cin >> n >> k;
  vector<vector<char>> g(n, vector<char>(n));
  read(g);

  vector<vector<int>> times(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      mark_h(g, times, i, j, k);
      mark_v(g, times, i, j, k);
    }
  }

  int x = 0, y = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (times[i][j] > times[x][y]) {
        x = i;
        y = j;
      }
    }
  }
  cout << (x + 1) << " " << (y + 1) << endl;
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

