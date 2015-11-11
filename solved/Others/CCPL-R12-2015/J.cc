#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

int next_int() {
  string line;
  getline(cin, line);
  return atoi(line.c_str());
}

int dfs(vector<vector<int> > &g, vector<int> &d, int node) {
  if (d[node] != -1)
    return d[node];

  int best = 1;
  for (int i = 0; i < g[node].size(); ++i) {
    best = max(best, dfs(g, d, g[node][i]) + 1);
  }
  return d[node] = best;
}

void build(vector<vector<int> > &g, vector<int> &d, int node, vector<int> &ans) {
  for (int i = 0; i < g[node].size(); ++i) {
    if (dfs(g, d, g[node][i]) + 1 == d[node]) {
      ans.push_back(g[node][i]);
      build(g, d, g[node][i], ans);
      return;
    }
  }
}

void solve(int n) {
  vector<vector<int> > g(n);
  map<string, vector<int> > nodes;
  string line;
  for (int t = 0; t < n; ++t) {
    getline(cin, line);
    int i;
    for (i = 0; line[i] != ':'; ++i) {}
    string name = line.substr(0, i);
    // D(name);
    i++;
    stringstream ss(line.substr(i));
    while (ss >> line) {
      if (line[0] == '@') {
        if (line == name) continue;
        vector<int> &idx = nodes[line];
        for (int j = 0; j < idx.size(); ++j) {
          g[idx[j]].push_back(t);
          // cout << "\tfrom " << line << " to " << name << endl;
        }
      }
    }
    nodes[name].push_back(t);
  }

  vector<int> depth(n, -1);
  int best = 0, idx = -1;
  for (int i = 0; i < n; ++i) {
    int t = dfs(g, depth, i);
    if (best < t) {
      best = t;
      idx = i;
    }
  }

  cout << best << endl;
  cout << idx + 1;
  vector<int> ans;
  build(g, depth, idx, ans);
  for (int i = 0; i < ans.size(); ++i) {
    cout << " " << ans[i] + 1;
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  string cur;
  while (getline(cin, cur)) {
    int n = atoi(cur.c_str());
    solve(n);
  }

  return 0;
}
