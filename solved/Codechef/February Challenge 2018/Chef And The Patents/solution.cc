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
  int n, m, x, k;
  read(n, m, x, k);
  string line; cin >> line;

  vector<int> workers(2);
  for (auto it : line) workers[it == 'E']++;

  for (int i = 0; i < m && n > 0; i++) {
    int cur = min(x, workers[i & 1]);
    n -= cur;
    workers[i & 1] -= cur;
  }
  puts(n <= 0 ? "yes" : "no");
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  int tc; cin >> tc;
  while (tc--)
    solve();
  return 0;
}
