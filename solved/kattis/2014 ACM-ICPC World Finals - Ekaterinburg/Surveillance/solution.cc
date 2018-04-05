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

const int MN = 2000000 + 100;
const int ML = 21;

int nxt[MN][ML];

void solve() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i <= 2 * n; i++)
    nxt[i][0] = i;

  for (int i = 0; i < k; i++) {
    int b, e; cin >> b >> e;
    if (e < b)
      e += n;

    nxt[b][0] = max(nxt[b][0], e + 1);
  }

  for (int i = 1; i <= 2 * n; i++) {
    nxt[i][0] = max(nxt[i][0], nxt[i - 1][0]);
  }

  for (int l = 1; l < ML; l++) {
    for (int i = 0; i <= 2 * n; i++) {
      nxt[i][l] = nxt[nxt[i][l - 1]][l - 1];
    }
  }

  int ans = 3 * n;

  for (int i = 0; i <= n; i++) {
    int pos = i, cur = 0;
    if (nxt[pos][ML - 1] < (i + n)) continue;

    for (int l = ML - 1; l >= 0; l--) {
      if (nxt[pos][l] < (i + n)) {
        cur += (1LL << l);
        pos = nxt[pos][l];
      }
    }

    ans = min(ans, cur + 1);
  }

  if (ans == 3 * n) {
    cout << "impossible" << endl;
  } else {
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

