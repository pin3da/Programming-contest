#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

bool query(int b, int e) {
  cout << "? " << b << ' ' << e << endl;
  string ans; cin >> ans;
  return ans == "<";
}

pair<int, int> search(int b, int e) {
  if (b == e) {
    return make_pair(b, e);
  }

  if ((b + 1) == e) {
    pair<int, int> best;
    if (query(b, e)) {
      best.first = b;
      best.second = e;
    } else {
      best.first = e;
      best.second = b;
    }
    return best;
  }

  int mid = (b + e) >> 1;
  pair<int, int> a1 = search(b, mid);
  pair<int, int> a2 = search(mid + 1, e);
  pair<int, int> ans;
  if (query(a1.first, a2.first))  ans.first = a1.first;
  else ans.first = a2.first;

  if (query(a1.second, a2.second)) ans.second = a2.second;
  else ans.second = a1.second;
  return ans;
}

void solve() {
  int n; cin >> n;
  pair<int, int> ans = search(1, n);
  cout << "! " << ans.first << ' ' << ans.second << endl;
}

int main() {
  int t; cin >> t;

  for (int i = 0; i < t; ++i)
    solve();

  return 0;
}
