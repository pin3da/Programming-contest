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


void solve() {
  string line; cin >> line;
  vector<int> p(line.size());
  for (auto &it : p) cin >> it;

  string t = line;
  for (int i = 0; i < int(line.size()); i++) {
    t[i] = line[p[i] - 1];
  }

  int ok = true;
  for (int i = 0; i < int(t.size()) / 2; i++) {
    if (t[i] != t[t.size() - 1 - i])
      ok = false;
  }
  debug(ok);
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
//   int tc; cin >> tc;
//  while (tc--)
    solve();
  return 0;
}

