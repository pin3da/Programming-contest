#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl


int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc; cin >> tc;
  while (tc--) {
    vector<int> a(5);
    for (int i = 0; i < 5; ++i) {
      cin >> a[i];
    }
    int ok = true;
    for (int i = 1; i < 5; ++i) {
      ok &= a[i] == (a[i - 1] + 1);
    }
    puts(ok ? "Y": "N");
  }
  return 0;
}
