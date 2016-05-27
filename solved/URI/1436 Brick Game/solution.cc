#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc, t = 1; cin >> tc;
  while (tc--) {
    int n; cin >> n;
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    sort(a.begin(), a.end());
    cout << "Case " << t++ << ": ";
    cout << a[n >> 1] << endl;
  }
  return 0;
}
