#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  int n; cin >> n;
  int x; cin >> x;
  vector<int> a(n);
  vector<int> seen(101);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    seen[a[i]] = 1;
  }
  int mmin = *min_element(a.begin(), a.end());
  int mmax = *max_element(a.begin(), a.end());
  if (seen[x]) {
    cout << 1 << endl;
  } else if (x >= mmin && x <= mmax) {
    cout << 2 << endl;
  } else {
    cout << -1 << endl;
  }

  return 0;
}
