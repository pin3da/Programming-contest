#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n && n) {
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      int peak = 0;
      peak |= (a[i] > a[(i - 1 + n) % n]) && (a[i] > a[(i + 1) % n]);
      peak |= (a[i] < a[(i - 1 + n) % n]) && (a[i] < a[(i + 1) % n]);
      ans += peak;
    }
    cout << ans << endl;
  }
  return 0;
}
