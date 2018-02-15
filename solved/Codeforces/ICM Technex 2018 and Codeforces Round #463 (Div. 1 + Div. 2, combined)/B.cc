#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {  cerr << " " << (h);  debug_out(t...); }
void read() {}
template <typename H, typename... T> void read(H &h, T&... t) { cin >> h; read(t...) ;}

#ifndef LOCAL
#define endl '\n'
#define debug(...) //
#else
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#endif

const int MN = 1000001;

int f(int x) {
  int ans = 1;
  while (x) {
    int t = x % 10;
    if (t) ans *= t;
    x /= 10;
  }
  return ans;
}

int comp_g(vector<int> &g, int x) {
  if (x < 10) return x;
  if (g[x] != 0) return g[x];
  return g[x] = comp_g(g, f(x));
}

int frec[MN][10];

void solve() {
  vector<int> g(MN);

  for (int i = 1; i < MN; i++) {
    g[i] = comp_g(g, i);
  }

  for (int i = 1; i < MN; i++) {
    frec[i][g[i]]++;
    for (int j = 0; j < 10; j++) {
      frec[i][j] += frec[i - 1][j];
    }
  }

  int q; cin >> q;
  while (q--) {
    int l, r, k; read(l, r, k);
    cout << frec[r][k] - frec[l - 1][k] << endl;
  }
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

