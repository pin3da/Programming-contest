#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

const int MAX_K = 2511;

typedef bitset<MAX_K> mask;

void solve() {
  int n, k; cin >> n >> k;
  vector<mask> sets(n);
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int len; cin >> len;
    for (int j = 0; j < len; ++j) {
      int tmp; cin >> tmp;
      sets[i].set(tmp, 1);
    }
    for (int j = 0; j < i; ++j) {
      if ((sets[i] | sets[j]).count() == (size_t)k) {
        ans++;
      }
    }
  }
  cout << ans << endl;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  int tc; cin >> tc;
  for (int i = 0; i < tc; ++i) {
    solve();
  }
  return 0;
}
