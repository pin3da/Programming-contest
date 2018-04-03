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

const int MN = 1000;
struct dsu {
  int p[MN];

  void init(int n) {
    for (int i = 0; i < n; i++) {
      p[i] = i;
    }
  }

  int find(int x) {
    return x == p[x] ? x : p[x] = find(p[x]);
  }

  int join(int x, int y) {
    int px = find(x), py = find(y);
    if (px == py)
      return 0;
    p[px] = py;
    return 1;
  }
};

dsu d;

void solve() {
  long long n; cin >> n;
  /*
  d.init(n);
  vector<pair<int, pair<int, int>>> edges;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      // cout << (i ^ j) << " ";
      edges.push_back(make_pair(i ^ j, make_pair(i, j)));
    }
    // cout << endl;
  }

  sort(edges.begin(), edges.end());
  long long total = 0;
  for (auto it : edges) {
    if (d.join(it.second.first, it.second.second)) {
      total += it.first;
    }
  }
  cout << total << endl;
  */

  n--;
  long long total = 0;
  for (int i = 0; i < 63; i++) {
    long long cur = (1ll << i);
    long long f = (n - cur) / (cur << 1) + 1;
    if (cur > n) break;
    total += cur * f;
    //debug(cur, f);
  }
  cout << total << endl;
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

