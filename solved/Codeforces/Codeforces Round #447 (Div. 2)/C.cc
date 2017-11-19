#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n;
  cin >> n;
  set<int> s;
  vector<int> ord;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    s.insert(t);
    ord.emplace_back(t);
  }

  reverse(ord.begin(), ord.end());
  vector<int> ans;
  int ok = true;
  ans.push_back(ord[0]);

  set<int> is_gcd;
  for (int i = 1; ok && i < n; i++) {
    int carry = ord[i];
    for (int j = ans.size() - 1; j >= 0; j--) {
      carry = __gcd(carry, ans[j]);
      ok &= s.count(carry);
      if (carry < ord[i])
        is_gcd.insert(carry);
    }
    if (ok && !is_gcd.count(ord[i]))
      ans.push_back(ord[i]);
  }

  if  (!ok) {
    cout << -1 << endl;
  } else {
    cout << ans.size() << endl;
    for (auto it : ans)
      cout << it << ' ';
    cout << endl;
  }
  return 0;
}
