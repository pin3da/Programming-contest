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

const long long inf = numeric_limits<long long>::max();

struct edge {
  int u, v;
  long long w;
  edge(int a, int b, long long c) : u(a), v(b), w(c) {}
  bool operator < (const edge &o) const {
    return w < o.w;
  }
};

const int MN = 1e6;

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

dsu dset;

void solve() {
  int n; cin >> n;

  vector<pair<long long, char>> a(n);
  for (auto &it : a)
    cin >> it.first >> it.second;

  vector<vector<int>> next_city(n + 10, vector<int>(3, n + 10));
  // RBP
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < 3; j++)
      next_city[i][j] = next_city[i + 1][j];
    if (a[i].second == 'R') next_city[i][0] = i;
    if (a[i].second == 'B') next_city[i][1] = i;
    if (a[i].second == 'P') next_city[i][2] = i;
  }

  vector<vector<int>> prev_city(n, vector<int>(3, -1));
  // RBP
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < 3; j++)
      prev_city[i][j] = prev_city[i - 1][j];
    if (a[i].second == 'R') prev_city[i][0] = i;
    if (a[i].second == 'B') prev_city[i][1] = i;
    if (a[i].second == 'P') prev_city[i][2] = i;
  }

  long long cost = 0;
  vector<edge> all;
  for (int i = 0; i < n; i++) {
    if (a[i].second == 'P') {
      int nxt = next_city[i + 1][2];
      if (nxt < n) {
        all.emplace_back(i, nxt, a[nxt].first - a[i].first);
      }
      if (i) {
        int pre = prev_city[i - 1][2];
        if (pre >= 0) {
          all.emplace_back(i, pre, a[i].first - a[pre].first);
        }
      }
    } else {
      int idx = (a[i].second == 'R') ? 0 : 1;

      if (next_city[i + 1][idx] < n) {
        int to = next_city[i+1][idx];
        all.emplace_back(i, to, a[to].first - a[i].first);
      }
      if (next_city[i + 1][2] < n) {
        int to = next_city[i+1][2];
        all.emplace_back(i, to, a[to].first - a[i].first);
      }
      if (i && prev_city[i - 1][idx] >= 0) {
        int to = prev_city[i-1][idx];
        all.emplace_back(i, to, a[i].first - a[to].first);
      }
      if (i && prev_city[i - 1][2] >= 0) {
        int to = prev_city[i-1][2];
        all.emplace_back(i, to, a[i].first - a[to].first);
      }
    }
  }

  sort(all.begin(), all.end());
  dset.init(3 * n);

  for (auto e : all) {
    if (dset.join(e.u, e.v)) {
      cost += e.w;
    }
  }

  cout << cost << endl;
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

