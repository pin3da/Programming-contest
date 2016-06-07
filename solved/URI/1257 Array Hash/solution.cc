#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n; cin >> n;
  while (n--) {
    int l; cin >> l;
    string line;
    long long ans = 0;
    for (int i = 0; i < l; ++i) {
      cin >> line;
      for (int j = 0; j < line.size(); ++j) {
        ans += (line[j] - 'A') + j + i;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
