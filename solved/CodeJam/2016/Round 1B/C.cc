#include <bits/stdc++.h>

#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'
using namespace std;


void solve() {
  int n;
  cin >> n;
  vector<pair<string, string>> d(n);
  for (auto &i : d)
    cin >> i.first >> i.second;

  sort(d.begin(), d.end());
  d.resize(unique(d.begin(), d.end()) - d.begin());

  n = d.size();
  int best = 0;
  for (int mask = 0; mask < (1 << n); ++mask) {
    int faked = 0;
    for (int i = 0; i < n; ++i) {
      if (((mask >> i) & 1) == 0) continue;
      int pf = false,
          ps = false;

      for (int j = 0; j < n; ++j) {
        if (j == i) continue;
        if (j < i) {
          pf |= d[i].first  == d[j].first;
          ps |= d[i].second == d[j].second;
        } else if (((mask >> j) & 1) == 0) {
          pf |= d[i].first  == d[j].first;
          ps |= d[i].second == d[j].second;
        }
      }
      if (pf && ps)
        faked++;
    }
    best = max(best, faked);
  }
  cout << best << endl;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    cout << "Case #" << (i + 1) << ": ";
    solve();
  }

  return 0;
}
