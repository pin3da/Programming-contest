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

const int MN = 1e5 + 100;

int cost[MN];
int p[MN];

int fs(int x) {
  return p[x] == x ? x : p[x] = fs(p[x]);
}

void join(int x, int y) {
  int px = fs(x), py = fs(y);
  cost[px] = min(cost[px], cost[py]);
  p[py] = px;
}

void solve() {
  int n, k, m;
  read(n, k, m);
  map<string, int> inv;
  vector<string> cad(n);

  for (int i = 0; i < n; i++) p[i] = i;

  read(cad);
  for (int i = 0; i < n; i++) {
    inv[cad[i]] = i;
  }

  for (int i = 0; i < n; i++) {
    cin >> cost[i];
  }

  for (int i = 0; i < k; i++) {
    int len; cin >> len;
    vector<int> same(len);
    read(same);
    for (int j = 1; j < len; j++) {
      join(same[j - 1] - 1, same[j] - 1);
    }
  }

  vector<string> message(m);
  read(message);

  long long ans = 0;
  for (int i = 0; i < m; i++) {
    int cur = fs(inv[message[i]]);
    ans += cost[cur];
  }
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

