#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

long long get_divs(vector<int> &a, int i, int j, int x) {
  long long hi = a[j] / x;
  return hi - ((a[i] - 1) / x);
}


int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n, x, k;
  cin >> n >> x >> k;
  vector<int> a(n);
  for (auto &i : a) cin >> i;

  long long ans = 0;
  for (int i = 0; i < (int)a.size(); i++) {
    for (int j = 0; j < n; j++) {
      if (a[i] <= a[j] && get_divs(a, i, j, x) == k) {
        ans++;
      }
    }
  }

  cout << ans << endl;


  return 0;
}
