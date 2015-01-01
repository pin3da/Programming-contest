using namespace std;
#include <bits/stdc++.h>

void solve() {
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  vector<int> ans;
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i];
    for (int j = 0; j < i; ++j) {
      int dist = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
      ans.push_back(dist);
    }
  }
  sort(ans.begin(), ans.end());
  printf("%d\n", 1 + distance(ans.begin(), unique(ans.begin(), ans.end())));
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
  return 0;
}
