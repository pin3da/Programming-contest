using namespace std;
#include<bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  cin >> n;
  vector<int> d(n), used(3 * n, 0), seen(3 * n, 0);
  for (int i = 0; i < n; ++i) {
    cin >> d[i];
    used[d[i]] = true;
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (seen[d[i]]) {
      for (int j = d[i]; j < used.size(); ++j) {
        if (!used[j]) {
          used[j] = true;
          ans += j - d[i];
          break;
        }
      }
    }
    seen[d[i]] = true;
  }
  cout << ans << endl;
  return 0;
}
