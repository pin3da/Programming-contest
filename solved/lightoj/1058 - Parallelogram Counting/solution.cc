using namespace std;
#include <bits/stdc++.h>

void solve() {
  int n;
  cin >> n;
  vector<pair<int, int> > p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i].first >> p[i].second;
  }

  vector<pair<int, int> > reachable;
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      reachable.push_back(make_pair(p[i].first + p[j].first, p[i].second + p[j].second));
    }
  }

  sort(reachable.begin(), reachable.end());
  int count = 0, ans = 0;
  for (int i = 1; i < reachable.size(); ++i) {
    if (reachable[i] == reachable[i - 1])
      count++;
    else {
      ans += count * (count + 1) / 2;
      count = 0;
    }
  }
  ans += count * (count + 1) / 2;
  printf("%d\n", ans);
}
int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
  return 0;
}
