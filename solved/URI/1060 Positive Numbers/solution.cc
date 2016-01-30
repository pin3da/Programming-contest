#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  double n;
  int ans = 0;
  for (int i = 100; i < 106; ++i) {
    cin >> n;
    ans += (n > 0);
  }
  cout << ans << " valores positivos" << endl;
  return 0;
}
