using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

void dfs(vector<vector<int> > &g, vector<int> &vi, int node) {
  vi[node] = true;
  for (int i = 0; i < g[node].size(); ++i) if (!vi[g[node][i]])
    dfs(g, vi, g[node][i]);
}

int get_id(map<string, int> &cod, string &s) {
  if (cod.count(s) == 0) {
    int id = cod.size();
    cod[s] = id;
  }
  return cod[s];
}

int main() {
  int n;
  cin >> n;
  map<string, int> cod;
  vector<vector<int>> g(n);
  for (int i = 0; i < n; i++) {
    string line; cin >> line;
    int e; cin >> e;
    int v = get_id(cod, line);
    while (e-- > 0) {
      cin >> line;
      int u = get_id(cod, line);
      g[u].push_back(v);
    }
  }

  assert(cod.size() == n);

  vector<int> ans(n, 0);
  for (const auto &it : cod) {
    if (it.first.substr(it.first.find("::") + 2, it.first.size()) == "PROGRAM") {
      vector<int> vi(n, 0);
      dfs(g, vi, it.second);
      for (int i = 0; i < n; ++i)
        ans[i] = ans[i] or vi[i];
    }
  }
  cout << count(ans.begin(), ans.end(), 0) << endl;

  return 0;
}
