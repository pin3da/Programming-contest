#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

long long dx[] = {0, 1118, 1680, 2018};
long long dy[] = {2018, 1680, 1118, 0};

void solve() {
  int n; cin >> n;
  set<pair<int, int>> exist;
  vector<pair<int, int>> points(n);
  for (int i = 0; i < n; i++) {
    cin >> points[i].first >> points[i].second;
    exist.insert(points[i]);
  }
  int ans = 0;
  pair<int, int> t;
  for (int i = 0; i < n; i++) {
    t = {points[i].first + dx[0], points[i].second + dy[0]}; if (exist.count(t)) ans++;
    t = {points[i].first + dx[0], points[i].second - dy[0]}; if (exist.count(t)) ans++;
    t = {points[i].first - dx[3], points[i].second + dy[3]}; if (exist.count(t)) ans++;
    t = {points[i].first + dx[3], points[i].second + dy[3]}; if (exist.count(t)) ans++;

    for (int k = 1; k < 3; k++) {
      t = {points[i].first + dx[k], points[i].second + dy[k]}; if (exist.count(t)) ans++;
      t = {points[i].first + dx[k], points[i].second - dy[k]}; if (exist.count(t)) ans++;
      t = {points[i].first - dx[k], points[i].second + dy[k]}; if (exist.count(t)) ans++;
      t = {points[i].first - dx[k], points[i].second - dy[k]}; if (exist.count(t)) ans++;
    }
  }
  cout << ans / 2 << endl;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  solve();
  return 0;
}
