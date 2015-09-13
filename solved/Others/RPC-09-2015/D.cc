#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x " = " << (x) << endl


bool same(vector<vector<string> > &g, map<string, int> &val, int i, int row) {
  set<string> not_seen;
  if (!row) {
    for (int j = 0; j < g[i].size(); ++j) {
      if (val.count(g[i][j])) continue;
      not_seen.insert(g[i][j]);
    }
  } else {
    for (int j = 0; j < g.size(); ++j) {
      if (val.count(g[j][i])) continue;
      not_seen.insert(g[j][i]);
    }
  }
  return not_seen.size() == 1;
}

int get_val(vector<vector<string> > &g, map<string, int> &val, int i, int row) {
  int ans = 0;
  if (!row) {
    for (int j = 0; j < g[i].size(); ++j) {
      if (!val.count(g[i][j])) continue;
      ans += val[g[i][j]];
    }
  } else {
    for (int j = 0; j < g.size(); ++j) {
      if (!val.count(g[j][i])) continue;
      ans += val[g[j][i]];
    }
  }
  return ans;
}

string get_cad(vector<vector<string> > &g, map<string, int> &val, int i, int row) {
  set<string> not_seen;
  if (!row) {
    for (int j = 0; j < g[i].size(); ++j) {
      if (val.count(g[i][j])) continue;
      not_seen.insert(g[i][j]);
    }
  } else {
    for (int j = 0; j < g.size(); ++j) {
      if (val.count(g[j][i])) continue;
      not_seen.insert(g[j][i]);
    }
  }
  assert(not_seen.size() == 1);
  return (*not_seen.begin());
}

int get_frec(vector<vector<string> > &g, int i, string s, int row) {
  int ans = 0;
  if (!row) {
    for (int j = 0; j < g[i].size(); ++j) {
      if (g[i][j] == s)
        ans++;
    }
  } else {
    for (int j = 0; j < g.size(); ++j) {
      if (g[j][i] == s)
        ans++;
    }
  }
  return ans;
}

int main() {
  int n, m;
  while (cin >> n >> m) {
    vector<vector<string> > g(n, vector<string>(m));
    vector<int> row(n), col(m);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> g[i][j];
      }
      cin >> row[i];
    }

    for (int i = 0; i < m; ++i)
      cin >> col[i];

    map<string, int> val;
    while (true) {
      int seen = 0;
      for (int i = 0; i < n; ++i) {
        if (same(g, val, i, 0)) {
          int cur = row[i] - get_val(g, val, i, 0);
          string s = get_cad(g, val, i, 0);
          val[s] = cur / get_frec(g, i, s, 0);
          seen = true;
        }
      }
      if (seen) continue;
      for (int i = 0; i < m; ++i) {
        if (same(g, val, i, 1)) {
          int cur = col[i] - get_val(g, val, i, 1);
          string s = get_cad(g, val, i, 1);
          val[s] = cur / get_frec(g, i, s, 1);
          seen = true;
        }
      }
      if (!seen)
        break;
    }
    for (map<string, int>::iterator it = val.begin(); it != val.end(); ++it) {
      cout << it-> first << " " << it-> second << endl;
    }
  }
  return 0;
}
