#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n; while (cin >> n && n) {
    int a, b;
    int ans[2] = {0, 0};
    while (n--) {
      cin >> a >> b;
      if (a == b) continue;
      ans[a < b]++;
    }
    cout << ans[0] << " " << ans[1] << endl;
  }
  return 0;
}
