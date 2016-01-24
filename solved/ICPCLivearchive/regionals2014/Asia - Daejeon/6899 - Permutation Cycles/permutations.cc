#include <bits/stdc++.h>

using namespace std;

void dfs(vector<int> &to, vector<int> &col, int cur, int c) {
  if (col[cur] != -1) return;
  col[cur] = c;
  dfs(to, col, to[cur], c);
}

void solve() {
  int n;
  cin >> n;
  vector<int> to(n);
  for (auto &i : to) {
    cin >> i;
    i--;
  }

  vector<int> col(n, -1);
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (col[i] == -1) {
      dfs(to, col, i, ans);
      ans++;
    }
  }
  cout << ans << endl;

}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc; cin >> tc;
  for (int i = 0; i < tc; ++i)
    solve();
  return 0;
}
