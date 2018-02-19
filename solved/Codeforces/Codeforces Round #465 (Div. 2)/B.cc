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

int T;

int side(int x, int y) {
  if (x == y) return 0;
  if (x < y) return 1;
  if (y < x) return 2;
  return 3;
}

int sim(string m, int s) {
  vector<int> x(m.size() + 1), y(m.size() + 1);
  T = s;

  int id = 0;
  int ans = 0;
  for (auto c : m) {
    int nx = x[id], ny = y[id];
    if (c == 'U') {
      ny++;
    } else {
      nx++;
    }
    x[id + 1] = nx;
    y[id + 1] = ny;
    if (id > 0 && side(x[id], y[id]) == 0) {
      if (side(x[id - 1], y[id - 1]) != side(x[id + 1], y[id + 1]))
        ans++;
    }
    id++;
  }
  return ans;
}

void solve() {
  int n; cin >> n;
  string m; cin >> m;
  cout << sim(m, 1) << endl;
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

