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

int nxt[MN][30];

void solve() {
  string line; cin >> line;

  for (int j = 0; j < 30; j++)
    nxt[line.size()][j] = line.size();

  for (int i = line.size() - 1; i >= 0; i--) {
    for (int j = 0; j < 30; j++) {
      nxt[i][j] = nxt[i + 1][j];
    }
    nxt[i][line[i] - 'a'] = i;
  }

  string ans = line;

  int pos = 0;
  int ok = true;
  for (int i = 0; i < 26; i++) {
    int b = nxt[pos][i];
    for (int j = 0; j <= i; j++)
      b = min(b, nxt[pos][j]);

    if (b == int(line.size())) {
      ok = false;
      break;
    } else {
      ans[b] = char('a' + i);
      pos = b + 1;
    }
  }

  if (ok)
    cout << ans << endl;
  else
    cout << -1 << endl;
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

