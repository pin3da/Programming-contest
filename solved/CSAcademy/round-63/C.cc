#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x " = " << (x) << endl


vector<int> divisors(int g) {
  vector<int> ans;
  for (int i = 1; i * i <= g; i++) {
    if ((g % i) == 0) {
      ans.push_back(i);
      ans.push_back(g / i);
    }
  }
  sort(ans.begin(), ans.end());
  return ans;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n;
  cin >> n;

  vector<int> a(n), b(n);
  for (auto &i : a) cin >> i;
  for (auto &i : b) cin >> i;

  int g = 0, ok = true;
  for (int i = 0; i < n; i++) {
    // debug(a[i] - b[i]);
    ok &= a[i] >= b[i];
    g = __gcd(g, a[i] - b[i]);
  }

  int mmax = (*max_element(b.begin(), b.end()));
  if (ok && g == 0) {
    cout << mmax + 1 << endl;
    return 0;
  }

  if (ok && g > mmax) {
    vector<int> divs = divisors(g);
    for (auto i: divs) {
      if (i > mmax) {
        cout << i << endl;
        return 0;
      }
    }
    cout << g << endl;
    return 0;
  } else {
    cout << -1 << endl;
  }
  return 0;
}
