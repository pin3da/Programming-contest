#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, h; cin >> n >> h;
  int t, ans = 0;
  for (int i = 0; i < n; ++i) {
    cin >> t;
    if (t > h) ans += 2;
    else ans++;
  }
  cout << ans << endl;

  return 0;
}
