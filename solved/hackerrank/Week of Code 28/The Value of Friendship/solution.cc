#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

const int MN = 123456;

struct ds {
  int p[MN];
  int s[MN];
  void init(int n) {
    for (int i = 0; i < n; ++i) {
      p[i] = i;
      s[i] = 1;
    }
  }

  int fs(int x) {
    return p[x] == x ? x : p[x] = fs(p[x]);
  }

  void js(int x, int y) {
    if (fs(x) == fs(y)) return;
    s[fs(x)] += s[fs(y)];
    p[fs(y)] = fs(x);
  }

  int get_s(int x) {
    return s[fs(x)];
  }
};

ds dsu;
typedef unsigned long long ull;

ull acc[MN];

void solve() {
  int n, m;
  cin >> n >> m;
  dsu.init(n + 10);
  vector<int> edges;
  while (m--) {
    int u, v;
    cin >> u >> v;
    u--;v--;
    edges.emplace_back(u);
    dsu.js(u, v);
  }
  set<int> components;
  for (int i = 0; i < n; ++i)
    components.insert(dsu.fs(i));

  vector<int> ed_in_comp(n);
  for (int i : edges)
    ed_in_comp[dsu.fs(i)]++;

  vector<pair<int, int>> entry;
  for (int i : components)
    entry.emplace_back(dsu.get_s(i), i);

  sort(entry.rbegin(), entry.rend());

  ull ans = 0;
  ull carry = 0;
  ull extra = 0;
  for (auto cur : entry) {
    ull s = dsu.get_s(cur.second);
    int id = cur.second;
    if (s == 1) continue;
    ans += acc[s];
    ans += carry * (s - 1);
    //debug(s);
    //debug(1 + ed_in_comp[id] - s);
    //debug(ans);
    //debug(carry);
    //cout << endl;
    carry += s * (s - 1);
    extra += 1 + ed_in_comp[id] - s;
  }
  cout << ans + (carry * extra) << endl;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  for (ull i = 2; i < MN; ++i)
    acc[i] = i * (i - 1) + acc[i - 1];

  int q;
  cin >> q;
  while (q--) {
    solve();
  }
  return 0;
}
