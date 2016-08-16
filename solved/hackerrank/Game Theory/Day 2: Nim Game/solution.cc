#include <bits/stdc++.h>

#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc; cin >> tc;
  while (tc--) {
    int n; cin >> n;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      int t; cin >> t;
      ans ^= t;
    }
    puts(ans ? "First" : "Second");
  }
  return 0;
}
