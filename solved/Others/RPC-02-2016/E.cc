#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<string> g(n);
  vector<vector<int>> sum(n, vector<int> (m + 1));

  for (int i = 0; i < n; ++i)
    cin >> g[i];

  int a, b, c, d;
  for (int i = 0; i < k; ++i) {
    cin >> a >> b >> c >> d;
    b = n - b;
    a = a - 1;
    c = c - 1;
    d = n - d;

    for (int i = d; i <= b; ++i) {
      sum[i][a] += 1;
      sum[i][c + 1] -= 1;
    }
  }

  int ans = 0, ans2 = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (j)
        sum[i][j] += sum[i][j - 1];
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (sum[i][j] > 0) {
        if (g[i][j] == 'B')
          ans++;
        else
          ans2++;
      }
    }
  }
  cout << ans << " " << ans2 << endl;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
