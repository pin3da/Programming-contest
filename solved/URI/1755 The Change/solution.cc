#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int t; cin >> t;
  while (t--) {
    long double d, p; int n;
    cin >> d >> n;
    int dd = round(d * 100);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      cin >> p;
      int pp = round(p * 100);
      if (pp > dd) continue;
      ans = max(ans, dd % pp);
    }
    // cout << ans / 100 << "." << ans % 100 << endl;
    printf("%d.%02d\n", ans / 100, ans % 100);
  }
  return 0;
}
