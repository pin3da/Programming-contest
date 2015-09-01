using namespace std;
#include <bits/stdc++.h>
#define endl '\n'

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n) {
    vector<long long> a(n);
    long long tot = 0;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      tot += a[i];
    }
    tot /= n;
    a[0] = 0;
    for (int i = 1; i < n; ++i)
      a[i] = a[i - 1] + tot - a[i];

    sort(a.begin(), a.end());
    long long mid = (a[n >> 1] + a[(n - 1) >> 1]) >> 1;
    long long ans = 0;
    for (int i = 0; i < n; ++i)
      ans += fabs(mid - a[i]);
    cout << ans << endl;
  }
  return 0;
}
