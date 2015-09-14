#include <bits/stdc++.h>
using namespace std;
const int MN = 110;

int n;
bool g[MN][MN];
bool dom[MN][MN];

void dfs(int s, int disabled, bool vis[]) {
  if (s == disabled)
    return;

  vis[s] = true;
  
  for (int i = 0; i < n; i++) {
    if (g[s][i] and !vis[i]) {
      dfs(i, disabled, vis);
    }
  }
  return;
}

void solve() {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> g[i][j];

  bool init[n];
  memset(init, 0, sizeof init);
  
  dfs(0, -1, init);

  bool vis[n];
  for (int i = 0; i < n; i++) {
    memset(vis, 0, sizeof vis);
    dfs(0, i, vis);

    for (int j = 0; j < n; j++) {
      if (!vis[j] and init[j])
	dom[i][j] = true;
      else
	dom[i][j] = false;
    }

    dom[i][i] = init[i];
  }

  cout << "+";
  for (int j = 0; j < n; j++)
    cout << "-" << (j + 1 == n ? "+" : "-");
  cout << endl;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << "|" << (dom[i][j] ? 'Y' : 'N');
      if (j + 1 == n)
	cout << "|" << endl;
    }
    cout << "+";
    for (int j = 0; j < n; j++)
      cout << "-" << (j + 1 == n ? "+" : "-");
    cout << endl;
  }  
}

int main() {
  int tc; cin >> tc;
  int cn = 0;

  while (tc--) {
    cin >> n;
    memset(dom, 0, sizeof dom);
    cout << "Case " << ++cn << ":" << endl;
    solve();
  }
  
  return 0;
}
