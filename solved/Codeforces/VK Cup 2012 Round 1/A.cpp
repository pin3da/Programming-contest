// http://codeforces.com/contest/161/problem/A

using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

struct entry{
  long long x;
  int type, id;
  entry (long long a, int b, int c) : x(a), type(b), id(c) {}
  bool operator < (const entry &o) const {
    if (x == o.x) {
      return type < o.type;
    }
    return x < o.x;
  }
};

void solve(int n, int m, int x, int y) {
  vector<entry> ts;
  long long t;
  for (int i = 0; i < n; ++i) {
    cin >> t;
    ts.push_back(entry(t - x, 0, i));
    ts.push_back(entry(t + y, 2, i));
  }
  for (int i = 0; i < m; ++i) {
    cin >> t;
    ts.push_back(entry(t, 1, i));
  }
  sort(ts.begin(), ts.end());
  set<int> av;
  vector<pair<int, int>> ans;

  for (int i = 0; i < ts.size(); ++i) {
    long long cur = ts[i].x;
    int type = ts[i].type;
    if (type == 0) {
      av.insert(ts[i].id);
    } else if (type == 2) {
      av.erase(ts[i].id);
    } else {
      if (av.size()) {
        int m = *av.begin();
        ans.push_back(make_pair(ts[i].id, m));
        av.erase(av.begin());
      }
    }
  }
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); ++i) {
    cout << ans[i].second + 1 << " " << ans[i].first + 1 << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, m, x, y;
  while (cin >> n >> m >> x >> y) {
    solve(n, m, x, y);
  }
  return 0;
}
