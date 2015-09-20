using namespace std;
#include <bits/stdc++.h>
#define endl '\n'


long long f(vector<vector<int> > &g, int t) {
  long long ans = 0;
  for (int i = 0; i < g.size(); ++i) {
    vector<int>::iterator it = lower_bound(g[i].begin(), g[i].end(), t);
    int a = g[i].end() - it;
    int b = g[i].size() - a;
    ans += abs(a - b);
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n && n) {
    vector<vector<int> > g(n);
    for (int i = 0; i < n; ++i) {
      int t, k; cin >> t;
      for (int j = 0; j < t; ++j) {
        cin >> k;
        g[i].push_back(k);
      }
      sort(g[i].begin(), g[i].end());
    }

    int lo = 0, hi = 1000;
    long long best = 1LL << 60;
    for (int i = lo; i < hi; ++i) {
      best = min(f(g, i), best);
    }
    cout << best  << endl;
  }
  return 0;
}
