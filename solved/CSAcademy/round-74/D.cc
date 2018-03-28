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


void solve() {
  int n; cin >> n;

  vector<vector<int>> ops;
  int total = (1 << n) - 1;
  for (; total > 0; total--) {
    vector<int> cur;
    for (int i = 0; i < n; i++) {
      if ((total >> i) & 1) {
        cur.push_back(i);
      }
    }
    ops.push_back(cur);
  }
  cout << ops.size() << endl;
  for (auto it : ops) {
    cout << it.size();
    for (auto i : it) {
      cout << " " << (i + 1);
    }
    cout << endl;
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

