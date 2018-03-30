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

const int MN = 26;

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n, m; cin >> n >> m;
  vector<vector<int>> g(MN, vector<int> (MN));

  for (int i = 0; i < n; i++) {
    char u, v;
    cin >> u >> v;
    u -= 'a'; v -= 'a';
    g[u][v] = true;
  }
  for (int i = 0; i < MN; i++)  g[i][i] = true;

  for (int k = 0; k < MN; k++)
    for (int i = 0; i < MN; i++)
      for (int j = 0; j < MN; j++)
        g[i][j] |= g[i][k] && g[k][j];

  while (m--) {
    string a, b; cin >> a >> b;
    if (a.size() != b.size()) {
      puts("no");
    } else {
      int ok = true;
      for (int i = 0; i < int(a.size()); i++) {
        if (g[a[i] - 'a'][b[i] - 'a'] == 0)
          ok = false;
      }
      puts(ok ? "yes" : "no");
    }
  }
  return 0;
}

