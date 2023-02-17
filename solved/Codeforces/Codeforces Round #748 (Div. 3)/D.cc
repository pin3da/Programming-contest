#include <bits/stdc++.h>

using namespace std;

bool all_equal(const vector<int> &a) {
  for (auto i : a)
    if (i != a[0]) return false;
  return true;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    int mmin = *min_element(a.begin(), a.end());
    if (all_equal(a)) {
      cout << -1 << endl;
      continue;
    }
    for (auto &i : a) i -= mmin;
    int gcd = 0;
    for (auto i : a) gcd = __gcd(gcd, i);
    cout << gcd << endl;
  }
  return 0;
}