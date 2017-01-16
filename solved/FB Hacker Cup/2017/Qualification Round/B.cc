#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

void solve() {
  int n; cin >> n;
  deque<int> a(n);
  for (int &i : a) cin >> i;
  sort(a.begin(), a.end());
  int ans = 0;
  while (!a.empty()) {
    int cur = a.back();
    int need = (50 + cur - 1) / cur;
    need--;
    a.pop_back();
    if (need > (int)a.size()) {
      break;
    }
    while (need--) {
      a.pop_front();
    }
    ans++;
  }
  cout << ans << endl;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  int t; cin >> t;
  for (int i = 0; i < t; ++i) {
    cout << "Case #" << (i + 1) << ": ";
    solve();
  }
  return 0;
}
