#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n; while (cin >> n && n) {
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    long long acc = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
      acc += a[i];
      ans += llabs(acc);
    }
    cout << ans << endl;
  }
  return 0;
}
