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

const int MN = 100000 + 100;

int frec[MN][33];

void solve() {
  int n, q;
  read(n, q);

  for (int i = 1; i <= n; i++) {
    int t; cin >> t;
    for (int j = 0; j <= 30; j++) {
      frec[i][j] = frec[i - 1][j];
      if ((t >> j) & 1)
        frec[i][j]++;
    }
  }

  while (q--) {
    int l, r;
    read(l, r);
    int ans = 0;
    for (int i = 30; i >= 0; i--) {
      int ones = frec[r][i] - frec[l - 1][i];
      int zeros = (r - l + 1) - ones;
      if (zeros > ones) {
        ans |= (1 << i);
      }
    }
    cout << ans << endl;
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

