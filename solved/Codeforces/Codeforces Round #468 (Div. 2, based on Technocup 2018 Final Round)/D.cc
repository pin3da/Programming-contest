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

typedef vector<vector<int>> graph;

void solve() {
  int n; cin >> n;
  graph g(n);
  for (int i = 1; i < n; i++) {
    int p; cin >> p;
    g[p - 1].push_back(i);
  }

  vector<int> dist(n, 1000000);

  dist[0] = 0;
  deque<int> q;
  q.push_back(0);
  while (!q.empty()) {
    int cur = q.front(); q.pop_front();
    for (auto to : g[cur]) {
      dist[to] = dist[cur] + 1;
      q.push_back(to);
    }
  }

  vector<int> frec(n);
  for (auto d : dist)
    frec[d]++;

  int ans = 0;
  for (auto f : frec)
    ans += f & 1;

  cout << ans << endl;
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

