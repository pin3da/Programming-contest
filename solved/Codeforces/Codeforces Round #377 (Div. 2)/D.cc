#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

const int MN = 1e5 + 100;

int d[MN], a[MN];
int last[MN];
int pref[MN];
int acc[MN];
int n, m;

bool fun(int len) {
  memset(last, -1, sizeof last);
  for (int i = 0; i < len; ++i) {
    last[d[i]] = i;
  }

  vector<pair<int, int> > cur;
  for (int i = 0; i < m; ++i) {
    if (last[i + 1] == -1) return false;
    cur.push_back(make_pair(last[i + 1], i));
  }

  sort(cur.begin(), cur.end());
  for (int i = 0; i < len; ++i) acc[i] = 1;
  for (int i = 0; i < (int)cur.size(); ++i) {
    acc[cur[i].first] = -a[cur[i].second];
  }
  int t = 0;
  for (int i = 0; i < len; ++i) {
    t += acc[i];
    if (t < 0) return false;
  }
  return true;
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'
#endif
  while (cin >> n >> m) {
    for (int i = 0; i < n; ++i)
      cin >> d[i];

    for (int i = 0; i < m; ++i)
      cin >> a[i];

    int lo = 1, hi = n;
    int p = fun(hi);
    if (!p) {
      cout << - 1 << endl;
      continue;
    }
    while (lo < hi) {
      int mid = (lo + hi) >> 1;
      if (fun(mid)) {
        hi = mid;
      } else {
        lo = mid + 1;
      }
    }
    cout << lo << endl;
  }
  return 0;
}
