#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int get_id(unordered_map<string, int> &d, string c) {
  if (d.count(c) == 0) {
    int id = d.size();
    d[c] = id;
  }
  return d[c];
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, G;
  cin >> n >> G;
  vector<vector<int>> g(n + 10);
  unordered_map<string, int> dic;
  dic.reserve(n + 10);
  for (int i = 0; i < n; ++i) {
    string a, b;
    cin >> a >> b;
    int u = get_id(dic, a), v = get_id(dic, b);
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }

  vector<int> d(n + 10, -1);
  deque<int> q;
  int s = get_id(dic, "Rerisson");
  q.push_back(s);
  d[s] = 0;
  while (!q.empty()) {
    int cur = q.front(); q.pop_front();
    for (auto &to : g[cur]) {
      if (d[to] < 0) {
        d[to] = d[cur] + 1;
        q.push_back(to);
      }
    }
  }

  vector<string> ans;
  ans.reserve(n + 10);
  d[s] = G + 10;
  for (auto &p : dic) {
    if (d[p.second] <= G && d[p.second] > 0)
      ans.push_back(p.first);
  }

  sort(ans.begin(), ans.end());
  cout << ans.size() << endl;
  for (auto &p : ans) {
    cout << p << endl;
  }

  return 0;
}
