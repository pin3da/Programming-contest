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

int color[555][555];
int can[555][555];
map<char, int> dx, dy;

bool out(vector<string> &g, int i, int j) {
  int n = g.size(), m = g[0].size();
  if (i < 0 || i >= n || j < 0 || j >= m) return true;
  if (color[i][j] == 0) {
    color[i][j] = 1;
    char s = g[i][j];
    can[i][j] = out(g, i + dx[s], j + dy[s]);
    color[i][j] = 2;
  } else if (color[i][j] == 1) {
    can[i][j] = false;
    return false; // cycle;
  }
  assert(color[i][j] == 2);
  return can[i][j];

}

void solve() {
  dx['D'] = 1;
  dx['U'] = -1;
  dy['L'] = -1;
  dy['R'] = 1;
  int n, m; cin >> n >> m;
  vector<string> g(n);
  for (auto &it : g) cin >> it;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (out(g, i, j)) ans++;
    }
  }
  cout << ans << endl;
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

