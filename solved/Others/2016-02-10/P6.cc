#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

typedef bitset<1001> bitmask;

bool dfs(vector<bitmask> &g, vector<int> &col, int node, int c) {
  if ((g[node] ^ g[c]).count() != 0)
    return false;

  col[node] = c;
  for (int i = 0; i < g.size(); ++i) {
    if (g[node][i] && col[i] == -1) {
      if(!dfs(g, col, i, c))
        return false;
    }
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  char t;
  cin >> n;
  vector<bitmask> g(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> t;
      if (t == 'S')
        g[i].set(j, 1);
    }
  }


  vector<int> col(n, -1);

  for (int i = 0; i < n; ++i) {
    if (col[i] == -1) {
      if (!dfs(g, col, i, i)) {
        cout << -1 << endl;
        return 0;
      }
    }
  }

  map<int, int> f;
  for (int i = 0; i < n; ++i) {
    f[col[i]]++;
  }

  vector<int> ans;
  ans.reserve(f.size());
  for (auto &i : f)
    ans.push_back(i.second);

  sort(ans.rbegin(), ans.rend());
  cout << f.size() << endl;
  for (int i = 0; i < ans.size(); ++i) {
    if (i) cout << " ";
    cout << ans[i];
  }
  cout << endl;
  return 0;
}
