#include <bits/stdc++.h>

#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc; cin >> tc;
  while (tc--) {
    int n; cin >> n;
    vector<int> a(n);
    int non_one = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      non_one |= a[i] != 1;
      ans ^= a[i];
    }
    if (non_one)
      puts(ans ? "First": "Second");
    else
      puts(ans ? "Second": "First");
  }
  return 0;
}
