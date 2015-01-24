using namespace std;
#include <bits/stdc++.h>
#define endl '\n'
#define D(x) cout << #x " = " << (x) << endl

void compute(int node, vector<vector<int> > &g, vector<int> &grundy) {
  vector<int> seen(20, 0);
  for (int i = 0; i < g[node].size(); ++i) {
    compute(g[node][i], g, grundy);
    seen[grundy[g[node][i]]] = true;
  }

  for (int i = 0; i < seen.size(); ++i) {
    if (!seen[i]) {
      grundy[node] = i;
      return;
    }
  }
}

void solve() {
  int n; cin >> n;
  vector<int> m(n);
  vector<vector<int> > g(n + 1);
  for (int i = 0; i < n; ++i) {
    cin >> m[i];
  }

  int t;
  for (int i = 0; i < n; ++i) {
    cin >> t;
    g[t].push_back(i + 1);
  }

  n++;
  vector<int> grundy(n, 0);
  compute(1, g, grundy);

  int ans = 0;
  for (int i = 1; i < n; ++i) {
    if (m[i - 1] & 1) {
      ans ^= grundy[i];
      //D(i);
      //D(grundy[i]);
    }
  }

  cout << ((ans == 0)? "second" : "first") << endl;


}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int t; cin >> t;
  for (int i = 0; i < t; ++i) {
    cout << "Case #" << i + 1 << ": ";
    solve();
  }
  return 0;
}
