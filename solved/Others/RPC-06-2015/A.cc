using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

int dx[] = {-1, -1, 0, 0, 1, 1};
int dy[] = {0, 1, -1, 1, -1, 0};
int g[1111][1111];

void solve() {
  int c, n, t;
  cin >> c >> n;
  vector<pair<int, int>> cap(n);
  for (int i = 0; i < n; ++i) {
    cin >> cap[i].second;
    cin >> t;
    set<pair<int, int>> points;
    for (int j = 0; j < t; ++j) {
      int a, b;
      cin >> a >> b;
      points.insert(make_pair(a, b));
    }
    int window = 0;
    for (const auto &it : points) {
      int a = it.first, b = it.second;
      for (int k = 0; k < 6; ++k) {
        int x = a + dx[k];
        int y = b + dy[k];
        if (points.count(make_pair(x, y)) == 0)
          window++;
      }
    }
    cap[i].first = window;
  }

  sort(cap.rbegin(), cap.rend());

  int cur_len = 0;
  int ans = 0;
  for (int i = 0; i < cap.size(); ++i) {
    for (int j = 0; j < cap[i].second; ++j) {
      ans ++;
      cur_len += cap[i].first;
      if (ans > 1)
        cur_len -= 2;

      if (cur_len >= c) {
        cout << "Je treba " << ans << " celku." <<  endl;
        return;
      }
    }
  }
  cout << "Kapacita zakladny je pouze " << cur_len << " lidi." << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
