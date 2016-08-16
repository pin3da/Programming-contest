#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int get_id(map<string, int> &m, string &s) {
  if (m.count(s)) return m[s];
  int ans = m.size();
  return m[s] = ans;
}

int nxint () {
  string b; getline(cin, b);
  return atoi(b.c_str());
}

const int MN = 1100;

void solve() {
  int n = nxint();
  map<string, int> id;
  vector<vector<int> > g(MN);
  vector<int> inc(MN);
  vector<int> vi(MN);

  for (int i = 0; i < n; ++i) {
    string line;
    getline(cin, line);
    stringstream ss(line);
    string ant;
    while (getline(ss, line, ',')) {
      if (ant.size()) {
        int u = get_id(id, ant);
        int v = get_id(id, line);
        g[u].push_back(v);
        inc[v]++;
      }
      ant = line;
    }
  }

  int nodes = id.size();
  deque<int> q;
  for (int i = 0; i < nodes; ++i) {
    if (inc[i] == 0) q.push_back(i);
  }

  while (!q.empty()) {
    int cur = q.front();q.pop_front();
    vi[cur] = true;
    for (int i = 0; i < g[cur].size(); ++i) {
      int to = g[cur][i];
      inc[to]--;
      if (inc[to] == 0) q.push_back(to);
    }
  }
  for (int i = 0; i < nodes; ++i) {
    if (!vi[i]) {
      cout << "ORDER VIOLATION" << endl;
      return;
    }
  }
  cout << "ORDER EXISTS" << endl;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc = nxint();
  while (tc--)
    solve();

  return 0;
}
